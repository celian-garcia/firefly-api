// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/ProcessingType.hpp"

namespace firefly {

    ProcessingType::ProcessingType(const std::string &name, const std::vector<std::string> &aliases) : name(name),
                                                                                                       aliases(aliases) {}

    const std::string &ProcessingType::getName() const {
        return name;
    }

    const std::vector<std::string> &ProcessingType::getAliases() const {
        return aliases;
    }

    const std::string &ProcessingType::getId() const {
        return id;
    }
}

