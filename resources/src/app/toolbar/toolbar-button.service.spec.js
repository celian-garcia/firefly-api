"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var testing_1 = require("@angular/core/testing");
var toolbar_button_service_1 = require("./toolbar-button.service");
describe('ToolbarButtonService', function () {
    beforeEach(function () {
        testing_1.TestBed.configureTestingModule({
            providers: [toolbar_button_service_1.ToolbarButtonService]
        });
    });
    it('should ...', testing_1.inject([toolbar_button_service_1.ToolbarButtonService], function (service) {
        expect(service).toBeTruthy();
    }));
});
//# sourceMappingURL=toolbar-button.service.spec.js.map