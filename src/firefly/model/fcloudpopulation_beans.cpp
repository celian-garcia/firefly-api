// Copyright 2017 <Célian Garcia>

#include "firefly/model/fcloudpopulation_beans.hpp"
namespace firefly {
namespace model {

// class FPoint3D {
//  public:
//     explicit FPoint3D(
//         int id, double x, double y, double z, std::vector<int> op_indices);
//     explicit FPoint3D(
//         double x, double y, double z, std::vector<int> op_indices);

//     int getId();
//     double getX();
//     double getY();
//     double getZ();
//     std::vector<int> getOperationsIndices();
//     void setX(double x);
//     void setY(double y);
//     void setZ(double z);
//     void setOperationsIndices(std::vector<int> op_indices);

//  private:
//     int m_id;
//     double m_x;
//     double m_y;
//     double m_z;
//     std::vector<int> m_op_indices;
// };

FCloud3D::FCloud3D(int id, std::string state)
    : m_id(id), m_state(state) {}
FCloud3D::FCloud3D(std::string state)
    : m_state(state) {}

int
FCloud3D::getId() {
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
