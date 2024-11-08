import PageView from "./Pageview";

class NotFoundPage extends PageView {
  constructor() {
    super();
    this.disableHeaderFooter();
  }

  disableHeaderFooter() {
    const header = document.getElementById("header");
    const footer = document.getElementById("footer");
    header.classList.add("disabled");
    footer.classList.add("disabled");
  }

  async getHtml() {
    return `
      <div class="error-container">
        <div>
          <p class="neonText">404</p>
          <p class="neonText">Not Found</p>
        </div>
      </div>
    `;
  }
}

export default NotFoundPage;
