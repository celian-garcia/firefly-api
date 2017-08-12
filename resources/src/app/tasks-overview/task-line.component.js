"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
Object.defineProperty(exports, "__esModule", { value: true });
var core_1 = require("@angular/core");
var Task_1 = require("app/api-firefly/data/Task");
var TaskLineComponent = TaskLineComponent_1 = (function () {
    function TaskLineComponent() {
        this.states = TaskLineComponent_1.STATES;
    }
    return TaskLineComponent;
}());
// TODO : provide it as a service
TaskLineComponent.STATES = {
    '0': 'assets/images/CREATED.png',
    '1': 'assets/images/STARTED.png',
    '2': 'assets/images/PAUSED.png',
    '3': 'assets/images/FINISHED.png',
    '4': 'assets/images/ABORTED.png'
};
__decorate([
    core_1.Input(),
    __metadata("design:type", Task_1.Task)
], TaskLineComponent.prototype, "task", void 0);
__decorate([
    core_1.Input(),
    __metadata("design:type", String)
], TaskLineComponent.prototype, "view_name", void 0);
TaskLineComponent = TaskLineComponent_1 = __decorate([
    core_1.Component({
        selector: 'app-task-line',
        templateUrl: './task-line.component.html',
        styleUrls: ['./task-line.component.css']
    }),
    __metadata("design:paramtypes", [])
], TaskLineComponent);
exports.TaskLineComponent = TaskLineComponent;
var TaskLineComponent_1;
//# sourceMappingURL=task-line.component.js.map