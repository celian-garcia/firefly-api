// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_TASKMODEL_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_TASKMODEL_HPP_

#include <optional>
#include <vector>
#include <firefly/core/model/interpreters/PGResultInterpreter.hpp>
#include <firefly/core/config/DataCommonStore.hpp>
#include <firefly/core/data/Task.hpp>
#include <firefly/core/model/interpreters/TaskInterpreter.hpp>
#include "DatabaseManager.hpp"

namespace firefly {
class TaskModel : public BaseModel {
 public:
    using BaseModel::BaseModel;

    TaskModel(DatabaseManager *, const DataCommonStore &);

    Task insertTask(const Task &task);

    void updateTaskStateById(int task_id, const Task::State &state);

    std::vector<Task> getTasks();

    std::optional<Task> getTaskById(int task_id);

    std::vector<Task> clearAllTasks();

 private:
    DataCommonStore data_store;
};

}  // namespace firefly

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_TASKMODEL_HPP_
