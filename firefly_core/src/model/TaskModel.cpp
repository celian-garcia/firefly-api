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

    std::vector<Task> TaskModel::getTasks() {
        std::string query = "SELECT * FROM task";
        PGresult *res = this->m_dbmanager->execSelectQuery(query.c_str());
        int nb_rows = PQntuples(res);
        int i_col_id = PQfnumber(res, "id");
        int i_col_name = PQfnumber(res, "name");
        int i_col_description = PQfnumber(res, "description");
        int i_col_type = PQfnumber(res, "type");
        int i_col_module = PQfnumber(res, "module");
        int i_col_state = PQfnumber(res, "state");
        int i_col_user = PQfnumber(res, "\"user\"");
        int i_col_date = PQfnumber(res, "date");
        std::vector <Task> tasks_list;
        std::vector<Module> modules = this->data_store.getModules();
        for (int row = 0; row < nb_rows; row++) {
            int id = atoi(PQgetvalue(res, row, i_col_id));
            std::string name = PQgetvalue(res, row, i_col_name);
            std::string description = PQgetvalue(res, row, i_col_description);
            int type_id = atoi(PQgetvalue(res, row, i_col_type));
            int module_id = atoi(PQgetvalue(res, row, i_col_module));
            Task::State state = static_cast<Task::State> (atoi(PQgetvalue(res, row, i_col_state)));
            std::string user = PQgetvalue(res, row, i_col_user);
            std::string date = PQgetvalue(res, row, i_col_date);
            Module module = modules[module_id];
            std::vector<ProcessingType> types = module.getProcessingTypesList();
            ProcessingType type = types[type_id];
            Task task(id, name, description, type, module, state, user, date);
            tasks_list.push_back(task);
        }
        return tasks_list;
    }

    TaskModel::TaskModel(DatabaseManager* db_manager, const DataCommonStore & data_store): BaseModel(db_manager){
        this->data_store = data_store;
    }
}
