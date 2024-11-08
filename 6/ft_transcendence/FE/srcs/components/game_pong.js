import { players, pongGameMode, resetPlayers } from "./state";
import { navigateTo, router } from "./router";
import * as THREE from './three.module.js';
import { FlakesTexture } from './FlakesTexture.js';
import { RGBELoader } from './RGBELoader.js';
import { language } from "./language.js";

function delay(ms) {
	return new Promise(resolve => setTimeout(resolve, ms));
}

export default function() {
const canvas = document.getElementById("canvas");
		const ctx = canvas.getContext('2d');

		canvas.width = window.innerWidth * 0.8;
		canvas.height = window.innerHeight * 0.6;

		const keysPressed = [];
		const KEY_UP = 38;
		const KEY_DOWN = 40;
		const KEY_W = 87;
		const KEY_S = 83;
		const PAD_LEFT = 0;
		const PAD_RIGHT = 1;

		const numPlayer = players.length;
		let ballSpeed;
		switch(pongGameMode){
			case "slow":
				ballSpeed = 1;
				break;
			case "normal":
				ballSpeed = 1.5;
				break;
			case "extreme":
				ballSpeed = 2;
				break;
			default:
				navigateTo("/pong");
				alert("mode not select");
				return;
		}

		const playerNames = players;
		const roundIndex = ["1st round", "2nd round", "Final round"];
		const roundIndex_ko = ["첫 번째 경기", "두 번째 경기", "마지막 경기"];
		const roundIndex_en = ["1st round", "2nd round", "Final round"];
		const roundIndex_jp = ["第1ラウンド", "第2ラウンド", "最終ラウンド"];

		let round = 0;
		const winnerNames = [];

		let scene3, camera, renderer, pointlight, ballMesh;
		
		const ballImg = new Image();

		function init() {
			scene3 = new THREE.Scene();
	
			renderer = new THREE.WebGLRenderer({alpha:true, antialias:true});
			renderer.setSize(window.innerWidth, window.innerHeight);
			renderer.domElement.setAttribute("style", "z-index:30;");
			document.querySelector("#ponggame-container").appendChild(renderer.domElement);

			renderer.outputEncoding = THREE.sRGBEncoding;
			renderer.toneMapping = THREE.ACESFilmicToneMapping;
			renderer.toneMappingExposure = 1.25;
	
			camera = new THREE.PerspectiveCamera(50, window.innerWidth / window.innerHeight, 1, 1000);
			camera.position.set(0, 0, 400);
	
			pointlight = new THREE.DirectionalLight(0xffffff, 3);
			pointlight.position.set(200, 200, 200);
			scene3.add(pointlight);

			const ambientLight = new THREE.AmbientLight(0xffffff, 0.7); // 색상과 밝기를 설정
			scene3.add(ambientLight);
			
			let envmaploader = new THREE.PMREMGenerator(renderer);
	
				let texture = new THREE.CanvasTexture(new FlakesTexture());
				texture.wrapS = THREE.RepeatWrapping;
				texture.wrapT = THREE.RepeatWrapping;
				texture.repeat.x = 10;
				texture.repeat.y = 6;
	
				const ballMaterial = {
					clearcoat: 1.0,
					clearcoatRoughness: 0.1,
					metalness: 0.9,
					roughness: 0.5,
					color: 0xFF8c00,
					normalMap: texture,
					normalScale: new THREE.Vector2(0.15, 0.15),
				};	
	
				let ballGeo = new THREE.SphereGeometry(3, 64, 64);
				let ballMat = new THREE.MeshPhysicalMaterial(ballMaterial);
				ballMesh = new THREE.Mesh(ballGeo, ballMat);
				scene3.add(ballMesh);
			
				animate();
		}
	
		function animate() {
				renderer.render(scene3, camera);
				
				ballImg.src = renderer.domElement.toDataURL();
	
				renderer.clear();
		};

		window.addEventListener('keydown', function (e) {
			keysPressed[e.keyCode] = true;
		});
		
		window.addEventListener('keyup', function (e) {
			keysPressed[e.keyCode] = false;
		});

		function vec2(x, y) {
			return {x: x, y: y};
		}

		function Ball(pos, velocity, radius) {
			this.pos = pos;
			this.velocity = velocity;
			this.radius = radius;

			this.update = function() {
				this.pos.x += this.velocity.x;
				this.pos.y += this.velocity.y;
			};

			this.draw = function() {
				ctx.drawImage(ballImg, pos.x - ballImg.width / 2, pos.y - ballImg.height / 2);
			};
		}

		function Paddle(pos, velocity, width, height, upkey, downkey) {
			this.pos = pos;
			this.velocity = velocity;
			this.width = width;
			this.height = height;
			this.score = 0;

			this.update = function() {
				if (keysPressed[upkey] && pos.y > 0) {
					this.pos.y -= this.velocity.y;
				}
				
				if (keysPressed[downkey] && pos.y < canvas.height - height) {
					this.pos.y += this.velocity.y;
				}
			};

			this.draw = function() {
				ctx.fillStyle = "#4f2d2d";
				ctx.fillRect(this.pos.x, this.pos.y, this.width, this.height);
			};

			this.getHalfWidth = function() {
				return this.width / 2;
			};

			this.getHalfHeight = function() {
				return this.height / 2;
			};

			this.getCenter = function() {
				return vec2(
					this.pos.x + this.getHalfWidth(),
					this.pos.y + this.getHalfHeight()
				);
			};
		}

		function ballCollisionWithTheEdge(ball) {
			if (ball.pos.y + ball.radius >= canvas.height || ball.pos.y - ball.radius <= 0) {
				ball.velocity.y *= -1;
			}
		};

		function ballPaddleCollision(ball, paddle, role) {
			let dx = Math.abs(ball.pos.x - paddle.getCenter().x);
			let dy = Math.abs(ball.pos.y - paddle.getCenter().y);

			if (dx <= (ball.radius + paddle.getHalfWidth()) && dy <= (paddle.getHalfHeight() + ball.radius)) {
				if ((role == PAD_LEFT && ball.velocity.x < 0) || (role == PAD_RIGHT && ball.velocity.x > 0)) {
					ball.velocity.x *= -1;
				}
			}
		}

		function respawnBall(ball) {
			ball.pos.x = canvas.width / 2;
			ball.pos.y = (Math.random() * (canvas.height - 200)) + 100;

			ball.velocity.x *= -1;
			ball.velocity.y *= -1;
		}

		function increaseScore(ball, paddle1, paddle2) {
			if (ball.pos.x <= -ball.radius) {
				paddle2.score += 1;
				respawnBall(ball);
			}

			if (ball.pos.x >= canvas.width + ball.radius) {
				paddle1.score += 1;
				respawnBall(ball);
			}
		}


		const ball = new Ball(vec2(canvas.width / 2, canvas.height / 2), vec2((canvas.width * 0.01 + canvas.height * 0.01) / 2 * ballSpeed, (canvas.width * 0.005 + canvas.height * 0.005) / 2 * ballSpeed), 5); //(canvas.width * 0.005 + canvas.height * 0.005) / 2);
		const paddle1 = new Paddle(vec2(canvas.width * 0.0, canvas.height * 0.4), vec2(1.5 * (canvas.width * 0.01 + canvas.height * 0.01) / 2 * ballSpeed, 1.5 * (canvas.width * 0.005 + canvas.height * 0.005) / 2 * ballSpeed), canvas.width * 0.02, canvas.height * 0.2, KEY_W, KEY_S);
		const paddle2 = new Paddle(vec2(canvas.width - canvas.width * 0.02, canvas.height * 0.4), vec2(1.5 * (canvas.width * 0.01 + canvas.height * 0.01) / 2 * ballSpeed, 1.5 * (canvas.width * 0.005 + canvas.height * 0.005) / 2 * ballSpeed), canvas.width * 0.02, canvas.height * 0.2, KEY_UP, KEY_DOWN);

		function gameUpdate() {
			ball.update();
			paddle1.update();
			paddle2.update();
			ballCollisionWithTheEdge(ball);

			ballPaddleCollision(ball, paddle1, PAD_LEFT);
			ballPaddleCollision(ball, paddle2, PAD_RIGHT);

			increaseScore(ball, paddle1, paddle2);
		}

		function gameDraw() {
			const tempWidth = canvas.width * 0.01;
			const tempHeight = canvas.height * 0.02;

			ctx.strokeStyle = "#FFFFFF";
			ctx.moveTo(canvas.width / 2, 0);
			ctx.lineTo(canvas.width / 2, canvas.height);
			ctx.lineWidth = tempWidth;
			ctx.stroke();
			
			ctx.moveTo(tempWidth * 0.5, 0);
			ctx.lineTo(tempWidth * 0.5, canvas.height);
			ctx.lineWidth = tempWidth;
			ctx.stroke();
			
			ctx.moveTo(canvas.width - tempWidth * 0.5, 0);
			ctx.lineTo(canvas.width - tempWidth * 0.5, canvas.height);
			ctx.lineWidth = tempWidth;
			ctx.stroke();
			
			ctx.moveTo(0, tempHeight * 0.5);
			ctx.lineTo(canvas.width, tempHeight * 0.5);
			ctx.lineWidth = tempHeight;
			ctx.stroke();

			ctx.moveTo(0, canvas.height - tempHeight * 0.5);
			ctx.lineTo(canvas.width, canvas.height - tempHeight * 0.5);
			ctx.lineWidth = tempHeight;
			ctx.stroke();
			
			ball.draw();
			paddle1.draw();
			paddle2.draw();
		}

	
	function resetGame() {
			keysPressed[KEY_S] = false;
			keysPressed[KEY_W] = false;
			keysPressed[KEY_DOWN] = false;
			keysPressed[KEY_UP] = false;
			
			paddle1.score = 0;
			paddle2.score = 0;
			paddle1.pos.x = canvas.width * 0.0;
			paddle1.pos.y = canvas.height * 0.4;
			paddle2.pos.x = canvas.width - canvas.width * 0.02;
			paddle2.pos.y = canvas.height * 0.4;
			document.getElementById("player1Score").innerHTML = paddle1.score;
			document.getElementById("player2Score").innerHTML = paddle2.score;
			if (numPlayer == 4){
				if (round == 0){
					document.getElementById("player1Name").innerHTML = playerNames[0];
					document.getElementById("player2Name").innerHTML = playerNames[1];
				} else if (round == 1){
					document.getElementById("player1Name").innerHTML = playerNames[2];
					document.getElementById("player2Name").innerHTML = playerNames[3];
				} else if (round == 2){
					document.getElementById("player1Name").innerHTML = winnerNames[0];
					document.getElementById("player2Name").innerHTML = winnerNames[1];
				}
			} else {
				round = 2;
				document.getElementById("player1Name").innerHTML = playerNames[0];
				document.getElementById("player2Name").innerHTML = playerNames[1];
			}

			switch(language){
				case 'ko':
					document.getElementById("roundIndex").innerHTML = roundIndex_ko[round];
					break;
				case 'en':
					document.getElementById("roundIndex").innerHTML = roundIndex_en[round];
					break;
				case 'jp':
					document.getElementById("roundIndex").innerHTML = roundIndex_jp[round];
					break;
			}
	
			alert("[" +  document.getElementById("roundIndex").innerHTML + "]" + " " + document.getElementById("player1Name").innerHTML + " vs " + document.getElementById("player2Name").innerHTML);

			document.getElementById("player1Name").style.display = 'block';
			document.getElementById("player2Name").style.display = 'block';
			player1Score.style.display = 'block';
			player2Score.style.display = 'block';
			canvas.style.display = 'block';
			window.roundIndex.style.display = 'block';
			gameLoop();
		}

		async function gameLoop() {
			ctx.clearRect(0, 0, canvas.width, canvas.height);
			ctx.beginPath();
			gameUpdate();
			gameDraw();

			if (!document.getElementById("player1Score")) return;
			document.getElementById("player1Score").innerHTML = paddle1.score;
			document.getElementById("player2Score").innerHTML = paddle2.score;
		
			if(paddle1.score < 5 && paddle2.score < 5){
				window.requestAnimationFrame(gameLoop);
			} else {
				document.getElementById("player1Name").style.display = 'none';
				document.getElementById("player2Name").style.display = 'none';
				player1Score.style.display = 'none';
				player2Score.style.display = 'none';
				canvas.style.display = 'none';
				window.roundIndex.style.display = 'none';
				await(delay(10));
				if (!document.getElementById('player2Score')) return;
					if (round == 2){
						if (paddle1.score == 5){
							if (language == 'en'){
								alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player1Name").innerHTML + " win!");
								alert("Congratulation! " + document.getElementById("player1Name").innerHTML);
							} else if (language == 'ko'){
								alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player1Name").innerHTML + " 승리!");
								alert("축하합니다! " + document.getElementById("player1Name").innerHTML);
							} else if (language == 'jp'){
								alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player1Name").innerHTML + "が勝った!");
								alert("おめでとうございます! " + document.getElementById("player1Name").innerHTML);
							}
						} else{
							if (language == 'en'){
								alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player2Name").innerHTML + " win!");
								alert("Congratulation! " + document.getElementById("player2Name").innerHTML);
							} else if (language == 'ko'){
								alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player2Name").innerHTML + " 승리!");
								alert("축하합니다! " + document.getElementById("player2Name").innerHTML);
							} else if (language == 'jp'){
								alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player2Name").innerHTML + "が勝った!");
								alert("おめでとうございます! " + document.getElementById("player2Name").innerHTML);
							}
						}
						resetPlayers();
						navigateTo("/main");
						return ;
					}
					ctx.clearRect(0, 0, canvas.width, canvas.height);
					if (paddle1.score == 5){
						winnerNames[round] = document.getElementById("player1Name").innerHTML;
						if (language == 'en'){
							alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player1Name").innerHTML + " win!");
						} else if (language == 'ko'){
							alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player1Name").innerHTML + " 승리!");
						} else if (language == 'jp'){
							alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player1Name").innerHTML + " が勝った!");
						}
					} else {
						winnerNames[round] = document.getElementById("player2Name").innerHTML;
						if (language == 'en'){
							alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player2Name").innerHTML + " win!");
						} else if (language == 'ko'){
							alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player2Name").innerHTML + " 승리!");
						} else if (language == 'jp'){
							alert(document.getElementById("roundIndex").innerHTML + ": " + document.getElementById("player2Name").innerHTML + " が勝った!");
						}
					}
					round++;
					resetGame();
			}
		}
		init();
		resetGame();
	}