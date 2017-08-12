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
var Subject_1 = require("rxjs/Subject");
var ToolbarButtonService = (function () {
    function ToolbarButtonService() {
        this._currentView = 0;
        this._createTaskItemSource = new Subject_1.Subject();
        this._toggleViewItemSource = new Subject_1.Subject();
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
    core_1.Injectable(),
    __metadata("design:paramtypes", [])
], ToolbarButtonService);
exports.ToolbarButtonService = ToolbarButtonService;
//# sourceMappingURL=toolbar-button.service.js.map