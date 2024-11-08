import { checkJwt } from "./fetch";

export const isValidPlayerNames = (playerNames) => {
  if (!Array.isArray(playerNames)) {
    return false;
  }

  for (const name of playerNames) {
    const englishRegex = /^[a-zA-Z]+$/;
    if (!englishRegex.test(name)) {
      return false;
    }

    if (name.trim() === "") {
      return false;
    }
  }

  return true;
};

export const normalizePath = (path) =>
  path.endsWith("/") ? path.slice(0, -1) : path;

export const pathToRegex = (path) =>
  new RegExp("^" + path.replace(/\//g, "\\/").replace(/:\w+/g, "(.+)") + "$");

export const getParams = (match) => {
  const values = match.result.slice(1);
  const keys = Array.from(match.route.path.matchAll(/:(\w+)/g)).map(
    (result) => result[1]
  );
  return Object.fromEntries(keys.map((key, i) => [key, values[i]]));
};

export const setGameHeaderDisabled = (path) => {
  const header = document.getElementById("header");
  const footer = document.getElementById("footer");
  if (path === "/pong/game" || path === "/dice/game") {
    header.classList.add("game-disable");
    footer.classList.add("game-disable");
  } else {
    header.classList.remove("game-disable");
    footer.classList.remove("game-disable");
  }
};



export const checkLoginToken = async () => {
  const LoginButton = document.getElementById("login");
  const LogoutButton = document.getElementById("logout");
  if (sessionStorage.getItem("login")){
    LoginButton.classList.add("disabled");
    LogoutButton.classList.remove("disabled");
    LoginButton.textContent = "42 logout";
  }else {
    LoginButton.classList.remove("disabled");
    LogoutButton.classList.add("disabled");
    LoginButton.textContent = "42 login";
  }
}
