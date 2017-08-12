"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
Object.defineProperty(exports, "__esModule", { value: true });
var core_1 = require("@angular/core");
var common_1 = require("@angular/common");
var api_firefly_module_1 = require("app/api-firefly/api-firefly.module");
var tasks_overview_component_1 = require("./tasks-overview.component");
var esm_1 = require("angular2-modal/esm");
var bootstrap_1 = require("angular2-modal/plugins/bootstrap");
var task_line_component_1 = require("./task-line.component");
var utils_module_1 = require("../utils/utils.module");
var task_modal_component_1 = require("./task-modal.component");
var forms_1 = require("@angular/forms");
var TasksOverviewModule = (function () {
    function TasksOverviewModule() {
    }
    return TasksOverviewModule;
}());
TasksOverviewModule = __decorate([
    core_1.NgModule({
        imports: [
            common_1.CommonModule,
            api_firefly_module_1.ApiFireflyModule,
            esm_1.ModalModule,
            bootstrap_1.BootstrapModalModule,
            utils_module_1.UtilsModule,
            forms_1.FormsModule
        ],
        declarations: [tasks_overview_component_1.TasksOverviewComponent, task_line_component_1.TaskLineComponent, task_modal_component_1.TaskModalComponent],
        exports: [tasks_overview_component_1.TasksOverviewComponent],
        entryComponents: [task_modal_component_1.TaskModalComponent]
    })
], TasksOverviewModule);
exports.TasksOverviewModule = TasksOverviewModule;
//# sourceMappingURL=tasks-overview.module.js.map