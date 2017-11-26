//
// Created by celian on 26/11/17.
//

#ifndef FIREFLY_OPERATIONMODEL_H
#define FIREFLY_OPERATIONMODEL_H

#include <vector>
#include "DatabaseManager.hpp"

namespace firefly {
class OperationModel : public BaseModel {
 public:
    using BaseModel::BaseModel;

    std::vector<Operation> getOperationsSince(int task_id, int last_operation);
};
}

#endif //FIREFLY_OPERATIONMODEL_H
