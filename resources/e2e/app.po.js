"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var protractor_1 = require("protractor");
var FireflyFrontPage = (function () {
    function FireflyFrontPage() {
    }
    FireflyFrontPage.prototype.navigateTo = function () {
        return protractor_1.browser.get('/');
    };
    FireflyFrontPage.prototype.getParagraphText = function () {
        return protractor_1.element(protractor_1.by.css('app-root h1')).getText();
    };
    return FireflyFrontPage;
}());
exports.FireflyFrontPage = FireflyFrontPage;
//# sourceMappingURL=app.po.js.map