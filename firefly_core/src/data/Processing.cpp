// Copyright 2017 <Célian Garcia>

#include <firefly/core/data/ProcessingType.hpp>
#include "firefly/core/data/Processing.hpp"

namespace firefly {

    Processing::Processing(const std::string &title, const std::string &description,
                           const ProcessingType &type) : title(title), description(description),
                                                         type(type) {}

    const std::string &Processing::getIdentifier() const {
        return identifier;
    }

    const std::string &Processing::getName() const {
        return name;
    }

    const std::string &Processing::getTitle() const {
        return title;
    }

    const std::string &Processing::getDescription() const {
        return description;
    }

    const ProcessingType &Processing::getType() const {
        return type;
    }

}
