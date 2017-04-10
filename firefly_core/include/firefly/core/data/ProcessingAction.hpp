// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_RESOURCE_HPP
#define FIREFLY_RESOURCE_HPP

#include <string>
namespace firefly {
    class ProcessingAction {
    private:
        std::string processingId;
        std::string name;
        std::string description;
        std::string httpMethod;

    };
}

#endif //FIREFLY_RESOURCE_HPP
