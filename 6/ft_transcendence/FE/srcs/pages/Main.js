import { handleOAuthRedirect } from "../components/fetch";
import { language } from "../components/language";
import { mainPageLanguage } from "../components/languageHtml";

import PageView from "./Pageview";

class Main extends PageView {
  constructor() {
    super();
  }

  async getHtml() {
    const html = mainPageLanguage[language];
    handleOAuthRedirect();

    return html;
  }
}
export default Main;
