import { language } from "../components/language";
import { PongPageLanguage } from "../components/languageHtml";
import PageView from "./Pageview";

class Pong extends PageView {
  constructor() {
    super();
  }

  async getHtml() {
    const html = PongPageLanguage[language];
    return html;
  }
}
export default Pong;
