import { language } from "../components/language";
import { PongRoomPageLanguage } from "../components/languageHtml";
import PageView from "./Pageview";

class PongRoom extends PageView {
  constructor(params) {
    super();
    this.id = params.id;
  }

  async getHtml() {
    const html = PongRoomPageLanguage(this.id)[language];
    return html;
  }
}
export default PongRoom;
