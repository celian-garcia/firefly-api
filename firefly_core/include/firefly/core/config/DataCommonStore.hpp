// Copyright 2017 <Célian Garcia>

#pragma once

#include <atomic>
#include <vector>
#include <firefly/core/data/Module.hpp>

namespace firefly {

/**
 * Not thread safe class
 */
class DataCommonStore {
 public:
    void storeModule(Module *module);

    const Module getModuleById(int id) const;

    const std::vector<Module> getModules() const;

    const ProcessingType &getProcessingTypeByIds(int module_id, int proc_id);

 private:
    std::vector<Module> modules;
};

}  // namespace firefly

