//
// Created by root on 14/10/17.
//

#include "fly_module/model/Point3DInterpreter.hpp"

firefly::fly_module::Point3DInterpreter::Point3DInterpreter(PGresult *result) {
    this->interpreter = new PGResultInterpreter(result);
    this->interpreter->registerProperties(PROPERTIES());
}

firefly::fly_module::Point3DInterpreter::~Point3DInterpreter() {
    delete this->interpreter;
}

firefly::fly_module::Point3DBean firefly::fly_module::Point3DInterpreter::getPoint3D(int row) {
    // Interpretation of the given row
    auto id = this->interpreter->get<int>("id", row);
    auto cloud_id = this->interpreter->get<int>("cloud_id", row);
    auto value = this->interpreter->get<cv::Vec3f>("value", row);
    auto operations = this->interpreter->get<std::vector<int>>("operations", row);

    // Point creation from interpreted data
    Point3DBean point(id, value, cloud_id, operations);

    return point;
}

int firefly::fly_module::Point3DInterpreter::get_row_number() {
    return this->interpreter->get_row_number();
}

const std::vector<const char *> firefly::fly_module::Point3DInterpreter::PROPERTIES() {
    return {"id", "cloud_id", "value", "operations"};
}
