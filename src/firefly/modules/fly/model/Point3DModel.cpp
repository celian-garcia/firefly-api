// Copyright 2017 <Célian Garcia>

#include "firefly/modules/fly/model/Point3DModel.hpp"

namespace firefly {
    namespace module_fly {

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
            int cloud_id_fnum = PQfnumber(res, "cloud_id");
            int value_fnum = PQfnumber(res, "value");
            int operations_fnum = PQfnumber(res, "operations");

            for (int row = 0; row < rows_number; row++) {
                char *id = PQgetvalue(res, row, id_fnum);
                char *cloud_id_char = PQgetvalue(res, row, cloud_id_fnum);
                char *value = PQgetvalue(res, row, value_fnum);
                char *operations = PQgetvalue(res, row, operations_fnum);
                std::cout << std::string(id) << std::endl;
                std::cout << std::string(cloud_id_char) << std::endl;
                std::cout << std::string(value) << std::endl;
                std::cout << std::string(operations) << std::endl;
            }

            return std::vector<Point3DBean>();

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

        void
        Point3DModel::updatePointOperations(Point3DBean point) {
            std::cout << "Point update" << std::endl;
        }
    }
}