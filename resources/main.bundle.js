webpackJsonp([0,2],{

/***/ 119:
/***/ (function(module, exports) {

function webpackEmptyContext(req) {
	throw new Error("Cannot find module '" + req + "'.");
}
webpackEmptyContext.keys = function() { return []; };
webpackEmptyContext.resolve = webpackEmptyContext;
module.exports = webpackEmptyContext;
webpackEmptyContext.id = 119;


/***/ }),

/***/ 120:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
Object.defineProperty(__webpack_exports__, "__esModule", { value: true });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__polyfills__ = __webpack_require__(135);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__angular_platform_browser_dynamic__ = __webpack_require__(122);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__app_app_module__ = __webpack_require__(127);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4__environments_environment__ = __webpack_require__(134);





if (__WEBPACK_IMPORTED_MODULE_4__environments_environment__["a" /* environment */].production) {
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_1__angular_core__["a" /* enableProdMode */])();
}
__webpack_require__.i(__WEBPACK_IMPORTED_MODULE_2__angular_platform_browser_dynamic__["a" /* platformBrowserDynamic */])().bootstrapModule(__WEBPACK_IMPORTED_MODULE_3__app_app_module__["a" /* AppModule */]);
//# sourceMappingURL=main.js.map

/***/ }),

/***/ 123:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_common__ = __webpack_require__(11);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return ApiFireflyModule; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};


var ApiFireflyModule = (function () {
    function ApiFireflyModule() {
    }
    return ApiFireflyModule;
}());
ApiFireflyModule = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["b" /* NgModule */])({
        imports: [
            __WEBPACK_IMPORTED_MODULE_1__angular_common__["a" /* CommonModule */]
        ],
        declarations: []
    })
], ApiFireflyModule);

//# sourceMappingURL=api-firefly.module.js.map

/***/ }),

/***/ 124:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_protractor_built_taskScheduler__ = __webpack_require__(222);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_protractor_built_taskScheduler___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_1_protractor_built_taskScheduler__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_babylonjs__ = __webpack_require__(149);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_babylonjs___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_2_babylonjs__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return AppTaskViewComponent; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var AppTaskViewComponent = AppTaskViewComponent_1 = (function () {
    function AppTaskViewComponent() {
        this.states = AppTaskViewComponent_1.STATES;
        this.babylonIsRunning = false;
    }
    AppTaskViewComponent.createScene = function (engine, canvas) {
        // Now create a basic Babylon Scene object
        var scene = new __WEBPACK_IMPORTED_MODULE_2_babylonjs__["Scene"](engine);
        // Change the scene background color to green.
        scene.clearColor = new __WEBPACK_IMPORTED_MODULE_2_babylonjs__["Color3"](0, 1, 0);
        // This creates and positions a free camera
        var camera = new __WEBPACK_IMPORTED_MODULE_2_babylonjs__["ArcRotateCamera"]('ArcRotateCamera', 1, 0.8, 10, new __WEBPACK_IMPORTED_MODULE_2_babylonjs__["Vector3"](0, 0, 0), scene);
        // This targets the camera to scene origin
        camera.setTarget(__WEBPACK_IMPORTED_MODULE_2_babylonjs__["Vector3"].Zero());
        // This attaches the camera to the canvas
        camera.attachControl(canvas, false);
        // This creates a light, aiming 0,1,0 - to the sky.
        var light = new __WEBPACK_IMPORTED_MODULE_2_babylonjs__["HemisphericLight"]('light1', new __WEBPACK_IMPORTED_MODULE_2_babylonjs__["Vector3"](0, 1, 0), scene);
        // Dim the light a small amount
        light.intensity = .5;
        // Let's try our built-in 'sphere' shape. Params: name, subdivisions, size, scene
        var sphere = __WEBPACK_IMPORTED_MODULE_2_babylonjs__["Mesh"].CreateSphere('sphere1', 16, 2, scene);
        // Move the sphere upward 1/2 its height
        sphere.position.y = 1;
        // Let's try our built-in 'ground' shape.  Params: name, width, depth, subdivisions, scene
        var ground = __WEBPACK_IMPORTED_MODULE_2_babylonjs__["Mesh"].CreateGround('ground1', 6, 6, 2, scene);
        // Leave this function
        return scene;
    };
    AppTaskViewComponent.prototype.ngAfterViewChecked = function () {
        if (this.task !== undefined && this.task !== null && !this.babylonIsRunning) {
            var canvas = document.getElementById('babylon-canvas');
            if (canvas !== null) {
                this.babylonIsRunning = true;
                this.babylonInitialization(canvas);
            }
        }
    };
    AppTaskViewComponent.prototype.babylonInitialization = function (canvas) {
        var engine = new __WEBPACK_IMPORTED_MODULE_2_babylonjs__["Engine"](canvas, true);
        // create a basic BJS Scene object
        var scene = AppTaskViewComponent_1.createScene(engine, canvas);
        engine.runRenderLoop(function () {
            scene.render();
        });
    };
    return AppTaskViewComponent;
}());
// TODO : provide it as a service
AppTaskViewComponent.STATES = {
    '0': 'assets/images/CREATED.png',
    '1': 'assets/images/STARTED.png',
    '2': 'assets/images/PAUSED.png',
    '3': 'assets/images/FINISHED.png',
    '4': 'assets/images/ABORTED.png'
};
__decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["c" /* Input */])(),
    __metadata("design:type", typeof (_a = typeof __WEBPACK_IMPORTED_MODULE_1_protractor_built_taskScheduler__["Task"] !== "undefined" && __WEBPACK_IMPORTED_MODULE_1_protractor_built_taskScheduler__["Task"]) === "function" && _a || Object)
], AppTaskViewComponent.prototype, "task", void 0);
AppTaskViewComponent = AppTaskViewComponent_1 = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["d" /* Component */])({
        selector: 'app-task-view',
        template: __webpack_require__(223),
        styles: [__webpack_require__(208)]
    }),
    __metadata("design:paramtypes", [])
], AppTaskViewComponent);

var AppTaskViewComponent_1, _a;
//# sourceMappingURL=app-task-view.component.js.map

/***/ }),

/***/ 125:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_common__ = __webpack_require__(11);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__app_task_view_component__ = __webpack_require__(124);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__utils_utils_module__ = __webpack_require__(78);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return AppTaskViewModule; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};




var AppTaskViewModule = (function () {
    function AppTaskViewModule() {
    }
    return AppTaskViewModule;
}());
AppTaskViewModule = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["b" /* NgModule */])({
        imports: [
            __WEBPACK_IMPORTED_MODULE_1__angular_common__["a" /* CommonModule */],
            __WEBPACK_IMPORTED_MODULE_3__utils_utils_module__["a" /* UtilsModule */]
        ],
        declarations: [__WEBPACK_IMPORTED_MODULE_2__app_task_view_component__["a" /* AppTaskViewComponent */]],
        exports: [__WEBPACK_IMPORTED_MODULE_2__app_task_view_component__["a" /* AppTaskViewComponent */]]
    })
], AppTaskViewModule);

//# sourceMappingURL=app-task-view.module.js.map

/***/ }),

/***/ 126:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__toolbar_toolbar_button_service__ = __webpack_require__(42);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return AppComponent; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var AppComponent = (function () {
    function AppComponent() {
    }
    AppComponent.prototype.ngOnInit = function () {
        this.taskSelected = false;
    };
    AppComponent.prototype.updateTask = function (event) {
        this.taskSelected = true;
        this.task = event;
    };
    return AppComponent;
}());
AppComponent = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["d" /* Component */])({
        selector: 'app-root',
        template: __webpack_require__(224),
        styles: [__webpack_require__(209)],
        encapsulation: __WEBPACK_IMPORTED_MODULE_0__angular_core__["E" /* ViewEncapsulation */].None,
        providers: [__WEBPACK_IMPORTED_MODULE_1__toolbar_toolbar_button_service__["a" /* ToolbarButtonService */]]
    }),
    __metadata("design:paramtypes", [])
], AppComponent);

//# sourceMappingURL=app.component.js.map

/***/ }),

/***/ 127:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_platform_browser__ = __webpack_require__(23);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__angular_forms__ = __webpack_require__(73);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__angular_http__ = __webpack_require__(41);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4_angular2_modal_plugins_bootstrap__ = __webpack_require__(31);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_angular2_modal__ = __webpack_require__(5);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_6__app_component__ = __webpack_require__(126);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_7__tasks_overview_tasks_overview_module__ = __webpack_require__(130);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_8_app_toolbar_toolbar_module__ = __webpack_require__(132);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_9__app_task_view_app_task_view_module__ = __webpack_require__(125);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return AppModule; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};










var AppModule = (function () {
    function AppModule() {
    }
    return AppModule;
}());
AppModule = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_1__angular_core__["b" /* NgModule */])({
        declarations: [
            __WEBPACK_IMPORTED_MODULE_6__app_component__["a" /* AppComponent */]
        ],
        imports: [
            __WEBPACK_IMPORTED_MODULE_0__angular_platform_browser__["a" /* BrowserModule */],
            __WEBPACK_IMPORTED_MODULE_2__angular_forms__["a" /* FormsModule */],
            __WEBPACK_IMPORTED_MODULE_3__angular_http__["a" /* HttpModule */],
            __WEBPACK_IMPORTED_MODULE_7__tasks_overview_tasks_overview_module__["a" /* TasksOverviewModule */],
            __WEBPACK_IMPORTED_MODULE_8_app_toolbar_toolbar_module__["a" /* ToolbarModule */],
            __WEBPACK_IMPORTED_MODULE_5_angular2_modal__["a" /* ModalModule */].forRoot(),
            __WEBPACK_IMPORTED_MODULE_4_angular2_modal_plugins_bootstrap__["a" /* BootstrapModalModule */],
            __WEBPACK_IMPORTED_MODULE_9__app_task_view_app_task_view_module__["a" /* AppTaskViewModule */]
        ],
        bootstrap: [__WEBPACK_IMPORTED_MODULE_6__app_component__["a" /* AppComponent */]]
    })
], AppModule);

//# sourceMappingURL=app.module.js.map

/***/ }),

/***/ 128:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_app_api_firefly_data_Task__ = __webpack_require__(74);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return TaskLineComponent; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


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
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["c" /* Input */])(),
    __metadata("design:type", typeof (_a = typeof __WEBPACK_IMPORTED_MODULE_1_app_api_firefly_data_Task__["a" /* Task */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_1_app_api_firefly_data_Task__["a" /* Task */]) === "function" && _a || Object)
], TaskLineComponent.prototype, "task", void 0);
__decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["c" /* Input */])(),
    __metadata("design:type", String)
], TaskLineComponent.prototype, "view_name", void 0);
TaskLineComponent = TaskLineComponent_1 = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["d" /* Component */])({
        selector: 'app-task-line',
        template: __webpack_require__(225),
        styles: [__webpack_require__(210)]
    }),
    __metadata("design:paramtypes", [])
], TaskLineComponent);

var TaskLineComponent_1, _a;
//# sourceMappingURL=task-line.component.js.map

/***/ }),

/***/ 129:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__api_firefly_task_service__ = __webpack_require__(76);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_angular2_modal_plugins_bootstrap_modal__ = __webpack_require__(51);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3_angular2_modal__ = __webpack_require__(5);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4__task_modal_component__ = __webpack_require__(77);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_angular2_modal_plugins_bootstrap__ = __webpack_require__(31);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_6__api_firefly_module_service__ = __webpack_require__(75);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_7_app_toolbar_toolbar_button_service__ = __webpack_require__(42);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_8_util__ = __webpack_require__(40);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_8_util___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_8_util__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return TasksOverviewComponent; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};









var TasksOverviewComponent = TasksOverviewComponent_1 = (function () {
    function TasksOverviewComponent(vcRef, modal, taskService, _toolbarButtonService) {
        this.modal = modal;
        this.taskService = taskService;
        this._toolbarButtonService = _toolbarButtonService;
        this.clickTask = new __WEBPACK_IMPORTED_MODULE_0__angular_core__["g" /* EventEmitter */]();
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
        this.modal.open(__WEBPACK_IMPORTED_MODULE_4__task_modal_component__["a" /* TaskModalComponent */], __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_3_angular2_modal__["n" /* overlayConfigFactory */])({ num1: 2, num2: 3 }, __WEBPACK_IMPORTED_MODULE_5_angular2_modal_plugins_bootstrap__["b" /* BSModalContext */]))
            .then(function (dialog) {
            dialog.result.then(function (result) {
                if (!__webpack_require__.i(__WEBPACK_IMPORTED_MODULE_8_util__["isNullOrUndefined"])(result)) {
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
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["J" /* Output */])(),
    __metadata("design:type", typeof (_a = typeof __WEBPACK_IMPORTED_MODULE_0__angular_core__["g" /* EventEmitter */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_0__angular_core__["g" /* EventEmitter */]) === "function" && _a || Object)
], TasksOverviewComponent.prototype, "clickTask", void 0);
TasksOverviewComponent = TasksOverviewComponent_1 = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["d" /* Component */])({
        selector: 'app-tasks-overview',
        providers: [__WEBPACK_IMPORTED_MODULE_1__api_firefly_task_service__["a" /* TaskService */], __WEBPACK_IMPORTED_MODULE_6__api_firefly_module_service__["a" /* ModuleService */]],
        template: __webpack_require__(227),
        styles: [__webpack_require__(212)]
    }),
    __metadata("design:paramtypes", [typeof (_b = typeof __WEBPACK_IMPORTED_MODULE_0__angular_core__["u" /* ViewContainerRef */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_0__angular_core__["u" /* ViewContainerRef */]) === "function" && _b || Object, typeof (_c = typeof __WEBPACK_IMPORTED_MODULE_2_angular2_modal_plugins_bootstrap_modal__["a" /* Modal */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_2_angular2_modal_plugins_bootstrap_modal__["a" /* Modal */]) === "function" && _c || Object, typeof (_d = typeof __WEBPACK_IMPORTED_MODULE_1__api_firefly_task_service__["a" /* TaskService */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_1__api_firefly_task_service__["a" /* TaskService */]) === "function" && _d || Object, typeof (_e = typeof __WEBPACK_IMPORTED_MODULE_7_app_toolbar_toolbar_button_service__["a" /* ToolbarButtonService */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_7_app_toolbar_toolbar_button_service__["a" /* ToolbarButtonService */]) === "function" && _e || Object])
], TasksOverviewComponent);

var TasksOverviewComponent_1, _a, _b, _c, _d, _e;
//# sourceMappingURL=tasks-overview.component.js.map

/***/ }),

/***/ 130:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_common__ = __webpack_require__(11);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_app_api_firefly_api_firefly_module__ = __webpack_require__(123);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__tasks_overview_component__ = __webpack_require__(129);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4_angular2_modal_esm__ = __webpack_require__(5);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_angular2_modal_plugins_bootstrap__ = __webpack_require__(31);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_6__task_line_component__ = __webpack_require__(128);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_7__utils_utils_module__ = __webpack_require__(78);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_8__task_modal_component__ = __webpack_require__(77);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_9__angular_forms__ = __webpack_require__(73);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return TasksOverviewModule; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};










var TasksOverviewModule = (function () {
    function TasksOverviewModule() {
    }
    return TasksOverviewModule;
}());
TasksOverviewModule = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["b" /* NgModule */])({
        imports: [
            __WEBPACK_IMPORTED_MODULE_1__angular_common__["a" /* CommonModule */],
            __WEBPACK_IMPORTED_MODULE_2_app_api_firefly_api_firefly_module__["a" /* ApiFireflyModule */],
            __WEBPACK_IMPORTED_MODULE_4_angular2_modal_esm__["a" /* ModalModule */],
            __WEBPACK_IMPORTED_MODULE_5_angular2_modal_plugins_bootstrap__["a" /* BootstrapModalModule */],
            __WEBPACK_IMPORTED_MODULE_7__utils_utils_module__["a" /* UtilsModule */],
            __WEBPACK_IMPORTED_MODULE_9__angular_forms__["a" /* FormsModule */]
        ],
        declarations: [__WEBPACK_IMPORTED_MODULE_3__tasks_overview_component__["a" /* TasksOverviewComponent */], __WEBPACK_IMPORTED_MODULE_6__task_line_component__["a" /* TaskLineComponent */], __WEBPACK_IMPORTED_MODULE_8__task_modal_component__["a" /* TaskModalComponent */]],
        exports: [__WEBPACK_IMPORTED_MODULE_3__tasks_overview_component__["a" /* TasksOverviewComponent */]],
        entryComponents: [__WEBPACK_IMPORTED_MODULE_8__task_modal_component__["a" /* TaskModalComponent */]]
    })
], TasksOverviewModule);

//# sourceMappingURL=tasks-overview.module.js.map

/***/ }),

/***/ 131:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__toolbar_button_service__ = __webpack_require__(42);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return ToolbarComponent; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var ToolbarComponent = (function () {
    function ToolbarComponent(_buttonService) {
        this._buttonService = _buttonService;
        this.fullTitleImagePath = 'assets/images/firefly_title.png';
    }
    ToolbarComponent.prototype.onClickCreateTask = function () {
        this._buttonService.createTask();
    };
    ToolbarComponent.prototype.onClickToggleView = function () {
        this._buttonService.toggleView();
    };
    return ToolbarComponent;
}());
ToolbarComponent = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["d" /* Component */])({
        selector: 'app-toolbar',
        template: __webpack_require__(228),
        styles: [__webpack_require__(213)]
    }),
    __metadata("design:paramtypes", [typeof (_a = typeof __WEBPACK_IMPORTED_MODULE_1__toolbar_button_service__["a" /* ToolbarButtonService */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_1__toolbar_button_service__["a" /* ToolbarButtonService */]) === "function" && _a || Object])
], ToolbarComponent);

var _a;
//# sourceMappingURL=toolbar.component.js.map

/***/ }),

/***/ 132:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_common__ = __webpack_require__(11);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_app_toolbar_toolbar_component__ = __webpack_require__(131);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return ToolbarModule; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};



var ToolbarModule = (function () {
    function ToolbarModule() {
    }
    return ToolbarModule;
}());
ToolbarModule = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["b" /* NgModule */])({
        imports: [
            __WEBPACK_IMPORTED_MODULE_1__angular_common__["a" /* CommonModule */]
        ],
        declarations: [__WEBPACK_IMPORTED_MODULE_2_app_toolbar_toolbar_component__["a" /* ToolbarComponent */]],
        exports: [__WEBPACK_IMPORTED_MODULE_2_app_toolbar_toolbar_component__["a" /* ToolbarComponent */]]
    })
], ToolbarModule);

//# sourceMappingURL=toolbar.module.js.map

/***/ }),

/***/ 133:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return CapitalizePipe; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};

var CapitalizePipe = (function () {
    function CapitalizePipe() {
    }
    CapitalizePipe.prototype.transform = function (value) {
        if (value) {
            return value.charAt(0).toUpperCase() + value.slice(1);
        }
        return value;
    };
    return CapitalizePipe;
}());
CapitalizePipe = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["e" /* Pipe */])({
        name: 'capitalize'
    })
], CapitalizePipe);

//# sourceMappingURL=capitalize.pipe.js.map

/***/ }),

/***/ 134:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return environment; });
// The file contents for the current environment will overwrite these during build.
// The build system defaults to the dev environment which uses `environment.ts`, but if you do
// `ng build --env=prod` then `environment.prod.ts` will be used instead.
// The list of which env maps to which file can be found in `.angular-cli.json`.
// The file contents for the current environment will overwrite these during build.
var environment = {
    production: false
};
//# sourceMappingURL=environment.js.map

/***/ }),

/***/ 135:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_core_js_es6_reflect__ = __webpack_require__(154);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_core_js_es6_reflect___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_core_js_es6_reflect__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_core_js_es7_reflect__ = __webpack_require__(155);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_core_js_es7_reflect___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_1_core_js_es7_reflect__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_zone_js_dist_zone__ = __webpack_require__(260);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_zone_js_dist_zone___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_2_zone_js_dist_zone__);
/**
 * This file includes polyfills needed by Angular and is loaded before the app.
 * You can add your own extra polyfills to this file.
 *
 * This file is divided into 2 sections:
 *   1. Browser polyfills. These are applied before loading ZoneJS and are sorted by browsers.
 *   2. Application imports. Files imported after ZoneJS that should be loaded before your main
 *      file.
 *
 * The current setup is for so-called "evergreen" browsers; the last versions of browsers that
 * automatically update themselves. This includes Safari >= 10, Chrome >= 55 (including Opera),
 * Edge >= 13 on the desktop, and iOS 10 and Chrome on mobile.
 *
 * Learn more in https://angular.io/docs/ts/latest/guide/browser-support.html
 */
/***************************************************************************************************
 * BROWSER POLYFILLS
 */
/** IE9, IE10 and IE11 requires all of the following polyfills. **/
// import 'core-js/es6/symbol';
// import 'core-js/es6/object';
// import 'core-js/es6/function';
// import 'core-js/es6/parse-int';
// import 'core-js/es6/parse-float';
// import 'core-js/es6/number';
// import 'core-js/es6/math';
// import 'core-js/es6/string';
// import 'core-js/es6/date';
// import 'core-js/es6/array';
// import 'core-js/es6/regexp';
// import 'core-js/es6/map';
// import 'core-js/es6/set';
/** IE10 and IE11 requires the following for NgClass support on SVG elements */
// import 'classlist.js';  // Run `npm install --save classlist.js`.
/** IE10 and IE11 requires the following to support `@angular/animation`. */
// import 'web-animations-js';  // Run `npm install --save web-animations-js`.
/** Evergreen browsers require these. **/


/** ALL Firefox browsers require the following to support `@angular/animation`. **/
// import 'web-animations-js';  // Run `npm install --save web-animations-js`.
/***************************************************************************************************
 * Zone JS is required by Angular itself.
 */
 // Included with Angular CLI.
/***************************************************************************************************
 * APPLICATION IMPORTS
 */
/**
 * Date, currency, decimal and percent pipes.
 * Needed for: All but Chrome, Firefox, Edge, IE11 and Safari 10
 */
// import 'intl';  // Run `npm install --save intl`.
//# sourceMappingURL=polyfills.js.map

/***/ }),

/***/ 208:
/***/ (function(module, exports, __webpack_require__) {

exports = module.exports = __webpack_require__(20)();
// imports


// module
exports.push([module.i, ".babylon-canvas {\r\n    width: 100%;\r\n    min-height: 100px;\r\n    background-color: #444444;\r\n}\r\n\r\n/***************************************\r\nTODO : Put these box in a common element\r\n */\r\n.firefly-box {\r\n    overflow: hidden;\r\n    border-radius: 2px;\r\n    background-color: #303030;\r\n    box-shadow: 2px 1px 5px #101010;\r\n}\r\n\r\n.firefly-box-shadow {\r\n    box-shadow: 0 10px 60px 40px #444;\r\n}\r\n/******************************************/", ""]);

// exports


/*** EXPORTS FROM exports-loader ***/
module.exports = module.exports.toString();

/***/ }),

/***/ 209:
/***/ (function(module, exports, __webpack_require__) {

exports = module.exports = __webpack_require__(20)();
// imports


// module
exports.push([module.i, "* {\r\n    color: darkgray;\r\n}\r\n\r\napp-toolbar {\r\n    position: fixed;\r\n    top: 0;\r\n    width: 100%;\r\n}\r\n\r\n#main-container {\r\n    margin-top: 70px;\r\n    display: -webkit-box;\r\n    display: -ms-flexbox;\r\n    display: flex;\r\n    -ms-flex-wrap: nowrap;\r\n        flex-wrap: nowrap;\r\n    -webkit-box-pack: justify;\r\n        -ms-flex-pack: justify;\r\n            justify-content: space-between;\r\n}\r\n\r\napp-tasks-overview {\r\n    -webkit-box-flex: 1;\r\n        -ms-flex: 1;\r\n            flex: 1;\r\n    margin: 10px;\r\n}\r\n\r\napp-task-view {\r\n    -webkit-box-flex: 4;\r\n        -ms-flex: 4;\r\n            flex: 4;\r\n    margin: 10px;\r\n}\r\n\r\n.hidden {\r\n    display: none;\r\n}\r\n\r\n.visible {\r\n    display: block;\r\n}\r\n\r\n", ""]);

// exports


/*** EXPORTS FROM exports-loader ***/
module.exports = module.exports.toString();

/***/ }),

/***/ 210:
/***/ (function(module, exports, __webpack_require__) {

exports = module.exports = __webpack_require__(20)();
// imports


// module
exports.push([module.i, ".task-content {\r\n    padding: 8px;\r\n}\r\n\r\n.task-card {\r\n    max-height: 200px;\r\n    width: 100%;\r\n}\r\n\r\n/***************************************\r\nTODO : Put these box in a common element\r\n */\r\n.firefly-box {\r\n    overflow: hidden;\r\n    border-radius: 2px;\r\n    background-color: #303030;\r\n    box-shadow: 2px 1px 5px #101010;\r\n}\r\n\r\n.firefly-box-shadow {\r\n    box-shadow: 0 10px 60px 40px #444;\r\n}\r\n/******************************************/\r\n\r\n.task-card-desc {\r\n    margin: 10px;\r\n    display: inline-block;\r\n    height: 60px;\r\n    overflow: hidden !important;\r\n    text-overflow: ellipsis;\r\n}\r\n\r\n.task-line-desc {\r\n    display: none;\r\n}\r\n\r\n.task-card-bottom {\r\n    height: 10px;\r\n    background-color: white;\r\n    box-shadow: 0 0 1px 2px white;\r\n}\r\n\r\n.task-line-bottom {\r\n    display: none;\r\n}\r\n\r\n.task-card-header {\r\n    font-size: 20px;\r\n    font-style: normal;\r\n    font-variant: normal;\r\n    font-weight: 500;\r\n    line-height: 24px;\r\n    margin: 0;\r\n    border-bottom: 2px solid #3b3b3b;\r\n}\r\n\r\n.task-line-header {\r\n    font-size: 20px;\r\n    font-style: normal;\r\n    font-variant: normal;\r\n    font-weight: 500;\r\n    line-height: 24px;\r\n    margin: 0;\r\n    border-bottom: 10px solid #3b3b3b;\r\n}\r\n\r\n.task-card-header-left {\r\n    max-width: 70%;\r\n    display: inline-block;\r\n    overflow: hidden !important;\r\n    text-overflow: ellipsis;\r\n    white-space: nowrap;\r\n}\r\n\r\n.task-line-header-left {\r\n    max-width: 70%;\r\n    display: inline-block;\r\n    overflow: hidden !important;\r\n    text-overflow: ellipsis;\r\n    white-space: nowrap;\r\n}\r\n\r\n.task-card-header-right {\r\n    float: right;\r\n}\r\n\r\n.task-line-header-right {\r\n    float: right;\r\n}\r\n\r\n.task-card-number {\r\n    float: right;\r\n    margin-left: 10px;\r\n}\r\n\r\n.task-line-number {\r\n    float: right;\r\n    margin-left: 10px;\r\n}\r\n\r\n.task-card-state {\r\n    width: 20px;\r\n    float: right;\r\n}\r\n\r\n.task-line-state {\r\n    width: 20px;\r\n    float: right;\r\n}\r\n\r\n.task-card-footer {\r\n    text-align: right;\r\n    margin-right: 10px;\r\n}\r\n\r\n.task-line-footer {\r\n    display: none;\r\n}\r\n\r\n.task-card-text-footer {\r\n    font-size: 13px;\r\n    font-style: italic;\r\n    font-variant: normal;\r\n    font-weight: 500;\r\n    line-height: 13px;\r\n}\r\n\r\n.task-line-text-footer {\r\n    display: none;\r\n}", ""]);

// exports


/*** EXPORTS FROM exports-loader ***/
module.exports = module.exports.toString();

/***/ }),

/***/ 211:
/***/ (function(module, exports, __webpack_require__) {

exports = module.exports = __webpack_require__(20)();
// imports


// module
exports.push([module.i, ".task-modal-dialog {\r\n    background-color: #222222;\r\n}\r\n\r\n.task-modal-header {\r\n    background-color: #303030;\r\n    color: #fff;\r\n    box-shadow: 0 3px 5px 0 black;\r\n    margin-bottom: 20px;\r\n}", ""]);

// exports


/*** EXPORTS FROM exports-loader ***/
module.exports = module.exports.toString();

/***/ }),

/***/ 212:
/***/ (function(module, exports, __webpack_require__) {

exports = module.exports = __webpack_require__(20)();
// imports


// module
exports.push([module.i, "ul {\r\n    margin: auto;\r\n    list-style-type: none;\r\n    display: -webkit-box;\r\n    display: -ms-flexbox;\r\n    display: flex;\r\n    -ms-flex-line-pack: justify;\r\n        align-content: space-between;\r\n    -webkit-box-pack: justify;\r\n        -ms-flex-pack: justify;\r\n            justify-content: space-between;\r\n    -webkit-box-orient: horizontal;\r\n    -webkit-box-direction: normal;\r\n        -ms-flex-flow: row wrap;\r\n            flex-flow: row wrap;\r\n    -webkit-box-align: stretch;\r\n        -ms-flex-align: stretch;\r\n            align-items: stretch;\r\n    padding: 0;\r\n}\r\n\r\nli.line {\r\n    width: 100%;\r\n    margin: 3px 5px;\r\n}\r\n\r\nli.card {\r\n    width : 300px;\r\n    margin: 10px 5px;\r\n}\r\n\r\napp-task-line {\r\n    width: 100%;\r\n}", ""]);

// exports


/*** EXPORTS FROM exports-loader ***/
module.exports = module.exports.toString();

/***/ }),

/***/ 213:
/***/ (function(module, exports, __webpack_require__) {

exports = module.exports = __webpack_require__(20)();
// imports


// module
exports.push([module.i, ".img-title {\r\n    height: 70%;\r\n    position: relative;\r\n    top: 50%;\r\n    left: 100px;\r\n    -webkit-transform: translateY(-50%);\r\n    transform: translateY(-50%);\r\n}\r\n\r\n.toolbar {\r\n    height: 60px;\r\n    background-color: #303030;\r\n    box-shadow: 0 0 20px #000;\r\n    -webkit-box-shadow: 0 0 20px #000;\r\n    -moz-box-shadow: 0 0 20px #000;\r\n}\r\n\r\n.toolbar-btn {\r\n    float: right;\r\n}", ""]);

// exports


/*** EXPORTS FROM exports-loader ***/
module.exports = module.exports.toString();

/***/ }),

/***/ 218:
/***/ (function(module, exports) {

function webpackEmptyContext(req) {
	throw new Error("Cannot find module '" + req + "'.");
}
webpackEmptyContext.keys = function() { return []; };
webpackEmptyContext.resolve = webpackEmptyContext;
module.exports = webpackEmptyContext;
webpackEmptyContext.id = 218;


/***/ }),

/***/ 223:
/***/ (function(module, exports) {

module.exports = "<div *ngIf=\"task !== undefined\">\n    <h3>\n        <span>{{task.name | capitalize}}</span>\n        <span>\n            <span>#{{task.id}}</span>\n            <img *ngIf=\"states[task.state]\" [src]=\"states[task.state]\"/>\n        </span>\n    </h3>\n    <div class=\"firefly-box\">\n        <div class=\"firefly-box-shadow\"></div>\n        <canvas id=\"babylon-canvas\"></canvas>\n    </div>\n    <span>Description : </span>\n    <p>{{task.description}}</p>\n    <br>\n    <span>Utilisateur : </span>\n    <p>{{task.user_name}}</p>\n    <br>\n    <span>Date de création : </span>\n    <p>{{task.date}}</p>\n    <br>\n    <!--<span>Module : </span>-->\n    <!--<p>{{task.module}}</p>-->\n    <!--<br>-->\n    <!--<span>Type : </span>-->\n    <!--<p>{{task.type}}</p>-->\n\n\n</div>\n"

/***/ }),

/***/ 224:
/***/ (function(module, exports) {

module.exports = "<app-toolbar></app-toolbar>\n<div id=\"main-container\">\n    <app-tasks-overview (clickTask)=\"updateTask($event)\"></app-tasks-overview>\n    <app-task-view [ngClass]=\"taskSelected ? 'visible' : 'hidden'\" [task]=\"task\"></app-task-view>\n</div>\n"

/***/ }),

/***/ 225:
/***/ (function(module, exports) {

module.exports = "<div class=\"task-card firefly-box\">\n    <div class=\"task-content\">\n        <div [ngClass]=\"'task-' + view_name + '-header'\">\n            <span [ngClass]=\"'task-' + view_name + '-header-left'\">{{task.name | capitalize}}</span>\n            <span [ngClass]=\"'task-' + view_name + '-header-right'\">\n                <span [ngClass]=\"'task-' + view_name + '-number'\">#{{task.id}}</span>\n                <img [ngClass]=\"'task-' + view_name + '-state'\" *ngIf=\"states[task.state]\" [src]=\"states[task.state]\">\n            </span>\n        </div>\n        <p [ngClass]=\"'task-' + view_name + '-desc'\">\n            {{task.description}}\n        </p>\n        <div [ngClass]=\"'task-' + view_name + '-footer task-card-text-footer'\">\n            Créé par {{task.user_name}} le {{task.date | date:'dd/MM/yyyy à HH:MM'}}\n        </div>\n    </div>\n    <div class=\"firefly-box-shadow\"></div>\n    <div [ngClass]=\"'task-' + view_name + '-bottom'\"></div>\n</div>\n"

/***/ }),

/***/ 226:
/***/ (function(module, exports) {

module.exports = "<div class=\"container-fluid task-modal-dialog\">\n    <form novalidate class=\"simple-form\">\n        <div class=\"row task-modal-header\">\n            <h1 class=\"col-sm-10\">Création d'une nouvelle tâche</h1>\n            <button class=\"cols-sm-2 close\" type=\"button\" (click)=\"onCancel()\" aria-label=\"Close\">\n                <span aria-hidden=\"true\">&times;</span>\n            </button>\n        </div>\n        <div class=\"task-modal-body\">\n            <label for=\"task-title\">Titre: </label><br/>\n            <input type=\"text\" name=\"task-title\" id=\"task-title\" [(ngModel)]=\"task.name\" autofocus required/><br/>\n\n            <label for=\"task-desc\">Description: </label><br/>\n            <textarea name=\"task-desc\" id=\"task-desc\" [(ngModel)]=\"task.description\" cols=\"40\" rows=\"4\"></textarea><br/>\n\n            <label for=\"task-module\">Module: </label><br/>\n            <select name=\"task-module\" id=\"task-module\" [(ngModel)]=\"task.module\">\n                <option *ngFor=\"let module of modules_list\" [ngValue]=\"module.id\">{{module.title}}</option>\n            </select><br/>\n\n            <label for=\"task-module\">Tâche: </label><br/>\n            <select *ngIf=\"task.module !== undefined\" name=\"task-type\" id=\"task-type\" [(ngModel)]=\"task.type\">\n                <option *ngFor=\"let type of getTypesFromModule(task.module)\" [ngValue]=\"type.id\">{{type.name}}</option>\n            </select><br/>\n        </div>\n        <div class=\"task-modal-footer\">\n            <button type=\"button\" (click)=\"onCreateTask()\">Créer</button>\n            <button type=\"button\" (click)=\"onCancel()\">Annuler</button>\n        </div>\n    </form>\n</div>\n"

/***/ }),

/***/ 227:
/***/ (function(module, exports) {

module.exports = "<ul [ngClass]=\"view_name\">\n    <li [ngClass]=\"view_name\" *ngFor=\"let task of tasks\">\n        <app-task-line (click)=\"onClick(task)\" [task]=\"task\" [view_name]=\"view_name\"></app-task-line>\n    </li>\n</ul>\n"

/***/ }),

/***/ 228:
/***/ (function(module, exports) {

module.exports = "<header class=\"toolbar\">\n    <img class=\"img-title\" [src]=\"fullTitleImagePath\"/>\n    <button id=\"tasks-toggle-overview-display-btn\" class=\"toolbar-btn\" (click)=\"onClickToggleView()\">toggle overview</button>\n    <button id=\"tasks-create-task-display-btn\" class=\"toolbar-btn\" (click)=\"onClickCreateTask()\">create task</button>\n</header>"

/***/ }),

/***/ 261:
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(120);


/***/ }),

/***/ 42:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_rxjs_Subject__ = __webpack_require__(21);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_rxjs_Subject___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_1_rxjs_Subject__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return ToolbarButtonService; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var ToolbarButtonService = (function () {
    function ToolbarButtonService() {
        this._currentView = 0;
        this._createTaskItemSource = new __WEBPACK_IMPORTED_MODULE_1_rxjs_Subject__["Subject"]();
        this._toggleViewItemSource = new __WEBPACK_IMPORTED_MODULE_1_rxjs_Subject__["Subject"]();
        this._createTaskItem = this._createTaskItemSource.asObservable();
        this._toggleViewItem = this._toggleViewItemSource.asObservable();
    }
    ToolbarButtonService.prototype.createTask = function () {
        console.log('Emit task creation event');
        this._createTaskItemSource.next(0);
    };
    ToolbarButtonService.prototype.toggleView = function () {
        console.log('Emit toggle view event');
        this._currentView++;
        this._toggleViewItemSource.next(this._currentView % 2);
    };
    ToolbarButtonService.prototype.subscribeCreateTask = function (next, error, complete) {
        console.log('Subscribe to task creation event');
        return this._createTaskItem.subscribe(next, error, complete);
    };
    ToolbarButtonService.prototype.subscribeToggleView = function (next, error, complete) {
        console.log('Subscribe to toggle view event');
        this._toggleViewItem.subscribe(next, error, complete);
        this._toggleViewItemSource.next(this._currentView);
    };
    return ToolbarButtonService;
}());
ToolbarButtonService = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["h" /* Injectable */])(),
    __metadata("design:paramtypes", [])
], ToolbarButtonService);

//# sourceMappingURL=toolbar-button.service.js.map

/***/ }),

/***/ 74:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return Task; });
/**
 * Created by celia on 15/04/2017.
 */
var Task = (function () {
    function Task() {
    }
    return Task;
}());

//# sourceMappingURL=Task.js.map

/***/ }),

/***/ 75:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_http__ = __webpack_require__(41);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_rxjs_Observable__ = __webpack_require__(2);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_rxjs_Observable___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_2_rxjs_Observable__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3_rxjs_add_operator_catch__ = __webpack_require__(108);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3_rxjs_add_operator_catch___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_3_rxjs_add_operator_catch__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4_rxjs_add_operator_map__ = __webpack_require__(109);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4_rxjs_add_operator_map___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_4_rxjs_add_operator_map__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_rxjs_add_observable_throw__ = __webpack_require__(107);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_rxjs_add_observable_throw___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_5_rxjs_add_observable_throw__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return ModuleService; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};






// TODO make an unique class for all firefly api
var ModuleService = ModuleService_1 = (function () {
    function ModuleService(http) {
        this.http = http;
    }
    ModuleService.extractData = function (res) {
        return res.json() || {};
    };
    ModuleService.handleError = function (error) {
        // In a real world app, you might use a remote logging infrastructure
        var errMsg;
        if (error instanceof __WEBPACK_IMPORTED_MODULE_1__angular_http__["b" /* Response */]) {
            var body = error.json() || '';
            var err = body.error || JSON.stringify(body);
            errMsg = error.status + " - " + (error.statusText || '') + " " + err;
        }
        else {
            errMsg = error.message ? error.message : error.toString();
        }
        console.error(errMsg);
        return __WEBPACK_IMPORTED_MODULE_2_rxjs_Observable__["Observable"].throw(errMsg);
    };
    ModuleService.prototype.getModules = function () {
        return this.http.get(ModuleService_1.MODULES_URL)
            .map(ModuleService_1.extractData)
            .catch(ModuleService_1.handleError);
    };
    return ModuleService;
}());
ModuleService.MODULES_URL = 'api/v1/modules'; // URL to web API
ModuleService = ModuleService_1 = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["h" /* Injectable */])(),
    __metadata("design:paramtypes", [typeof (_a = typeof __WEBPACK_IMPORTED_MODULE_1__angular_http__["c" /* Http */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_1__angular_http__["c" /* Http */]) === "function" && _a || Object])
], ModuleService);

var ModuleService_1, _a;
//# sourceMappingURL=module.service.js.map

/***/ }),

/***/ 76:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_http__ = __webpack_require__(41);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_rxjs_Observable__ = __webpack_require__(2);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_rxjs_Observable___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_2_rxjs_Observable__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3_rxjs_add_operator_catch__ = __webpack_require__(108);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3_rxjs_add_operator_catch___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_3_rxjs_add_operator_catch__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4_rxjs_add_operator_map__ = __webpack_require__(109);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4_rxjs_add_operator_map___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_4_rxjs_add_operator_map__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_rxjs_add_observable_throw__ = __webpack_require__(107);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_rxjs_add_observable_throw___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_5_rxjs_add_observable_throw__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return TaskService; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};






var TaskService = TaskService_1 = (function () {
    function TaskService(http) {
        this.http = http;
    }
    TaskService.extractData = function (res) {
        return res.json() || {};
    };
    TaskService.handleError = function (error) {
        // In a real world app, you might use a remote logging infrastructure
        var errMsg;
        if (error instanceof __WEBPACK_IMPORTED_MODULE_1__angular_http__["b" /* Response */]) {
            var body = error.json() || '';
            var err = body.error || JSON.stringify(body);
            errMsg = error.status + " - " + (error.statusText || '') + " " + err;
        }
        else {
            errMsg = error.message ? error.message : error.toString();
        }
        console.error(errMsg);
        return __WEBPACK_IMPORTED_MODULE_2_rxjs_Observable__["Observable"].throw(errMsg);
    };
    TaskService.prototype.getTasks = function () {
        return this.http.get(TaskService_1.TASKS_URL)
            .map(TaskService_1.extractData)
            .catch(TaskService_1.handleError);
    };
    TaskService.prototype.createTask = function (task) {
        var headers = new __WEBPACK_IMPORTED_MODULE_1__angular_http__["d" /* Headers */]({ 'Content-Type': 'application/json' });
        var options = new __WEBPACK_IMPORTED_MODULE_1__angular_http__["e" /* RequestOptions */]({ headers: headers });
        console.log(task);
        console.log(JSON.stringify(task));
        return this.http.post(TaskService_1.TASKS_URL, JSON.stringify(task), options)
            .map(TaskService_1.extractData)
            .catch(TaskService_1.handleError);
    };
    TaskService.prototype.getNames = function () {
        return this.http.get(TaskService_1.NAMES_URL)
            .map(TaskService_1.extractData)
            .catch(TaskService_1.handleError);
    };
    TaskService.prototype.getCategories = function () {
        return this.http.get(TaskService_1.CATEGORIES_URL)
            .map(TaskService_1.extractData)
            .catch(TaskService_1.handleError);
    };
    return TaskService;
}());
TaskService.TASKS_URL = 'api/v1/tasks'; // URL to web API
TaskService.NAMES_URL = 'api/v1/names'; // URL to web API
TaskService.CATEGORIES_URL = 'api/v1/categories'; // URL to web API
TaskService = TaskService_1 = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["h" /* Injectable */])(),
    __metadata("design:paramtypes", [typeof (_a = typeof __WEBPACK_IMPORTED_MODULE_1__angular_http__["c" /* Http */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_1__angular_http__["c" /* Http */]) === "function" && _a || Object])
], TaskService);

var TaskService_1, _a;
//# sourceMappingURL=task.service.js.map

/***/ }),

/***/ 77:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_angular2_modal__ = __webpack_require__(5);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_angular2_modal_plugins_bootstrap__ = __webpack_require__(31);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3_app_api_firefly_data_Task__ = __webpack_require__(74);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4__api_firefly_task_service__ = __webpack_require__(76);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_app_api_firefly_module_service__ = __webpack_require__(75);
/* unused harmony export TaskModalContext */
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return TaskModalComponent; });
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






var TaskModalContext = (function (_super) {
    __extends(TaskModalContext, _super);
    function TaskModalContext() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    return TaskModalContext;
}(__WEBPACK_IMPORTED_MODULE_2_angular2_modal_plugins_bootstrap__["b" /* BSModalContext */]));

var TaskModalComponent = TaskModalComponent_1 = (function () {
    function TaskModalComponent(dialog, taskService, moduleService) {
        this.dialog = dialog;
        this.taskService = taskService;
        this.moduleService = moduleService;
        this.context = dialog.context;
        this.task = new __WEBPACK_IMPORTED_MODULE_3_app_api_firefly_data_Task__["a" /* Task */]();
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
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["d" /* Component */])({
        selector: 'app-task-modal',
        providers: [__WEBPACK_IMPORTED_MODULE_4__api_firefly_task_service__["a" /* TaskService */], __WEBPACK_IMPORTED_MODULE_5_app_api_firefly_module_service__["a" /* ModuleService */]],
        styles: [__webpack_require__(211)],
        template: __webpack_require__(226)
    }),
    __metadata("design:paramtypes", [typeof (_a = typeof __WEBPACK_IMPORTED_MODULE_1_angular2_modal__["d" /* DialogRef */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_1_angular2_modal__["d" /* DialogRef */]) === "function" && _a || Object, typeof (_b = typeof __WEBPACK_IMPORTED_MODULE_4__api_firefly_task_service__["a" /* TaskService */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_4__api_firefly_task_service__["a" /* TaskService */]) === "function" && _b || Object, typeof (_c = typeof __WEBPACK_IMPORTED_MODULE_5_app_api_firefly_module_service__["a" /* ModuleService */] !== "undefined" && __WEBPACK_IMPORTED_MODULE_5_app_api_firefly_module_service__["a" /* ModuleService */]) === "function" && _c || Object])
], TaskModalComponent);

var TaskModalComponent_1, _a, _b, _c;
//# sourceMappingURL=task-modal.component.js.map

/***/ }),

/***/ 78:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_common__ = __webpack_require__(11);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__capitalize_pipe__ = __webpack_require__(133);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return UtilsModule; });
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};



var UtilsModule = (function () {
    function UtilsModule() {
    }
    return UtilsModule;
}());
UtilsModule = __decorate([
    __webpack_require__.i(__WEBPACK_IMPORTED_MODULE_0__angular_core__["b" /* NgModule */])({
        imports: [
            __WEBPACK_IMPORTED_MODULE_1__angular_common__["a" /* CommonModule */]
        ],
        declarations: [__WEBPACK_IMPORTED_MODULE_2__capitalize_pipe__["a" /* CapitalizePipe */]],
        exports: [__WEBPACK_IMPORTED_MODULE_2__capitalize_pipe__["a" /* CapitalizePipe */]]
    })
], UtilsModule);

//# sourceMappingURL=utils.module.js.map

/***/ })

},[261]);
//# sourceMappingURL=main.bundle.js.map