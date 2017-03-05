// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_FLYCLOUDPOPULATION_HPP
#define FIREFLY_FLYCLOUDPOPULATION_HPP

#include <firefly/utils/FireflyException.hpp>

namespace firefly {
    namespace module_fly {
        class FlyCloudPopulation{
            FlyCloudPopulation();
            void start();
            void stop();
            void collect();
        private:
//            const std::vector capabilities = {
//                    ModuleCapability::START,
//                    ModuleCapability::STOP,
//                    ModuleCapability::COLLECT
//            };
        };
    }
}

#endif //FIREFLY_FLYCLOUDPOPULATION_HPP
