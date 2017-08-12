"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var testing_1 = require("@angular/core/testing");
var module_service_1 = require("./module.service");
describe('ModuleService', function () {
    beforeEach(function () {
        testing_1.TestBed.configureTestingModule({
            providers: [module_service_1.ModuleService]
        });
    });
    it('should ...', testing_1.inject([module_service_1.ModuleService], function (service) {
        expect(service).toBeTruthy();
    }));
});
//# sourceMappingURL=module.service.spec.js.map