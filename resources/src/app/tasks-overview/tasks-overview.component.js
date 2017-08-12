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
var task_service_1 = require("../api-firefly/task.service");
var modal_1 = require("angular2-modal/plugins/bootstrap/modal");
var angular2_modal_1 = require("angular2-modal");
var task_modal_component_1 = require("./task-modal.component");
var bootstrap_1 = require("angular2-modal/plugins/bootstrap");
var module_service_1 = require("../api-firefly/module.service");
var toolbar_button_service_1 = require("app/toolbar/toolbar-button.service");
var util_1 = require("util");
var TasksOverviewComponent = TasksOverviewComponent_1 = (function () {
    function TasksOverviewComponent(vcRef, modal, taskService, _toolbarButtonService) {
        this.modal = modal;
        this.taskService = taskService;
        this._toolbarButtonService = _toolbarButtonService;
        this.clickTask = new core_1.EventEmitter();
        this.modal.overlay.defaultViewContainer = vcRef;
    }
    TasksOverviewComponent.prototype.ngOnInit = function () {
        var _this = this;
        this._toolbarButtonService.subscribeCreateTask(function (_) { return _this._openCreationModal(); });
        this._toolbarButtonService.subscribeToggleView(function (view_id) { return _this._setView(view_id); });
        this.refreshTasksList();
    };
    TasksOverviewComponent.prototype.refreshTasksList = function () {
        var _this = this;
        this.taskService.getTasks()
            .subscribe(function (tasks) { return _this.tasks = tasks; }, function (error) { return _this.error_message = error; });
    };
    TasksOverviewComponent.prototype._setView = function (view_id) {
        console.log('Received toggle view event');
        this.view_name = TasksOverviewComponent_1.VIEWS_MAP[view_id];
    };
    TasksOverviewComponent.prototype._openCreationModal = function () {
        var _this = this;
        console.log('Received task creation event');
        this.modal.open(task_modal_component_1.TaskModalComponent, angular2_modal_1.overlayConfigFactory({ num1: 2, num2: 3 }, bootstrap_1.BSModalContext))
            .then(function (dialog) {
            dialog.result.then(function (result) {
                if (!util_1.isNullOrUndefined(result)) {
                    _this.tasks.push(result);
                }
            }).catch(function (err) {
                alert(err);
            });
        });
    };
    TasksOverviewComponent.prototype.onClick = function (task) {
        console.log("Sent task :");
        console.log(task);
        this.clickTask.next(task);
    };
    return TasksOverviewComponent;
}());
TasksOverviewComponent.VIEWS_MAP = {
    0: 'line',
    1: 'card'
};
__decorate([
    core_1.Output(),
    __metadata("design:type", core_1.EventEmitter)
], TasksOverviewComponent.prototype, "clickTask", void 0);
TasksOverviewComponent = TasksOverviewComponent_1 = __decorate([
    core_1.Component({
        selector: 'app-tasks-overview',
        providers: [task_service_1.TaskService, module_service_1.ModuleService],
        templateUrl: './tasks-overview.component.html',
        styleUrls: ['./tasks-overview.component.css']
    }),
    __metadata("design:paramtypes", [core_1.ViewContainerRef, modal_1.Modal, task_service_1.TaskService,
        toolbar_button_service_1.ToolbarButtonService])
], TasksOverviewComponent);
exports.TasksOverviewComponent = TasksOverviewComponent;
var TasksOverviewComponent_1;
//# sourceMappingURL=tasks-overview.component.js.map