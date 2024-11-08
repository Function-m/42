import { language } from "./language";
import { ProfileInfoHtml } from "./languageHtml";

export let players = [];

export function resetPlayers() {
  players = [];
}

export let pongGameMode = "";

export function setPongGameMode(mode) {
  pongGameMode = mode;
}

export function resetPongGameMode() {
  pongGameMode = "";
}

export const OAUTH_REDIRECT_URL =
  process.env.FORTYTWO_AUTHORIZE_URL +
  "?client_id=" +
  process.env.OAUTH_CLIENT_ID +
  "&redirect_uri=" +
  process.env.FORTYTWO_REDIRECT_URI +
  "&response_type=code";

export const createPlayerContainers = (count) => {
  const playerOrders = {
    ko: ["첫번째", "두번째", "세번째", "네번째"],
    en: ["First", "Second", "Third", "Fourth"],
    jp: ["一番目", "二番目", "三番目", "四番目"],
  };

  const playerLabels = {
    ko: "플레이어",
    en: "Player",
    jp: "プレイヤー",
  };

  let containers = "";
  for (let i = 1; i <= count; i++) {
    const playerOrder = playerOrders[language]?.[i - 1] || `${i}th`;
    const playerLabel = playerLabels[language] || "Player";
    containers += `
      <div id="player${i}" class="player_container">
        <p>${playerOrder} ${playerLabel}</p>
        <input type="text" class="player_name" maxlength="5"/>
      </div>
    `;
  }
  return containers;
};

export const createStatisticsTable = (data) => {
  const formattedData = [
    {
      name: "Odd",
      win: data.odd.odd_win,
      lose: data.odd.odd_lose,
    },
    {
      name: "Even",
      win: data.even.even_win,
      lose: data.even.even_lose,
    },
  ];

  let table = `
    <table id="table">
      <tr class="table-row">
        <th class="table-head">${data.nick}</th>
        <th class="table-head">Win</th>
        <th class="table-head">Lose</th>
        </tr>
        `;

  formattedData.forEach((player) => {
    table += `
      <tr class="table-row">
        <td class="table-data">${player.name}</td>
        <td class="table-data">${player.win}</td>
        <td class="table-data">${player.lose}</td>
        </tr>
        `;
  });

  table += "</table>";
  return table;
};

export const createProfileContainers = (data) => {
  const labels = ProfileInfoHtml[language];

  let containers = "";
  containers += `
    <div id="profile_info">
      <p>${labels.nick}: ${data.nick}</p>
      <p>${labels.name}: ${data.name}</p>
      <p>${labels.email}: ${data.email}</p>
    </div>
  `;
  return containers;
};
