// Copyright 2017 <Célian Garcia>

#include "firefly/core/model/TaskModel.hpp"
namespace firefly {
//    Task
//    TaskModel::getTaskById(int id) {
//        std::string query =
//                "SELECT * FROM task WHERE id = " + this->m_dbmanager->format(id);
//        PGresult *res = this->m_dbmanager->execSelectQuery(query.c_str());
//        std::string state = PQgetvalue(res, 0, 1);
//        return NULL;
//    }

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
        this->m_dbmanager->execInsertQuery(insert_query.c_str());
        PGresult *res = this->m_dbmanager->execSelectQuery(select_query.c_str());

        int task_id = atoi(PQgetvalue(res, 0, 0));
        m_dbmanager->clearResult(res);
        Task result_task(task);
        result_task.setIdentifier(task_id);
        return result_task;
    }
}
