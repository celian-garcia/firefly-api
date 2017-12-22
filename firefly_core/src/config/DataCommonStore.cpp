// Copyright 2017 <Célian Garcia>

#include "firefly/core/config/DataCommonStore.hpp"

namespace firefly {

void DataCommonStore::storeModule(Module *module) {
    module->setId(static_cast<int>(modules.size()));
    std::vector<ProcessingType> new_proc_types;
    int current_proc_id = 0;
    for (auto proc : module->getProcessingTypesList()) {
        ProcessingType new_proc = proc;
        new_proc.setId(current_proc_id++);
        new_proc_types.push_back(new_proc);
    }
    module->setProcessingTypesList(new_proc_types);
    this->modules.push_back(*module);
}

const Module DataCommonStore::getModuleById(int id) const {
    return modules[id];
}

const std::vector<Module> DataCommonStore::getModules() const {
    return modules;
}

const ProcessingType &DataCommonStore::getProcessingTypeByIds(int module_id, int proc_id) {
    return this->getModuleById(module_id).getProcessingTypesList().at((unsigned int) proc_id);
}

}  // namespace firefly
