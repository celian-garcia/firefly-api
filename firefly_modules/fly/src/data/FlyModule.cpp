// Copyright 2017 <Célian Garcia>

#include "fly_module/data/FlyModule.hpp"

namespace firefly {

    const std::string FlyModule::TITLE = "Fly";
    const std::string FlyModule::DESCRIPTION = "Fly module description";
    const std::string FlyModule::IMAGE_PATH = "";
    const ProcessingType FlyModule::R3D_PROC_TYPE("Reconstruction 3D", {"R3D"});
    const ProcessingType FlyModule::P3D_PROC_TYPE("Population 3D", {"P3D"});
    const ProcessingType FlyModule::P3DR_PROC_TYPE("Population 3D random", {"P3Dr"});
    const ProcessingType FlyModule::P3DD_PROC_TYPE("Population 3D diamound", {"P3Dd"});

    FlyModule::FlyModule() {
        this->setTitle(FlyModule::TITLE);
        this->setDescription(FlyModule::DESCRIPTION);
        this->setImagePath(FlyModule::IMAGE_PATH);
        this->setProcessingTypesList({FlyModule::R3D_PROC_TYPE, FlyModule::P3D_PROC_TYPE,
                                      FlyModule::P3DR_PROC_TYPE, FlyModule::P3DD_PROC_TYPE});
    }

}  // namespace firefly
