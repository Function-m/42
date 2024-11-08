import { navigateTo } from "../components/router";
import { OAUTH_REDIRECT_URL } from "./state";

export async function checkJwt() {
  const response = await fetch(process.env.USER_VERIFY_URL, {
    method: "GET",
    headers: {
      "Content-Type": "application/json",
      Authorization: `${sessionStorage.getItem("jwt")}`,
    },
  });
  if (response.ok) {
    return true;
  } else {
    return false;
  }
}

export function verifyTwoFA() {
  const twoFAValue = document.getElementById("twofa-input")?.value ?? null;
  fetch(process.env.TWO_FA_VERIFY_URL, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "Authorization": `${sessionStorage.getItem("jwt")}`,
    },
    body: JSON.stringify(twoFAValue),
  })
    .then((res) => {
      if (res.ok){
        res.json().then((data) => {
          if (sessionStorage.getItem("jwt")) {
            sessionStorage.removeItem("jwt");
          }
          sessionStorage.setItem("jwt", data.jwt);
          sessionStorage.setItem("login", true);
          navigateTo("/main");
        })
      }
      else {
        console.log("verify fail");
      }})
}

export function createTwoFA() {
  const jwt = { jwt: sessionStorage.getItem("jwt") };
  if (!jwt.jwt) {
    alert("There is no token.");
    navigateTo("/main");
    return;
  }
  fetch(process.env.TWO_FA_CREATE_URL, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      credentials: 'include',
      Authorization: `${sessionStorage.getItem("jwt")}`,
    },
  })
    .then((res) => {
      if (res.ok) {
      } else {
        console.log("FAIL create twoFA", res);
      }
    })
    .catch((error) => {
      console.log("error", error);
    });
}

export function setLogIn() {
  window.location.href = OAUTH_REDIRECT_URL;
}

export function setLogOut() {
  sessionStorage.removeItem("jwt");
  sessionStorage.removeItem("login");
  alert("logout");
  navigateTo("/main");
}

export function handleOAuthRedirect() {
  const url = window.location.href;
  if (!url.includes("code=")) return;
  const accessToken = url.split("code=")[1];

  fetch("https://127.0.0.1/login/", {
    method: "POST",
    headers: { "Content-Type": "application/json", credentials: 'include'},
    body: JSON.stringify({
      code: accessToken,
    }),
  }).then((res) => {
    if (res.ok) {
      res.json().then((data) => {
        sessionStorage.setItem("jwt", data.jwt);
        if (data.jwt) {
          navigateTo("/twofactor");
        } else {
          navigateTo("/main");
        }
      });
    } else {
      alert("Login failed.");
      navigateTo("/main");
    }
  });
}

export async function DiceStat() {
  try {
    const response = await fetch(process.env.DICE_STAT_URL, {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        Authorization: `${sessionStorage.getItem("jwt")}`,
      },
    });
    if (response.ok) {
      return await response.json();
    } else {
      console.log("fail dice stat");
      throw new Error("Failed to fetch dice stat");
    }
  } catch (error) {
    console.error("Error in DiceStat:", error);
    throw error;
  }
}

export function DiceResult(data) {
  fetch(process.env.DICE_RESULT_URL, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      Authorization: `${sessionStorage.getItem("jwt")}`,
    },
    body: JSON.stringify({
      data: data,
    }),
  })
    .then((res) => {
      if (!res.ok) {
		  console.log("dice result fail");
      }
    })
    .catch((error) => {});
}

export async function ProfileDelete() {
  try {
    const res = await fetch(process.env.USER_INFO_DEL_URL, {
      method: "DELETE",
      headers: {
        "Content-Type": "application/json",
        Authorization: `${sessionStorage.getItem("jwt")}`,
      },
    });
    if (res.ok) {
      sessionStorage.removeItem("jwt");
      sessionStorage.removeItem("login");
      return true;
    } else {
      console.log("profile delete fail");
      return false;
    }
  } catch (error) {
    console.log("error", error);
    return false;
  }
}

export async function ProfileAnony() {
  try {
    const res = await fetch(process.env.USER_INFO_ANONY_URL, {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        Authorization: `${sessionStorage.getItem("jwt")}`,
      },
    });
    if (res.ok) {
      return true;
    } else {
      console.log("profile anony fail");
      return false;
    }
  } catch (error) {
    console.log("error", error);
    return false;
  }
}

export const ProfileGetData = async () => {
	try {
    const response = await fetch(process.env.USER_INFO_URL, {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        Authorization: `${sessionStorage.getItem("jwt")}`,
      },
    });
    if (response.ok) {
      return response.json();
    } else {
      throw new Error("Failed to fetch user info");
    }
  } catch (error) {
    console.log("Error in ProfileGetData:", error);
    throw error;
  }
};
