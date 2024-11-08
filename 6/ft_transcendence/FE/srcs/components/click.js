import { navigateTo, router } from "./router";
import { players, pongGameMode, setPongGameMode, resetPlayers } from "./state";
import { isValidPlayerNames, normalizePath } from "./utils";
import { ProfileAnony as ProfileAnony, ProfileDelete, setLogIn, verifyTwoFA } from "./fetch";
import { changeLanguage } from "./language";

export const clickMainTitle = () => {
  navigateTo("/main");
};

export const clickProfilePage = () => {
  navigateTo("/profile");
};

export const clickGameStart = (id) => {
  resetPlayers();
  const playerNameInputs = document.querySelectorAll(".player_name");
  playerNameInputs.forEach((input, index) => {
    players[index] = input.value;
  });
  if (isValidPlayerNames(players) === false) {
	alert("Please insert English only, not blank");
    return;
  }

  if (id === "pong") navigateTo("/pong/game");
  else if (id === "dice") navigateTo("/dice/game");
};

export function clickPongMode(id) {
  const [mode, players] = id.split("_");
  let navigateToUrl;

  if (mode == "") {
    switch (players) {
      case "two":
        navigateToUrl = "/dice/room/2";
        break;
      case "four":
        navigateToUrl = "/dice/room/4";
        break;
      default:
        console.error("Invalid players value:", players);
        return;
    }
  } else {
    switch (players) {
      case "two":
        navigateToUrl = "/pong/room/2";
        break;
      case "four":
        navigateToUrl = "/pong/room/4";
        break;
      default:
        console.error("Invalid players value:", players);
        return;
    }
  }
  setPongGameMode(mode);
  navigateTo(navigateToUrl);
}

export function clickGameMode(id) {
  if (id === "pong") navigateTo("/pong");
  else if (id === "dice") navigateTo("/dice");
}

export function onClickLoginButton() {
  setLogIn();
}

export const clickChangeLanguage = (id) => {
  if (
    normalizePath(location.pathname) === "/twofactor" ||
    normalizePath(location.pathname) === "/dice/game" ||
    normalizePath(location.pathname) === "/pong/game"
  ) {
    return;
  }

  const languageButtons = document.querySelectorAll(".btn-check");
  changeLanguage(id);

  languageButtons.forEach((button) => {
    if (button.id === id) {
      button.checked = true;
    } else {
      button.checked = false;
    }
  });
  router();
};

export const onClickStatistics = () => {
  navigateTo("/statistics");
};

export const onClickTwoFA = () => {
  verifyTwoFA();
};

export async function clickProfileButton(id) {
  if ("user-del" === id) {
    const isDeleted = await ProfileDelete();
    alert("user has been deleted");
    navigateTo("/main");
  } else if ("user-anony" === id) {
    const isAnony = await ProfileAnony();
    if (isAnony) {
      router("/profile");
    } else {
      navigateTo("/main");
    }
  }
}
