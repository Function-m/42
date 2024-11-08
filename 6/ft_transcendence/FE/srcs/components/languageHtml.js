import {
  createPlayerContainers,
  createProfileContainers,
  createStatisticsTable,
} from "./state";
import pingPongImage from "../statics/images/ping-pong.png";
import diceImage from "../statics/images/dice.png";

import diceAni from "../statics/images/dice-game.gif";
import diceDef from "../statics/images/dice_default.png";


export const mainPageLanguage = {
  ko: `
    <div id="main-container">
        <div id="pong" class="main_row game-select-button" data-link>
            <p>퐁 게임</p>
            <img id="pong-img" src="${pingPongImage}" alt="Pong Game" />
        </div>
        <div id="dice" class="main_row game-select-button" data-link>
            <img id="dice-img" src="${diceImage}" alt="Pong Game" />
            <p>주사위 게임</p>
        </div>
    </div>
  `,
  en: `
    <div id="main-container">
        <div id="pong" class="main_row game-select-button" data-link>
            <p>Pong Game</p>
            <img id="pong-img" src="${pingPongImage}" alt="Pong Game" />
        </div>
        <div id="dice" class="main_row game-select-button" data-link>
            <img id="dice-img" src="${diceImage}" alt="Pong Game" />
            <p>Dice Game</p>
        </div>
    </div>      
  `,
  jp: `
        <div id="main-container">
            <div id="pong" class="main_row game-select-button" data-link>
                <p>ポンゲーム</p>
                <img id="pong-img" src="${pingPongImage}" alt="Pong Game" />
            </div>
            <div id="dice" class="main_row game-select-button" data-link>
                <img id="dice-img" src="${diceImage}" alt="Pong Game" />
                <p>サイコロゲーム</p>
            </div>
        </div>
    `,
};

export const PongPageLanguage = {
  ko: `
      <div id="container">
          <div id="mode-select">
            <p>모드 선택</p>
            <img id="pong-img" src="${pingPongImage}" alt="Pong Game" />
          </div>
          <div id="mode-container">
            <div class="pong-mode">
                <p>느림</p>
                <div id="pong-select-container">
                    <div id="slow_two"  class="game-mode pong-select" data-link>2명의 사람</div>
                    <div id="slow_four" class="game-mode pong-select" data-link>4명의 사람</div>
                </div>
            </div>
            <div class="pong-mode">
                <p>중간</p>
                <div id="pong-select-container">
                    <div id="normal_two"  class="game-mode pong-select" data-link>2명의 사람</div>
                    <div id="normal_four" class="game-mode pong-select" data-link>4명의 사람</div>
                </div>
            </div>
            <div class="pong-mode">
                <p>극한</p>
                <div id="pong-select-container">
                    <div id="extreme_two"  class="game-mode pong-select" data-link>2명의 사람</div>
                    <div id="extreme_four" class="game-mode pong-select" data-link>4명의 사람</div>
                </div>
            </div>
          </div>
      </div>
      `,
  en: `
      <div id="container">
          <div id="mode-select">
            <p>Mode Select</p>
            <img id="pong-img" src="${pingPongImage}" alt="Pong Game" />
          </div>
          <div id="mode-container">
            <div class="pong-mode">
                <p>Slow</p>
                <div id="pong-select-container">
                    <div id="slow_two"  class="game-mode pong-select" data-link>two player</div>
                    <div id="slow_four" class="game-mode pong-select" data-link>four player</div>
                </div>
            </div>
            <div class="pong-mode">
                <p>Normal</p>
                <div id="pong-select-container">
                    <div id="normal_two"  class="game-mode pong-select" data-link>two player</div>
                    <div id="normal_four" class="game-mode pong-select" data-link>four player</div>
                </div>
            </div>
            <div class="pong-mode">
                <p>Extreme</p>
                <div id="pong-select-container">
                    <div id="extreme_two"  class="game-mode pong-select" data-link>two player</div>
                    <div id="extreme_four" class="game-mode pong-select" data-link>four player</div>
                </div>
            </div>
          </div>
      </div>
                            `,
  jp: `
      <div id="container">
          <div id="mode-select">
            <p>モード選択</p>
            <img id="pong-img" src="${pingPongImage}" alt="Pong Game" />
          </div>
          <div id="mode-container">
            <div class="pong-mode">
                <p>スロー</p>
                <div id="pong-select-container">
                    <div id="slow_two"  class="game-mode pong-select" data-link>二人用 </div>
                    <div id="slow_four" class="game-mode pong-select" data-link> 四人用</div>
                </div>
            </div>
            <div class="pong-mode">
                <p>通常</p>
                <div id="pong-select-container">
                    <div id="normal_two"  class="game-mode pong-select" data-link>二人用</div>
                    <div id="normal_four" class="game-mode pong-select" data-link>四人用</div>
                </div>
            </div>
            <div class="pong-mode">
                <p>エクストリーム</p>
                <div id="pong-select-container">
                    <div id="extreme_two"  class="game-mode pong-select" data-link>二人用</div>
                    <div id="extreme_four" class="game-mode pong-select" data-link>四人用</div>
                </div>
            </div>
          </div>
      </div>
                            `,
};

export const PongRoomPageLanguage = (id) => {
  return {
    ko: `
        <div id="container">
          <div id="mode-select">
            <p>멤버 등록</p>
            <img id="pong-img" src="${pingPongImage}" alt="Pong Game" />
          </div>
          <div id="mode-container">
            <div id="input-container">
              ${createPlayerContainers(id)}
              <div id="pong" class="game_start_button" data-link>게임 시작</div>
            </div>
          </div>
        </div>
      `,
    en: `
        <div id="container">
          <div id="mode-select">
            <p>Register Members</p>
            <img id="pong-img" src="${pingPongImage}" alt="Pong Game" />
          </div>
          <div id="mode-container">
            <div id="input-container">
              ${createPlayerContainers(id)}
              <div id="pong" class="game_start_button" data-link>game start</div>
            </div>
          </div>
        </div>      `,
    jp: `
        <div id="container">
          <div id="mode-select">
            <p>メンバー登録</p>
            <img id="pong-img" src="${pingPongImage}" alt="Pong Game" />
          </div>
          <div id="mode-container">
            <div id="input-container">
              ${createPlayerContainers(id)}
              <div id="pong" class="game_start_button" data-link>ゲームスタート</div>
            </div>
          </div>
        </div>
      `,
  };
};

export const PongGamePageLanguage = {
  ko: `
  		<div id="ponggame-container">
  			<div class="canvas-box">
	  			<canvas id="canvas"></canvas>
 			</div>
  			<h1 id="player1Score">0</h1>
  			<h1 id="player2Score">0</h1>
			<h1 id="player1Name"></h1>
 			<h1 id="player2Name"></h1>
	  		<h1 id="roundIndex"></h1>`,
  en: `
		<div id="ponggame-container">
		<div class="canvas-box">
			<canvas id="canvas"></canvas>
 		</div>
  		<h1 id="player1Score">0</h1>
  		<h1 id="player2Score">0</h1>
		<h1 id="player1Name"></h1>
		<h1 id="player2Name"></h1>
  		<h1 id="roundIndex"></h1>`,
  jp: `
  		<div id="ponggame-container">
  		<div class="canvas-box">
	  		<canvas id="canvas"></canvas>
   		</div>
		<h1 id="player1Score">0</h1>
		<h1 id="player2Score">0</h1>
 		<h1 id="player1Name"></h1>
  		<h1 id="player2Name"></h1>
		<h1 id="roundIndex"></h1>`,
};

export const DicePageLanguage = (id) => {
  return {
    ko: `
          <div id="container">
            <div id="mode-select" class="reverse-linear">
                <img id="dice-img" src="${diceImage}" alt="Pong Game" />
                <p>멤버 등록</p>
            </div> 
            <div id="mode-container">
                <div id="dice-odd" class="dice-container">
                    <p>홀수</p>
                    ${createPlayerContainers(id)}
                </div>
                <div id="dice-even" class="dice-container">
                    <p>짝수</p>
                    ${createPlayerContainers(id)}
                </div>
            </div>
            <div id="mode-container">
                <div id="dice-statistics" data-link>Statistics</div>
                <div id="dice" class="game_start_button" data-link>Game Start</div>
            <div>
        </div>
    
                        `,
    en: `
          <div id="container">
            <div id="mode-select" class="reverse-linear">
                <img id="dice-img" src="${diceImage}" alt="Pong Game" />
                <p>Register Members</p>
            </div> 
            <div id="mode-container">
                <div id="dice-odd" class="dice-container">
                    <p>Odd Number</p>
                    ${createPlayerContainers(id)}
                </div>
                <div id="dice-even" class="dice-container">
                    <p>Even Number</p>
                    ${createPlayerContainers(id)}
                </div>
            </div>
            <div id="mode-container">
                <div id="dice-statistics" data-link>Statistics</div>
                <div id="dice" class="game_start_button" data-link>Game Start</div>
            <div>
        </div>
                      `,
    jp: `
        <div id="container">
            <div id="mode-select" class="reverse-linear">
                <img id="dice-img" src="${diceImage}" alt="Pong Game" />
                <p>メンバー登録</p>
            </div> 
            <div id="mode-container">
                <div id="dice-odd" class="dice-container">
                    <p>奇数</p>
                    ${createPlayerContainers(id)}
                </div>
                <div id="dice-even" class="dice-container">
                    <p>偶数</p>
                    ${createPlayerContainers(id)}
                </div>
            </div>
            <div id="mode-container">
                <div id="dice-statistics" data-link>Statistics</div>
                <div id="dice" class="game_start_button" data-link>Game Start</div>
            <div>
        </div>
                        `,
  };
};

export const DiceGamePageLanguage = {
  ko: `
		<div id="dicegame-container">
			<img src=${diceAni} id="dice"/>
			<div id="dice-result"></div>
			<div id="button-div">
				<button id="player1Btn"></button>
				<button id="player2Btn"></button>
			</div>
			<button id="rollBtn">주사위 굴리기</button>
			<img src=${diceDef} id="dice_img"/>
		</div>`,
  en: `
  <div id="dicegame-container">
  <img src=${diceAni} id="dice"/>
  <div id="dice-result"></div>
  <div id="button-div">
	  <button id="player1Btn"></button>
	  <button id="player2Btn"></button>
  </div>
  <button id="rollBtn">Roll Dice</button>
  <img src=${diceDef} id="dice_img"/>
</div>`,
  jp: `
  <div id="dicegame-container">
  <img src=${diceAni} id="dice"/>
  <div id="dice-result"></div>
  <div id="button-div">
	  <button id="player1Btn"></button>
	  <button id="player2Btn"></button>
  </div>
  <button id="rollBtn">サイコロを振る</button>
  <img src=${diceDef} id="dice_img"/>
</div>`,
};

export const StatisticsPageLanguage = (data) => {
  return {
    ko: `
        <div id="container" class="table-container">
         ${createStatisticsTable(data)}
        </div>
                    `,
    en: `
      <div id="container" class="table-container">
         ${createStatisticsTable(data)}
        </div>
                  `,
    jp: `
      <div id="container" class="table-container">
         ${createStatisticsTable(data)}
        </div>
                    `,
  };
};

export const ProfilePageLanguage = (data) => {
  return {
    ko: `   
        <div id="container">
            <div id="profile-container">
                <div id="profile-header">Profile</div>
                <div id="profile-body">
                    ${createProfileContainers(data)}
                    <div id="profile-button-container">
                        <div id="user-del" class="profile-btn" data-link>삭제</div>
                        <div id="user-anony" class="profile-btn" data-link>익명화</div>
                    </div>
                </div>
            </div>
        </div>
        `,
    en: `        <div id="container">
            <div id="profile-container">
                <div id="profile-header">Profile</div>
                <div id="profile-body">
                    ${createProfileContainers(data)}
                    <div id="profile-button-container">
                        <div id="user-del" class="profile-btn" data-link>Delete</div>
                        <div id="user-anony" class="profile-btn" data-link>Anony</div>
                    </div>
                </div>
            </div>
        </div>`,
    jp: `        <div id="container">
            <div id="profile-container">
                <div id="profile-header">Profile</div>
                <div id="profile-body">
                    ${createProfileContainers(data)}
                    <div id="profile-button-container">
                        <div id="user-del" class="profile-btn" data-link>削除</div>
                        <div id="user-anony" class="profile-btn" data-link>匿名</div>
                    </div>
                </div>
            </div>
        </div>`,
  };
};

export const twoFactorPageLanguage = {
  ko: `
    <div id="main-container">
        <div id="mode-select">
            <p>이차 보안 검증</p>
        </div>
        <div id="twofa-container">
            <p>인증 코드</p>
            <div id="twofa-input-container">
                <input type="text" id="twofa-input" placeholder="이차인증코드" maxlength="6">
                <div id="twofa-button" data-link>입력</button>
            </div>
        </div>
    </div>
                        `,
  en: `
    <div id="main-container">
        <div id="mode-select">
            <p>Securty Authentication</p>
        </div>
        <div id="twofa-container">
            <p>authentication code</p>
            <div id="twofa-input-container">
                <input type="text" id="twofa-input" placeholder="two Factor code" maxlength="6">
                <div id="twofa-button" data-link>Enter</button>
            </div>
        </div>
    </div>
                      `,
  jp: `
    <div id="main-container">
        <div id="mode-select">
            <p>セキュリティ認証</p>
        </div>
        <div id="twofa-container">
            <p>認証コード</p>
            <div id="twofa-input-container">
                <input type="text" id="twofa-input" placeholder=" 二要素コード" maxlength="6">
                <div id="twofa-button" data-link>入力</button>
            </div>
        </div>
    </div>`,
};

export const MainTitleLanguageHtml = {
  ko: "초월",
  en: "transcendence",
  jp: "超越",
};

export const ProfileLanguageHtml = {
  ko: "프로필",
  en: "Profile",
  jp: "プロフィール",
};

export const LanguageButtonHtml = {
  ko: {
    ko: "한국어",
    en: "영어",
    jp: "일본어",
  },
  en: {
    ko: "Ko",
    en: "En",
    jp: "Jp",
  },
  jp: {
    ko: "韓国語",
    en: "英語",
    jp: "日本語",
  },
};

export const ProfileInfoHtml = {
  ko: {
    nick: "닉네임",
    name: "이름",
    email: "이메일",
  },
  en: {
    nick: "Nick",
    name: "Name",
    email: "Email",
  },
  jp: {
    nick: "ニックネーム",
    name: "名前",
    email: "メール",
  },
};

export const LoginButtonHtml = {
  ko: "42 로그인",
  en: "42 Login",
  jp: "42ログイン",
};

export const LougoutButtonHtml = {
  ko: "42 로그아웃",
  en: "42 Logout",
  jp: "42 ログアウト",
};
