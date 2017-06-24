// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/TaskBuilder.hpp"


namespace firefly {

    Task TaskBuilder::buildTask(DataCommonStore dataStore) {
        this->task.setModule(dataStore.getModuleById(this->module_id));
        this->task.setType(dataStore.getProcessingTypeById(this->type_id));
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

    void TaskBuilder::setIdentifier(const std::string &identifier) {
        this->task.setIdentifier(identifier);
    }

    void TaskBuilder::setType(const std::string &type) {
        this->type_id = type;
    }

    void TaskBuilder::setModule(const std::string &module) {
        this->module_id = module;
    }

    void TaskBuilder::setUserName(const std::string &userName) {
        this->task.setUserName(userName);
    }
}