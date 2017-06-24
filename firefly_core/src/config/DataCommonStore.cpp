// Copyright 2017 <Célian Garcia>

#include "firefly/core/config/DataCommonStore.hpp"

namespace firefly {
    void DataCommonStore::storeModule(Module module) {
        modulesMap[module.getId()] = module;
    }

    Module DataCommonStore::getModuleById(std::string id) {
        return modulesMap[id];
    }

    ProcessingType DataCommonStore::getProcessingTypeById(std::string id) {
        return procTypesMap[id];
    }
}