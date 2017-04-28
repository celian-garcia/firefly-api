// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/Task.hpp"

namespace firefly {

    Task::Task(const std::string &identifier, const std::string &name, const std::string &description,
               const ProcessingType &type, const Module &module, const std::string &userName, const std::string &date) :
            identifier(identifier), name(name), description(description),
            type(type), module(module), userName(userName), date(date) {}

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

    const Module &Task::getModule() const {
        return module;
    }

    const std::string &Task::getUserName() const {
        return userName;
    }

    Task::State Task::getState() const {
        return state;
    }

    const std::string &Task::getDate() const {
        return date;
    }

}
