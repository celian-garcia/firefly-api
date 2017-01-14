// Copyright 2017 <Célian Garcia>
#ifndef INCLUDE_FIREFLY_OPERATION_HPP_
#define INCLUDE_FIREFLY_OPERATION_HPP_
#include <opencv2/core.hpp>

namespace firefly {
enum class OperationType {ADD, REMOVE, END};

class Operation  {
 public:
    Operation(OperationType type, cv::Vec3f value)
        : m_type(type), m_value(value) {}

    cv::Vec3f getValue() const {return this->m_value;}
    OperationType getType() const {return this->m_type;}

 private:
    OperationType m_type;
    cv::Vec3f m_value;
};
}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_OPERATION_HPP_
