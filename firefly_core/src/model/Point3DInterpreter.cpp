//
// Created by root on 14/10/17.
//

#include "firefly/core/model/Point3DInterpreter.hpp"

namespace firefly {
    namespace fly_module {
        Point3DInterpreter::Point3DInterpreter(PGresult *result) {
            this->interpreter = new PGResultInterpreter(result);
            this->interpreter->registerProperties(PROPERTIES());
        }

        Point3DInterpreter::~Point3DInterpreter() {
            delete this->interpreter;
        }

        Point3DBean
        Point3DInterpreter::getPoint3D(int row) {
            // Interpretation of the given row
            auto id = this->interpreter->get<int>("id", row);
            auto task_id = this->interpreter->get<int>("task_id", row);
            auto value = this->interpreter->get<cv::Vec3f>("value", row);
            auto operations = this->interpreter->get<std::vector<int>>("operations", row);

            // Point creation from interpreted data
            Point3DBean point(id, value, task_id, operations);

            return point;
        }

        int
        Point3DInterpreter::get_row_number() {
            return this->interpreter->get_row_number();
        }

        const std::vector<const char *>
        Point3DInterpreter::PROPERTIES() {
            return {"id", "task_id", "value", "operations"};
        }
    }
}
