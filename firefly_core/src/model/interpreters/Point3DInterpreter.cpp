// Copyright 2017 <Célian Garcia>

#include <firefly/core/model/interpreters/Point3DInterpreter.hpp>

namespace firefly {

Point3DInterpreter::Point3DInterpreter(PGresult *result) : PGResultInterpreter(result) {
    this->registerProperties(PROPERTIES());
}

Point3DBean
Point3DInterpreter::getPoint3D(int row) {
    // Interpretation of the given row
    auto id = this->get<int>("id", row);
    auto task_id = this->get<int>("task_id", row);
    auto value = this->get<cv::Vec3f>("value", row);
    auto operations = this->get<std::vector<int>>("operations", row);

    // Point creation from interpreted data
    Point3DBean point(id, value, task_id, operations);

    return point;
}

const std::vector<const char *>
Point3DInterpreter::PROPERTIES() {
    return {"id", "task_id", "value", "operations"};
}

}  // namespace firefly
