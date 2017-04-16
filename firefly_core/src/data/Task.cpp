// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/Task.hpp"

namespace firefly {

    Task::Task(const std::string &name, const std::string &description,
                           const ProcessingType &type) : name(name), description(description),
                                                         type(type) {}

    const std::string &Task::getIdentifier() const {
        return identifier;
    }

    const std::string &Task::getName() const {
        return name;
    }

    const std::string &Task::getDescription() const {
        return description;
    }

    const ProcessingType &Task::getType() const {
        return type;
    }

    const std::string &Task::getCategory() const {
        return category;
    }

    const std::string &Task::getUserName() const {
        return userName;
    }

    Task::State Task::getState() const {
        return state;
    }

}
