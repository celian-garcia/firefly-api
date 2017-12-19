// Copyright 2017 <Célian Garcia>

#include "firefly/core/model/interpreters/TaskInterpreter.hpp"

namespace firefly {
TaskInterpreter::TaskInterpreter(PGresult *result, DataCommonStore *data_store) : PGResultInterpreter(result),
                                                                                  m_data_store(data_store) {
    this->registerProperties(PROPERTIES());
}

const std::vector<const char *> TaskInterpreter::PROPERTIES() {
    return {"id", "name", "description", "type", "module", "state", "\"user\"", "date"};
}

Task TaskInterpreter::getTask(int row) {
    // Interpretation of the given row
    auto id = this->get<int>("id", row);
    auto name = static_cast<std::string> (this->get<char *>("name", row));
    auto description = static_cast<std::string> (this->get<char *>("description", row));
    auto type_id = this->get<int>("type", row);
    auto module_id = this->get<int>("module", row);
    auto state = static_cast<Task::State> (this->get<int>("state", row));
    auto user = static_cast<std::string> (this->get<char *>("user", row));
    auto date = static_cast<std::string> (this->get<char *>("date", row));

    // Task creation from interpreted data
    Module module = this->m_data_store->getModuleById(module_id);
    std::vector<ProcessingType> types = module.getProcessingTypesList();
    ProcessingType type = types[type_id];
    Task task(id, name, description, type, module, state, user, date);
    return task;
}

}  // namespace firefly
