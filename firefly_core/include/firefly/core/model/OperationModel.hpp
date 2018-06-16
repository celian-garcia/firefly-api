// Copyright 2017 <Célian Garcia>

#pragma once

#include <vector>
#include <firefly/core/model/interpreters/OperationInterpreter.hpp>
#include <firefly/core/data/Operation.hpp>
#include <firefly/core/model/DatabaseManager.hpp>
#include "DatabaseManager.hpp"

namespace firefly {
class OperationModel : public BaseModel {
 public:
    using BaseModel::BaseModel;

    std::vector<Operation> getOperationsSince(int task_id, int last_operation);

    int insertOperation(Operation operation, int cloud_id);
};
}  // namespace firefly

