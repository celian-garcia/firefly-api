// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/TaskBuilder.hpp"


namespace firefly {

    Task TaskBuilder::buildTask(DataCommonStore dataStore) {
        std::vector<Module> modules = dataStore.getModules();
        Module module = modules[this->module_id];
        std::vector<ProcessingType> types = module.getProcessingTypesList();
        ProcessingType type = types[this->type_id];

        this->task.setModule(module);
        this->task.setType(type);
        return this->task;
    }

    void TaskBuilder::setState(Task::State state) {
        this->task.setState(state);
    }

    void TaskBuilder::setName(const std::string &name) {
        this->task.setName(name);
    }

    void TaskBuilder::setDate(const std::string &date) {
        this->task.setDate(date);
    }

    void TaskBuilder::setDescription(const std::string &description) {
        this->task.setDescription(description);
    }

    void TaskBuilder::setIdentifier(const int &identifier) {
        this->task.setIdentifier(identifier);
    }

    void TaskBuilder::setType(const int &type) {
        this->type_id = type;
    }

    void TaskBuilder::setModule(const int &module) {
        this->module_id = module;
    }

    void TaskBuilder::setUserName(const std::string &userName) {
        this->task.setUserName(userName);
    }
}