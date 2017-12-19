// Copyright 2017 <Célian Garcia>

#include "firefly/core/model/interpreters/OperationInterpreter.hpp"

namespace firefly {

OperationInterpreter::OperationInterpreter(PGresult *result) : PGResultInterpreter(result) {
    this->registerProperties(PROPERTIES());
}

Operation OperationInterpreter::getOperation(int row) {
    // Interpretation of the given row
    auto operation_id = this->get<int>("operation_id", row);
    auto operation_type = OPERATION_TYPES.at(this->get<std::string>("operation_type", row));
    auto point_id = this->get<int>("point_id", row);
    auto point_value = this->get<cv::Vec3f>("point_value", row);

    // For the moment we handle uniquely points but in the future the type should be dynamically retrieved
    return {operation_id, operation_type, {point_id, "fpoint3d", point_value}};
}

const std::vector<const char *> OperationInterpreter::PROPERTIES() {
    return {"operation_id", "point_id", "operation_type", "point_value"};
}

std::map<std::string, OperationType> OperationInterpreter::OPERATION_TYPES = {
        {"add",    OperationType::ADD},
        {"delete", OperationType::DELETE}
};

}  // namespace firefly
