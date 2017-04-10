// Copyright 2017 <Célian Garcia>

#include "fly_module/data/FlyModule.hpp"

namespace firefly {
    const std::string FlyModule::TITLE = "Fly";
    const std::string FlyModule::DESCRIPTION = "Fly module description";
    const std::string FlyModule::IMAGE_PATH = "Image not found";

    FlyModule::FlyModule() {
        this->setTitle(FlyModule::TITLE);
        this->setDescription(FlyModule::DESCRIPTION);
        this->setImagePath(FlyModule::IMAGE_PATH);
    }
}

