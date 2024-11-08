import Dice from "../pages/Dice";
import DiceGame from "../pages/DiceGame";
import DiceRoom from "../pages/DiceRoom";
import Main from "../pages/Main";
import NotFoundPage from "../pages/NotFountPage";
import Pong from "../pages/Pong";
import PongGame from "../pages/PongGame";
import PongRoom from "../pages/PongRoom";
import Statistics from "../pages/Statistics";
import TwoFactor from "../pages/TwoFactor";
import {
  clickMainTitle,
  clickGameStart,
  clickPongMode,
  onClickLoginButton,
  clickGameMode,
  clickChangeLanguage,
  onClickStatistics,
  onClickTwoFA,
  clickProfileButton,
  clickProfilePage,
} from "./click";
import { players } from "./state";
import resetGame from "./game_pong";
import jj_diceGame from "./game_dice";
import { checkJwt, setLogOut } from "./fetch";
import Profile from "../pages/Profile";
import {
  getParams,
  normalizePath,
  pathToRegex,
  setGameHeaderDisabled,
  checkLoginToken,
} from "./utils";
import { language, setLanguage } from "./language";

export const router = async () => {
  
  if (location.pathname === '/' || location.pathname === '') {
    location.pathname = '/main';
  }

  await checkLoginToken();
  const $routes = [
    { path: "/404", view: NotFoundPage },
    { path: "/main", view: Main },
    { path: "/pong", view: Pong },
    { path: "/pong/room/:id", view: PongRoom },
    { path: "/pong/game", view: PongGame },
    { path: "/dice", view: Dice },
    { path: "/dice/room/:id", view: DiceRoom },
    { path: "/dice/game", view: DiceGame },
    { path: "/twofactor", view: TwoFactor },
    { path: "/statistics", view: Statistics },
    { path: "/profile", view: Profile },
  ];

  const $potentialMatches = $routes.map((route) => {
    return {
      route,
      result: normalizePath(location.pathname).match(pathToRegex(route.path)),
    };
  });

  let match = $potentialMatches.find(
    (potentialMatch) => potentialMatch.result !== null
  );

  if (!match) {
    match = {
      route: $routes[0],
      result: [location.pathname],
    };
  }

  const params = getParams(match);
  if (window.location.pathname === "/dice/room/2" 
      || window.location.pathname === "/dice/room/4"
      || (params.id && params.id !== "2" && params.id !== "4")) {
    match = {
      route: $routes[0],
      result: [location.pathname],
    };
  }
  setGameHeaderDisabled(match.route.path);
  if (
    players.length === 0 &&
    (match.route.path === "/pong/game" || match.route.path === "/dice/game")
  ) {
    if (match.route.path === "/pong/game") navigateTo("/pong");
    else navigateTo("/dice");
  } else {
    const $view = new match.route.view(params);

    setLanguage(language);
    document.querySelector("#app").innerHTML = await $view.getHtml();

    buttons();
    if (document.querySelector("#ponggame-container")) {
      resetGame();
    }
    if (document.querySelector("#dicegame-container")) {
      jj_diceGame();
    }
  }
};

export async function navigateTo(url) {
  const $appElement = document.getElementById("app");
  if (url === "/twofactor" || url === "/main") {
    $appElement.innerHTML = "";
    history.pushState(null, null, url);
  } else {
    const isJwt = await checkJwt();
    if (isJwt) {
      $appElement.innerHTML = "";
      history.pushState(null, null, url);
    } else {
      $appElement.innerHTML = "";
      sessionStorage.removeItem("login");
      history.pushState(null, null, "/main");
      alert("not login user.");
    }
  }
  router();
}

export async function buttons() {
  const buttonList = [
    {
      class: "game-select-button",
      event: "click",
      handler: (id) => clickGameMode(id),
    },
    {
      class: "btn-check",
      event: "click",
      handler: (id) => clickChangeLanguage(id),
    },
    {
      class: "game-mode",
      event: "click",
      handler: (id) => clickPongMode(id),
    },
    {
      class: "game_start_button",
      event: "click",
      handler: (id) => clickGameStart(id),
    },
    {
      id: "main-title",
      event: "click",
      handler: () => clickMainTitle(),
    },
    {
      class: "login_button",
      event: "click",
      handler: () => onClickLoginButton(),
    },
    {
      id: "dice-statistics",
      event: "click",
      handler: () => onClickStatistics(),
    },
    {
      id: "twofa-button",
      event: "click",
      handler: () => onClickTwoFA(),
    },
    {
      class: "profile-btn",
      event: "click",
      handler: (id) => clickProfileButton(id),
    },
    {
      class: "logout_button",
      event: "click",
      handler: () => setLogOut(),
    },
    {
      id: "profile-btn",
      event: "click",
      handler: (id) => clickProfilePage(id),
    },
  ];

  buttonList.forEach((button) => {
    let elements = [];

    if (button.id) {
      const idElement = document.getElementById(button.id);
      if (idElement) elements.push(idElement);
    }

    if (button.class) {
      const classElements = document.getElementsByClassName(button.class);
      elements = elements.concat(Array.from(classElements));
    }

    elements.forEach((element) => {
      if (!element.hasAttribute("data-event-added")) {
        element.addEventListener(button.event, () =>
          button.handler(button.id || element.id)
        );
        element.setAttribute("data-event-added", "true");
      }
    });
  });
}
