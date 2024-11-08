
import {
  LanguageButtonHtml,
  MainTitleLanguageHtml,
  ProfileLanguageHtml,
} from "./languageHtml";
import { normalizePath } from "./utils";

export let language = sessionStorage.getItem("language") || "en";

export function changeLanguage(lang) {
  sessionStorage.setItem("language", lang);
  language = lang;
}

export const setLanguage = (lang) => {
  if (
    normalizePath(location.pathname) === "/twofactor" ||
    normalizePath(location.pathname) === "/dice/game" ||
    normalizePath(location.pathname) === "/pong/game"
  ) {
    return;
  }
  const languageButtons = document.querySelectorAll(".btn-check");
  const isLogin = sessionStorage.getItem("login");
  languageButtons.forEach((button) => {
    if (button.id === lang) {
      button.checked = true;
    } else {
      button.checked = false;
    }
  });

  const headerTitle = document.querySelector("#main-title");
  headerTitle.textContent = MainTitleLanguageHtml[lang];

  const footerProfile = document.querySelector("#profile-btn");
  footerProfile.textContent = ProfileLanguageHtml[lang];

  document.querySelectorAll("label[data-lang]").forEach((label) => {
    const langKey = label.getAttribute("for");
    label.textContent = LanguageButtonHtml[lang][langKey];
  });

  const headerLogin = document.getElementById("login");
  if (isLogin) {
    headerLogin.textContent = "42 logout";
  }
};
