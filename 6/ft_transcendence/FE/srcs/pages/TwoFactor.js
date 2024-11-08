import { language } from "../components/language";
import {
  PongRoomPageLanguage,
  twoFactorPageLanguage,
} from "../components/languageHtml";
import PageView from "./Pageview";
import { createTwoFA } from "../components/fetch";

class TwoFactor extends PageView {
  constructor() {
    super();
  }

  async getHtml() {
    createTwoFA();
    const html = twoFactorPageLanguage[language];
    return html;
  }
}
export default TwoFactor;
