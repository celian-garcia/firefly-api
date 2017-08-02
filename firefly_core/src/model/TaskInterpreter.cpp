// Copyright 2017 <Célian Garcia>

#include "firefly/core/model/TaskInterpreter.hpp"

namespace firefly {
    TaskInterpreter::TaskInterpreter(DataCommonStore * dataStore, PGresult *result) {
        this->dataStore = dataStore;
        this->interpreter = new PGResultInterpreter(result);
        this->interpreter->registerProperties(PROPERTIES());
    }

    TaskInterpreter::~TaskInterpreter() {
        delete this->interpreter;
    }

    const std::vector<const char *> TaskInterpreter::PROPERTIES() {
        return {"id", "name", "description", "type", "module", "state", "\"user\"", "date"};
    }

    Task TaskInterpreter::getTask(int row) {
        // Interpretation of the given row
        auto id = this->interpreter->get<int>("id", row);
        auto name = static_cast<std::string> (this->interpreter->get<char *>("name", row));
        auto description = static_cast<std::string> (this->interpreter->get<char *>("description", row));
        auto type_id = this->interpreter->get<int>("type", row);
        auto module_id = this->interpreter->get<int>("module", row);
        auto state = static_cast<Task::State> (this->interpreter->get<int>("state", row));
        auto user = static_cast<std::string> (this->interpreter->get<char *>("state", row));
        auto date = static_cast<std::string> (this->interpreter->get<char *>("state", row));

        // Task creation from interpreted data
        Module module = this->dataStore->getModuleById(module_id);
        std::vector<ProcessingType> types = module.getProcessingTypesList();
        ProcessingType type = types[type_id];
        Task task(id, name, description, type, module, state, user, date);
        return task;
    }

    int TaskInterpreter::get_row_number() {
        return this->interpreter->get_row_number();
    }
}
