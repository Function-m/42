import { language } from "../components/language";
import { DiceGamePageLanguage } from "../components/languageHtml";
import PageView from "./Pageview";

class DiceGame extends PageView {
  constructor() {
    super();
  }

  async getHtml() {
    const html = DiceGamePageLanguage[language];
    return html;
  }
}
export default DiceGame;
