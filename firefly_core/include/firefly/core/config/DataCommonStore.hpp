// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_DATACOMMONSTORE_HPP
#define FIREFLY_DATACOMMONSTORE_HPP

#include <firefly/core/data/Module.hpp>
#include <atomic>

namespace firefly {
    /**
     * Not thread safe class
     */
    class DataCommonStore {

    public:
        void storeModule(Module& module);

        const Module getModuleById(int id) const;

        const std::vector<Module> getModules() const;

        const ProcessingType &getProcessingTypeByIds(int module_id, int proc_id);

    private:
        std::vector<Module> modules;
    };
}

#endif //FIREFLY_DATACOMMONSTORE_HPP
