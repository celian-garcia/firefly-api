// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/Task.hpp"

namespace firefly {

    Task::Task(const std::string &title, const std::string &description,
                           const ProcessingType &type) : title(title), description(description),
                                                         type(type) {}

    const std::string &Task::getIdentifier() const {
        return identifier;
    }

    const std::string &Task::getName() const {
        return name;
    }

    const std::string &Task::getTitle() const {
        return title;
    }

    const std::string &Task::getDescription() const {
        return description;
    }

    const ProcessingType &Task::getType() const {
        return type;
    }

}
