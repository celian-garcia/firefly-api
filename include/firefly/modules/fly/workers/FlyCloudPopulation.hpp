// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_FLYCLOUDPOPULATION_HPP
#define FIREFLY_FLYCLOUDPOPULATION_HPP

#include <firefly/utils/FireflyException.hpp>
#include <vector>

namespace firefly {
    namespace module_fly {
        class FlyCloudPopulation {
        public:

            static int start();

            static void stop();

            static void collect();

        private:
            static const std::vector<ProcessActionType> VALID_ACTION_TYPES;

        };
    }
}

#endif //FIREFLY_FLYCLOUDPOPULATION_HPP
