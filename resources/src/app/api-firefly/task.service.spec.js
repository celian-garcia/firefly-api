"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var testing_1 = require("@angular/core/testing");
var task_service_1 = require("./task.service");
describe('TaskService', function () {
    beforeEach(function () {
        testing_1.TestBed.configureTestingModule({
            providers: [task_service_1.TaskService]
        });
    });
    it('should ...', testing_1.inject([task_service_1.TaskService], function (service) {
        expect(service).toBeTruthy();
    }));
});
//# sourceMappingURL=task.service.spec.js.map