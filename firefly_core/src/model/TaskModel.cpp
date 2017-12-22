// Copyright 2017 <Célian Garcia>

#include "firefly/core/model/TaskModel.hpp"

namespace firefly {

Task TaskModel::insertTask(const Task &task) {
    std::string insert_query =
            "INSERT INTO task (name, description, type, module, state, \"user\", date) VALUES (" +
            this->m_dbmanager->format(task.getName()) + ", " +
            this->m_dbmanager->format(task.getDescription()) + ", " +
            this->m_dbmanager->format(task.getType().getId()) + ", " +
            this->m_dbmanager->format(task.getModule().getId()) + ", " +
            this->m_dbmanager->format(task.getState()) + ", " +
            this->m_dbmanager->format(task.getUserName()) + ", " +
            this->m_dbmanager->format(task.getDate()) + ")";
    std::string select_query =
            "SELECT max(id) FROM task";

    // TODO(Célian) : Danger if an insert command is run asynchronously
    // between the two following lines....
    this->m_dbmanager->execInsertQuery(insert_query);
    PGresult *res = this->m_dbmanager->execSelectQuery(select_query);

    int task_id = atoi(PQgetvalue(res, 0, 0));
    m_dbmanager->clearResult(res);
    Task result_task(task);
    result_task.setIdentifier(task_id);
    return result_task;
}

void
TaskModel::updateTaskStateById(int task_id, const Task::State &state) {
    std::stringstream update_query;
    update_query << "UPDATE task SET " <<
                 "state = " << this->m_dbmanager->format(state) << " "
                         "WHERE id = " << this->m_dbmanager->format(task_id) << ";";
    this->m_dbmanager->execUpdateQuery(update_query.str());
}

std::vector<Task> TaskModel::getTasks() {
    // Request
    std::string query = "SELECT * FROM task;";
    PGresult *res = this->m_dbmanager->execSelectQuery(query);

    // Initialize interpreter
    TaskInterpreter interpreter(res, &this->data_store);

    // Get the task list
    std::vector<Task> tasks_list;
    for (int row = 0; row < interpreter.get_row_number(); row++) {
        // Get the task from row
        tasks_list.push_back(interpreter.getTask(row));
    }
    return tasks_list;
}

std::optional<Task> TaskModel::getTaskById(int id) {
    // Request
    std::string query = "SELECT * FROM task WHERE id = " + this->m_dbmanager->format(id) + ";";
    PGresult *res = this->m_dbmanager->execSelectQuery(query);
    TaskInterpreter interpreter(res, &this->data_store);
    if (interpreter.get_row_number() == 0) {
        return {};
    }
    return std::optional < Task > {interpreter.getTask(0)};
}

TaskModel::TaskModel(DatabaseManager *db_manager, const DataCommonStore &data_store) : BaseModel(db_manager) {
    this->data_store = data_store;
}

}  // namespace firefly
