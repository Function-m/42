import { language } from "../components/language";
import { PongGamePageLanguage } from "../components/languageHtml";
import { pongGameMode } from "../components/state";
import PageView from "./Pageview";

class PongGame extends PageView {
  constructor() {
    super();
  }

  async getHtml() {
    const html = PongGamePageLanguage[language];
    return html;
  }
}
export default PongGame;
