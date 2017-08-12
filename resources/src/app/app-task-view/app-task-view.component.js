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
var BABYLON = require("babylonjs");
var AppTaskViewComponent = AppTaskViewComponent_1 = (function () {
    function AppTaskViewComponent() {
        this.states = AppTaskViewComponent_1.STATES;
        this.babylonIsRunning = false;
    }
    AppTaskViewComponent.createScene = function (engine, canvas) {
        // Now create a basic Babylon Scene object
        var scene = new BABYLON.Scene(engine);
        // Change the scene background color to green.
        scene.clearColor = new BABYLON.Color3(0, 1, 0);
        // This creates and positions a free camera
        var camera = new BABYLON.ArcRotateCamera('ArcRotateCamera', 1, 0.8, 10, new BABYLON.Vector3(0, 0, 0), scene);
        // This targets the camera to scene origin
        camera.setTarget(BABYLON.Vector3.Zero());
        // This attaches the camera to the canvas
        camera.attachControl(canvas, false);
        // This creates a light, aiming 0,1,0 - to the sky.
        var light = new BABYLON.HemisphericLight('light1', new BABYLON.Vector3(0, 1, 0), scene);
        // Dim the light a small amount
        light.intensity = .5;
        // Let's try our built-in 'sphere' shape. Params: name, subdivisions, size, scene
        var sphere = BABYLON.Mesh.CreateSphere('sphere1', 16, 2, scene);
        // Move the sphere upward 1/2 its height
        sphere.position.y = 1;
        // Let's try our built-in 'ground' shape.  Params: name, width, depth, subdivisions, scene
        var ground = BABYLON.Mesh.CreateGround('ground1', 6, 6, 2, scene);
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
        var engine = new BABYLON.Engine(canvas, true);
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
    core_1.Input(),
    __metadata("design:type", Object)
], AppTaskViewComponent.prototype, "task", void 0);
AppTaskViewComponent = AppTaskViewComponent_1 = __decorate([
    core_1.Component({
        selector: 'app-task-view',
        templateUrl: './app-task-view.component.html',
        styleUrls: ['./app-task-view.component.css']
    }),
    __metadata("design:paramtypes", [])
], AppTaskViewComponent);
exports.AppTaskViewComponent = AppTaskViewComponent;
var AppTaskViewComponent_1;
//# sourceMappingURL=app-task-view.component.js.map