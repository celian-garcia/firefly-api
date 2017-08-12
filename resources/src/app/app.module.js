"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
Object.defineProperty(exports, "__esModule", { value: true });
var platform_browser_1 = require("@angular/platform-browser");
var core_1 = require("@angular/core");
var forms_1 = require("@angular/forms");
var http_1 = require("@angular/http");
var bootstrap_1 = require("angular2-modal/plugins/bootstrap");
var angular2_modal_1 = require("angular2-modal");
var app_component_1 = require("./app.component");
var tasks_overview_module_1 = require("./tasks-overview/tasks-overview.module");
var toolbar_module_1 = require("app/toolbar/toolbar.module");
var app_task_view_module_1 = require("./app-task-view/app-task-view.module");
var AppModule = (function () {
    function AppModule() {
    }
    return AppModule;
}());
AppModule = __decorate([
    core_1.NgModule({
        declarations: [
            app_component_1.AppComponent
        ],
        imports: [
            platform_browser_1.BrowserModule,
            forms_1.FormsModule,
            http_1.HttpModule,
            tasks_overview_module_1.TasksOverviewModule,
            toolbar_module_1.ToolbarModule,
            angular2_modal_1.ModalModule.forRoot(),
            bootstrap_1.BootstrapModalModule,
            app_task_view_module_1.AppTaskViewModule
        ],
        bootstrap: [app_component_1.AppComponent]
    })
], AppModule);
exports.AppModule = AppModule;
//# sourceMappingURL=app.module.js.map