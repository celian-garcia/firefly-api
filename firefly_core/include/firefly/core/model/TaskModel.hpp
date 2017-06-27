// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_TASKMODEL_HPP
#define FIREFLY_TASKMODEL_HPP

#include <firefly/core/config/DataCommonStore.hpp>
#include "firefly/core/data/Task.hpp"
#include "DatabaseManager.hpp"

namespace firefly {
    class TaskModel : public BaseModel {
    public:
        using BaseModel::BaseModel;

        TaskModel(DatabaseManager*, const DataCommonStore&);
//        Task getTaskById(int id);
//
        Task insertTask(const Task &task);
//
//        void updateTask(const Task &task);
        std::vector<Task> getTasks();
    private:
        DataCommonStore data_store;
    };

}

#endif //FIREFLY_TASKMODEL_HPP
