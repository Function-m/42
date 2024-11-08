import { ProfileGetData } from "../components/fetch";
import { language } from "../components/language";
import { ProfilePageLanguage } from "../components/languageHtml";
import PageView from "./Pageview";

class Profile extends PageView {
  constructor() {
    super();
  }

  async getHtml() {
    let data = await ProfileGetData();
    const html = ProfilePageLanguage(data)[language];
    return html;
  }
}
export default Profile;
