// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_OPERATIONMODEL_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_OPERATIONMODEL_HPP_

#include <vector>
#include <firefly/core/model/interpreters/OperationInterpreter.hpp>
#include "DatabaseManager.hpp"

namespace firefly {
class OperationModel : public BaseModel {
 public:
    using BaseModel::BaseModel;

    std::vector<Operation> getOperationsSince(int task_id, int last_operation);
};
}  // namespace firefly

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_OPERATIONMODEL_HPP_
