// Copyright 2017 <Célian Garcia>
#include "firefly/modules/fly/model/beans/Point3DBean.hpp"

namespace firefly {
    namespace module_fly {
        Point3DBean::Point3DBean(int id, cv::Vec3f value,
                                 int cloud_id, std::vector<int> operations_ids)
                : m_id(id), m_value(value),
                  m_cloud_id(cloud_id), m_operations_ids(operations_ids) {}

        Point3DBean::Point3DBean(cv::Vec3f value,
                                 int cloud_id, std::vector<int> operations_ids)
                : m_value(value),
                  m_cloud_id(cloud_id), m_operations_ids(operations_ids) {}

        int const &
        Point3DBean::getId() const {
            return this->m_id;
        }

        cv::Vec3f const &
        Point3DBean::getValue() const {
            return this->m_value;
        }

        int const &
        Point3DBean::getCloudId() const {
            return this->m_cloud_id;
        }

        std::vector<int> const &
        Point3DBean::getOperationsIds() const {
            return this->m_operations_ids;
        }

        void
        Point3DBean::setValue(const cv::Vec3f &value) {
            this->m_value = value;
        }

        void
        Point3DBean::setOperationsIds(const std::vector<int> &operations_ids) {
            this->m_operations_ids = operations_ids;
        }

        void
        Point3DBean::setCloudId(const int &cloud_id) {
            this->m_cloud_id = cloud_id;
        }

        void
        Point3DBean::addOperationId(const int &operation_id) {
            this->m_operations_ids.push_back(operation_id);
        }
    }
}
