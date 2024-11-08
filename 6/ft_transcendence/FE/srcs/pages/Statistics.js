import { DiceStat } from "../components/fetch";
import { language } from "../components/language";
import { StatisticsPageLanguage } from "../components/languageHtml";
import PageView from "./Pageview";

class Statistics extends PageView {
  async getHtml() {
    const data = await DiceStat();
    const html = StatisticsPageLanguage(data)[language];
    return html;
  }
}
export default Statistics;
