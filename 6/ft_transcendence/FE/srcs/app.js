import { navigateTo, router } from "./components/router";
import { resetPlayers } from "./components/state";

document.addEventListener("DOMContentLoaded", () => {
  document.body.addEventListener("click", (e) => {
    if (e.target.matches("[data-link]")) {
      e.preventDefault();
    }
  });
	const path = window.location.pathname;

  if (path === "/dice" 
    || path === "/pong" 
    || path === "/profile"
    || path === "/statistics"
    || path === "/pong/room/2"
    || path === "/pong/room/4") {
      navigateTo();
    } else {
    router();
    }
});

window.addEventListener("popstate", () => {
  resetPlayers();
  router();
});
 
