//
// Created by celian on 26/11/17.
//

#include "firefly/core/model/interpreters/OperationInterpreter.hpp"

namespace firefly {

OperationInterpreter::OperationInterpreter(PGresult *result) {
    this->interpreter = new PGResultInterpreter(result);
    this->interpreter->registerProperties(PROPERTIES());
}

OperationInterpreter::~OperationInterpreter() {
    delete this->interpreter;
}

Operation OperationInterpreter::getOperation(int row) {
    // Interpretation of the given row
    auto id = this->interpreter->get<int>("pt_id", row);
    auto type = OPERATION_TYPES.at(this->interpreter->get<std::string>("op_type", row));
    auto value = this->interpreter->get<cv::Vec3f>("pt_value", row);

    return {id, type, value};
}

int OperationInterpreter::get_row_number() {
    return this->interpreter->get_row_number();
}

const std::vector<const char *> OperationInterpreter::PROPERTIES() {
    return {"pt_id", "op_type", "pt_value"};
}

std::map<std::string, OperationType> OperationInterpreter::OPERATION_TYPES = {
        {"add", OperationType::ADD},
        {"delete", OperationType::DELETE},
        {"nothing", OperationType::NONE}
};

}
