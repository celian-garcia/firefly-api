// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_TASKMODEL_HPP
#define FIREFLY_TASKMODEL_HPP

#include <firefly/core/config/DataCommonStore.hpp>
#include "firefly/core/data/Task.hpp"
#include "DatabaseManager.hpp"
#include <firefly/core/model/PGResultInterpreter.hpp>
#include <firefly/core/model/TaskInterpreter.hpp>
#include <optional>

namespace firefly {
    class TaskModel : public BaseModel {
    public:
        using BaseModel::BaseModel;

        TaskModel(DatabaseManager*, const DataCommonStore&);

        Task insertTask(const Task &task);

        void updateTaskStateById(int task_id, const Task::State& state);

        std::vector<Task> getTasks();

        std::optional<Task> getTaskById(int task_id);

    private:
        DataCommonStore data_store;
    };

}

#endif //FIREFLY_TASKMODEL_HPP
