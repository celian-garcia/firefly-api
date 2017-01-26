// Copyright 2017 <Célian Garcia>

#include "firefly/model/fcloudpopulation_beans.hpp"
namespace firefly {
namespace model {

FPoint3D::FPoint3D(int id, cv::Vec3f value,
    int cloud_id, std::vector<int> operations_ids)
    : m_id(id), m_value(value),
    m_cloud_id(cloud_id), m_operations_ids(operations_ids) {}

FPoint3D::FPoint3D(cv::Vec3f value,
    int cloud_id, std::vector<int> operations_ids)
    : m_value(value),
    m_cloud_id(cloud_id), m_operations_ids(operations_ids) {}

int const&
FPoint3D::getId() const {
    return this->m_id;
}

cv::Vec3f const&
FPoint3D::getValue() const {
    return this->m_value;
}

int const&
FPoint3D::getCloudId() const {
    return this->m_cloud_id;
}

std::vector<int> const &
FPoint3D::getOperationsIds() const {
    return this->m_operations_ids;
}

void
FPoint3D::setValue(const cv::Vec3f& value) {
    this->m_value = value;
}

void
FPoint3D::setOperations_ids(const std::vector<int>& operations_ids) {
    this->m_operations_ids = operations_ids;
}

void
FPoint3D::setCloudId(const int& cloud_id) {
    this->m_cloud_id = cloud_id;
}

void
FPoint3D::addOperationId(const int& operation_id) {
    this->m_operations_ids.push_back(operation_id);
}



FCloud3D::FCloud3D(int id, std::string state)
    : m_id(id), m_state(state) {}

FCloud3D::FCloud3D(std::string state)
    : m_state(state) {}

int const&
FCloud3D::getId() const {
    return this->m_id;
}

std::string const&
FCloud3D::getState() const {
    return this->m_state;
}

void
FCloud3D::setState(const std::string& state) {
    this->m_state = state;
}

}  // namespace model
}  // namespace firefly
