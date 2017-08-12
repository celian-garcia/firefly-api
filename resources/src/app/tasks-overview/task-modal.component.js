"use strict";
var __extends = (this && this.__extends) || (function () {
    var extendStatics = Object.setPrototypeOf ||
        ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
        function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
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
var angular2_modal_1 = require("angular2-modal");
var bootstrap_1 = require("angular2-modal/plugins/bootstrap");
var Task_1 = require("app/api-firefly/data/Task");
var task_service_1 = require("../api-firefly/task.service");
var module_service_1 = require("app/api-firefly/module.service");
var TaskModalContext = (function (_super) {
    __extends(TaskModalContext, _super);
    function TaskModalContext() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return TaskModalContext;
}(bootstrap_1.BSModalContext));
exports.TaskModalContext = TaskModalContext;
var TaskModalComponent = TaskModalComponent_1 = (function () {
    function TaskModalComponent(dialog, taskService, moduleService) {
        this.dialog = dialog;
        this.taskService = taskService;
        this.moduleService = moduleService;
        this.context = dialog.context;
        this.task = new Task_1.Task();
        this.task.name = 'Default title';
        this.task.description = 'Default description';
        dialog.setCloseGuard(this);
    }
    TaskModalComponent.controlTaskBeforeCreate = function (task) {
        return true;
    };
    TaskModalComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.moduleService.getModules().subscribe(function (data) {
            _this.modules_list = data;
            _this.task.module = _this.modules_list[0].id;
            _this.task.type = _this.modules_list[0].processing_types[0].id;
        }, function (error) { return _this.errorMessage = error; });
    };
    TaskModalComponent.prototype.getTypesFromModule = function (id) {
        return this.modules_list.find(function (elt) { return elt.id === id; }).processing_types;
    };
    TaskModalComponent.prototype.onCancel = function () {
        this.dialog.close();
    };
    TaskModalComponent.prototype.onCreateTask = function () {
        var _this = this;
        if (!TaskModalComponent_1.controlTaskBeforeCreate(this.task)) {
            return;
        }
        this.taskService.createTask(this.task).subscribe(function (task) {
            _this.task = task;
            _this.dialog.close(_this.task);
        }, function (error) {
            _this.errorMessage = error;
            _this.dialog.dismiss();
        });
    };
    TaskModalComponent.prototype.beforeDismiss = function () {
        return false;
    };
    TaskModalComponent.prototype.beforeClose = function () {
        return false;
    };
    return TaskModalComponent;
}());
TaskModalComponent = TaskModalComponent_1 = __decorate([
    core_1.Component({
        selector: 'app-task-modal',
        providers: [task_service_1.TaskService, module_service_1.ModuleService],
        styleUrls: ['./task-modal.component.css'],
        templateUrl: './task-modal.component.html'
    }),
    __metadata("design:paramtypes", [angular2_modal_1.DialogRef, task_service_1.TaskService, module_service_1.ModuleService])
], TaskModalComponent);
exports.TaskModalComponent = TaskModalComponent;
var TaskModalComponent_1;
//# sourceMappingURL=task-modal.component.js.map