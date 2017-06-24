// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_DATACOMMONSTORE_HPP
#define FIREFLY_DATACOMMONSTORE_HPP

#include <firefly/core/data/Module.hpp>

namespace firefly {
    class DataCommonStore {

    public:
        void storeModule(Module module);

        Module getModuleById(std::string id);

        ProcessingType getProcessingTypeById(std::string id);

    private:
        std::map<std::string, Module> modulesMap;
        std::map<std::string, ProcessingType> procTypesMap;
    };
}

#endif //FIREFLY_DATACOMMONSTORE_HPP
