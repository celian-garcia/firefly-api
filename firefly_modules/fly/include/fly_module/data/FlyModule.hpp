// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_FLYMODULE_HPP
#define FIREFLY_FLYMODULE_HPP

#include <firefly/core/data/Module.hpp>

namespace firefly {
    class FlyModule : public Module {
    private:
        static const std::string TITLE;
        static const std::string DESCRIPTION;
        static const std::string IMAGE_PATH;

    public:

        FlyModule();
    };
}

#endif //FIREFLY_FLYMODULE_HPP
