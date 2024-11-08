import { language } from "../components/language";
import {
  DiceRoomPageLanguage,
  PongRoomPageLanguage,
} from "../components/languageHtml";
import PageView from "./Pageview";

class DiceRoom extends PageView {
  constructor(params) {
    super();
    this.id = params.id;
  }

  async getHtml() {
    const html = DiceRoomPageLanguage(this.id)[language];
    return html;
  }
}
export default DiceRoom;
