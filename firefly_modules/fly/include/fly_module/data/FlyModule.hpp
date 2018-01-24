// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_MODULES_FLY_INCLUDE_FLY_MODULE_DATA_FLYMODULE_HPP_
#define FIREFLY_MODULES_FLY_INCLUDE_FLY_MODULE_DATA_FLYMODULE_HPP_

#include <string>
#include <firefly/core/data/Module.hpp>

namespace firefly {

class FlyModule : public Module {
 private:
    static const std::string TITLE;
    static const std::string DESCRIPTION;
    static const std::string IMAGE_PATH;
    static const ProcessingType R3D_PROC_TYPE;
    static const ProcessingType P3D_PROC_TYPE;
    static const ProcessingType P3DR_PROC_TYPE;
    static const ProcessingType P3DD_PROC_TYPE;

 public:
    FlyModule();
};

}  // namespace firefly

#endif  // FIREFLY_MODULES_FLY_INCLUDE_FLY_MODULE_DATA_FLYMODULE_HPP_
