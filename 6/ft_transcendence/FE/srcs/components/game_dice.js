import dice1 from "../statics/images/dice1.png";
import dice2 from "../statics/images/dice2.png";
import dice3 from "../statics/images/dice3.png";
import dice4 from "../statics/images/dice4.png";
import dice5 from "../statics/images/dice5.png";
import dice6 from "../statics/images/dice6.png";

import { language } from "./language.js";
import { players, resetPlayers } from "./state";
import { navigateTo, router } from "./router";
import { DiceResult } from "./fetch";

function delay(ms) {
	return new Promise(resolve => setTimeout(resolve, ms));
}

export default function () {
  let player1Ready = false;
  let player2Ready = false;
  let res;

  /* playerNames[0] = even select player, playerNames[1] = odd select player */
  const playerNames = players;
  let dice;
  const img = document.getElementById("#img");
  const p1 = document.getElementById("player1Btn");
  const p2 = document.getElementById("player2Btn");
  const roll = document.getElementById("rollBtn");

  if (language == 'en'){
	  p1.innerText = playerNames[1] + " (Even)\n Ready?\n(click to ready)";
	  p2.innerText = playerNames[0] + " (Odd)\n Ready?\n(click to ready)";
  } else if (language == 'ko'){
	p1.innerText = playerNames[1] + " (짝수)\n 준비?\n(누르면 준비 완료)";
	p2.innerText = playerNames[0] + " (홀수)\n 준비?\n(누르면 준비 완료)";
} else if (language == 'jp'){
	p1.innerText = playerNames[1] + " (偶数)\n 準備はいいですか?\n(クリックして準備完了)";
	p2.innerText = playerNames[0] + " (奇数)\n 準備はいいですか?\n(クリックして準備完了)";
}

  p1.addEventListener("click", (e) => {
	if (language == 'en'){
		p1.innerText = playerNames[1] + "\n Ready!";
	} else if (language == 'ko'){
		p1.innerText = playerNames[1] + "\n 준비 완료!";
	} else if (language == 'jp'){
		p1.innerText = playerNames[1] + "\n 準備完了!";
	}
    p1.style.backgroundColor = "#D64747";
    p1.style.borderColor = "#D64747";
    player1Ready = true;
    p1.disabled = true;
  });
  p2.addEventListener("click", (e) => {
	if (language == 'en'){
		p2.innerText = playerNames[0] + "\n Ready!";
	} else if (language == 'ko'){
		p2.innerText = playerNames[0] + "\n 준비 완료!";
	} else if (language == 'jp'){
		p2.innerText = playerNames[0] + "\n 準備完了!";
	}
    p2.style.backgroundColor = "#D64747";
    p2.style.borderColor = "#D64747";
    player2Ready = true;
    p2.disabled = true;
  });
  roll.addEventListener("click", async (e) => {
    if (player1Ready == false || player2Ready == false) {
		if (language == 'en'){
			alert("Please ready before rolling!");
		} else if (language == 'ko'){
			alert("굴리기 전에 준비해주세요!");
		} else if (language == 'jp'){
			alert("転がす前に準備してください!");
		}
      return;
    }

    document.querySelector("#dice").style.display = "block";
    document.querySelector("#dice_img").style.display = "none";
	if (language == 'en'){
		roll.innerText = "Rolling..";
	} else if (language == 'ko'){
		roll.innerText = "굴리는중..";
	} else if (language == 'jp'){
		roll.innerText = "転がし中..";
	}
	roll.disabled = true;

      dice = rollDice();

      switch (dice) {
        case 1:
          window.dice_img.src = `${dice1}`;
          break;
        case 2:
          window.dice_img.src = `${dice2}`;
          break;
        case 3:
          window.dice_img.src = `${dice3}`;
          break;
        case 4:
          window.dice_img.src = `${dice4}`;
          break;
        case 5:
          window.dice_img.src = `${dice5}`;
          break;
        case 6:
          window.dice_img.src = `${dice6}`;
          break;
      }
	  await delay(2000);
	  if (!window.dice_img) return;
      window.dice_img.style.display = "block";
      window.dice.style.display = "none";
		await delay(100);
	  	if (!document.querySelector('#player1Btn')) return;
        res = dice % 2;
        if (res == 1) {
			if (language == 'en'){
				p2.innerText = playerNames[0] + " Win!!";
				p1.innerText = playerNames[1] + " Lose..";
			} else if (language == 'ko'){
				p2.innerText = playerNames[0] + " 승리!!";
				p1.innerText = playerNames[1] + " 패배..";
			} else if (language == 'jp'){
				p2.innerText = playerNames[0] + "しょうり!!";
				p1.innerText = playerNames[1] + "はいぼく..";
			}
          p2.style.backgroundColor = "#70bb70";
          p2.style.borderColor = "#70bb70";
          p1.style.backgroundColor = "#ff9999";
          p1.style.borderColor = "#ff9999";
        } else {
			if (language == 'en'){
				p1.innerText = playerNames[1] + " Win!!";
				p2.innerText = playerNames[0] + " Lose..";
			} else if (language == 'ko'){
				p1.innerText = playerNames[1] + " 승리!!";
				p2.innerText = playerNames[0] + " 패배..";
			} else if (language == 'jp'){
				p1.innerText = playerNames[1] + "しょうり!!";
				p2.innerText = playerNames[0] + "はいぼく..";
			}
          p1.style.backgroundColor = "#70bb70";
          p1.style.borderColor = "#70bb70";
          p2.style.backgroundColor = "#ff9999";
          p2.style.borderColor = "#ff9999";
        }
		await delay(100);
          if (res == 1) {
			if (language == 'en'){
				alert("Odd Number Win!!");
				alert("Congratulation! " + playerNames[0] + "~~");
			} else if (language == 'ko'){
				alert("홀수 승리!!");
				alert("축하합니다! " + playerNames[0] + "~~");
			} else if (language == 'jp'){
				alert("奇数勝利!!");
				alert("おめでとうございます! " + playerNames[0] + "~~");
			}
          } else {
			if (language == 'en'){
				alert("Even Number Win!!");
				alert("Congratulation! " + playerNames[1] + "~~");
			} else if (language == 'ko'){
				alert("짝수 승리!!");
				alert("축하합니다! " + playerNames[1] + "~~");
			} else if (language == 'jp'){
				alert("偶数勝利!!");
				alert("おめでとうございます! " + playerNames[1] + "~~");
			}
          }
          let data = {
            type: res,
          };
          DiceResult(data);
		  resetPlayers();
          navigateTo("/main");
  });

  function rollDice() {
    return Math.floor(Math.random() * 6) + 1;
  }
}
