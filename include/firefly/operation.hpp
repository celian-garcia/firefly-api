// Copyright 2017 <Célian Garcia>
#ifndef INCLUDE_FIREFLY_OPERATION_HPP_
#define INCLUDE_FIREFLY_OPERATION_HPP_
#include <opencv2/core.hpp>

namespace firefly {
enum class OperationType {ADD, REMOVE, END};

class Operation  {
 public:
    Operation(
        OperationType type,
        double x, double y, double z)
        : m_type(type), m_x(x), m_y(y), m_z(z)
    {}
    Operation(
        OperationType type,
        cv::Vec3f vec)
        : m_type(type), m_x(vec[0]), m_y(vec[1]), m_z(vec[2])
    {}

    double getX() const {return this->m_x;}
    double getY() const {return this->m_y;}
    double getZ() const {return this->m_z;}
    OperationType getType() const {return this->m_type;}

 private:
    OperationType m_type;
    double m_x;
    double m_y;
    double m_z;
};
}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_OPERATION_HPP_
