// Copyright 2017 <Célian Garcia>

#include "fly_module/model/Point3DModel.hpp"

namespace firefly {
    namespace fly_module {

        Point3DBean
        Point3DModel::getPointByValueAndCloudId(cv::Vec3f value, int cloud_id) {
            double min_distance = Point3DModel::INTERSECT_MIN_DISTANCE;
            std::string select_query =
                    "SELECT * FROM fpoint3d WHERE value <-> point " +
                    this->m_dbmanager->format(value) + " < " +
                    this->m_dbmanager->format(min_distance) +
                    " AND cloud_id = " +
                    this->m_dbmanager->format(cloud_id);

            PGresult *res = this->m_dbmanager->execSelectQuery(select_query.c_str());

            if (PQntuples(res) == 0) {
                throw ObjectNotFound();
            }

            // TODO(Célian) : get correctly the point from the database
            // int id_fnum = PQfnumber(res, "id");
            // int cloud_id_fnum = PQfnumber(res, "cloud_id");
            // int value_fnum = PQfnumber(res, "value");
            // int operations_fnum = PQfnumber(res, "operations");
            // int point_id = atoi(PQgetvalue(res, 0, id_fnum));
            // std::cout << PQntuples(res) << std::endl;
            // std::string value = PQgetvalue(res, 0, value_fnum);
            // // std::cout << value << std::endl;
            // std::string operations = PQgetvalue(res, 0, operations_fnum);
            // // std::cout << operations << std::endl;
            // m_dbmanager->clearResult(res);
            return Point3DBean(value, cloud_id, {0});
        }

        std::vector<Point3DBean>
        Point3DModel::getPointListByCloudId(int cloud_id) {
            std::string select_query =
                    "SELECT * FROM fpoint3d WHERE cloud_id = " +
                    this->m_dbmanager->format(cloud_id);

            PGresult *res = this->m_dbmanager->execSelectQuery(select_query.c_str());

            int rows_number = PQntuples(res);
            if (rows_number == 0) {
                throw ObjectNotFound();
            }

            int id_fnum = PQfnumber(res, "id");
            int value_fnum = PQfnumber(res, "value");
            int operations_fnum = PQfnumber(res, "operations");

            std::vector<Point3DBean> points;
            for (int row = 0; row < rows_number; row++) {
                int id = this->m_dbmanager->parse(PQgetvalue(res, row, id_fnum));

                cv::Vec3f value(1, 1, 1);//TODO
                std::vector<int> operations = {4, 5, 6};//TODO
                points.push_back(Point3DBean(id, value, cloud_id, operations));
            }

            return points;

        }

        void
        Point3DModel::insertPoint(Point3DBean point) {
            std::string insert_query =
                    "INSERT INTO fpoint3d (cloud_id, value, operations) VALUES (" +
                    this->m_dbmanager->format(point.getCloudId()) + ", " +
                    this->m_dbmanager->format(point.getValue()) + ", " +
                    this->m_dbmanager->format(point.getOperationsIds()) + ")";

            this->m_dbmanager->execInsertQuery(insert_query.c_str());
        }

        void Point3DModel::updatePoint(Point3DBean point) {
            std::string update_query =
                    "UPDATE fpoint3d SET cloud_id = '" +
                    this->m_dbmanager->format(point.getCloudId()) + "', value = '" +
                    this->m_dbmanager->format(point.getValue()) + "', operations = '" +
                    this->m_dbmanager->format(point.getOperationsIds()) + "' WHERE id = " +
                    this->m_dbmanager->format(point.getId());

            this->m_dbmanager->execUpdateQuery(update_query.c_str());
        }

        void Point3DModel::insertOperation(Operation operation, int cloud_id) {
            if (operation.getType() == OperationType::END) {
                throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, "Internal server error");
            }
            cv::Vec3f operation_value = operation.getValue();

            try {
                Point3DBean point = this->getPointByValueAndCloudId(operation_value, cloud_id);

                // If the size of operations indices is even, the next operation should be an add
                // If the size of operations indices is odd , the next operation should be a remove
                // With this type of storing, we don't need to store the ADD or REMOVE flag.
                // So we can store another thing in place: the total index of the operation,
                // which is much more useful in the listen part.
                OperationType operation_type = operation.getType();
                std::vector<int> operation_indices = point.getOperationsIds();
                if ((operation_indices.size() % 2 == 0 && operation_type == OperationType::ADD) ||
                    (operation_indices.size() % 2 == 1 && operation_type == OperationType::REMOVE)) {
                    point.addOperationId(operation.getId());
                    this->updatePoint(point);
                }
            } catch (ObjectNotFound e) {
                Point3DBean new_point(operation_value, cloud_id, {operation.getId()});
                this->insertPoint(new_point);
            }
        }
    }
}