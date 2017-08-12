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
var toolbar_button_service_1 = require("./toolbar-button.service");
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
    core_1.Component({
        selector: 'app-toolbar',
        templateUrl: './toolbar.component.html',
        styleUrls: ['./toolbar.component.css']
    }),
    __metadata("design:paramtypes", [toolbar_button_service_1.ToolbarButtonService])
], ToolbarComponent);
exports.ToolbarComponent = ToolbarComponent;
//# sourceMappingURL=toolbar.component.js.map