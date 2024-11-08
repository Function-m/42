import { language } from "../components/language";
import { DicePageLanguage } from "../components/languageHtml";
import PageView from "./Pageview";

class Dice extends PageView {
  constructor() {
    super();
  }

  async getHtml() {
    const html = DicePageLanguage(1)[language];

    return html;
  }
}
export default Dice;
