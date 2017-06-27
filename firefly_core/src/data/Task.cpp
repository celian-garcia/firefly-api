// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/Task.hpp"

namespace firefly {

    Task::Task(const std::string &name, const std::string &description,
               const ProcessingType &type, const Module &module, const std::string &userName, const std::string &date) :
            name(name), description(description),
            type(type), module(module), userName(userName), date(date) {}

    Task::Task(const int &identifier, const std::string &name, const std::string &description,
               const ProcessingType &type, const Module &module, const std::string &userName, const std::string &date) :
            identifier(identifier), name(name), description(description),
            type(type), module(module), userName(userName), date(date) {}

    Task::Task(const int &identifier, const std::string &name, const std::string &description,
               const ProcessingType &type, const Module &module, const State &state, const std::string &userName, const std::string &date) :
            identifier(identifier), name(name), description(description),
            type(type), module(module), state(state), userName(userName), date(date) {}

    const int &Task::getIdentifier() const {
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

    void Task::setState(Task::State state) {
        Task::state = state;
    }

    void Task::setName(const std::string &name) {
        Task::name = name;
    }

    void Task::setIdentifier(const int &identifier) {
        Task::identifier = identifier;
    }

    void Task::setDescription(const std::string &description) {
        Task::description = description;
    }

    void Task::setType(const ProcessingType &type) {
        Task::type = type;
    }

    void Task::setModule(const Module &module) {
        Task::module = module;
    }

    void Task::setUserName(const std::string &userName) {
        Task::userName = userName;
    }

    void Task::setDate(const std::string &date) {
        Task::date = date;
    }

}
