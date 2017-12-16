// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_OPERATION_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_OPERATION_HPP_

#include <string>
#include <map>
#include <opencv2/opencv.hpp>
#include <json/json.hpp>
#include "OperationType.hpp"
#include "OperationElement.hpp"

namespace firefly {

class Operation {
 public:
    Operation(int m_id, OperationType m_type, const OperationElement &m_element) : m_id(m_id), m_type(m_type),
                                                                                   m_element(m_element) {}

    Operation(OperationType m_type, const OperationElement &m_element) : m_type(m_type), m_element(m_element) {}

    int getId() const {
        return m_id;
    }

    void setId(int m_id) {
        Operation::m_id = m_id;
    }

    OperationType getType() const {
        return m_type;
    }

    void setType(OperationType m_type) {
        Operation::m_type = m_type;
    }

    const OperationElement &getElement() const {
        return m_element;
    }

    void setElement(const OperationElement &m_element) {
        Operation::m_element = m_element;
    }

 private:
    int m_id = 0;
    OperationType m_type;
    OperationElement m_element;
};

}  // namespace firefly

namespace nlohmann {
template<>
struct __attribute__((unused)) adl_serializer<firefly::Operation> {
    static void __attribute__((unused)) to_json(json &j, const firefly::Operation &operation) {
        j = json{{"id",      operation.getId()},
                 {"type",    operation.getType()},
                 {"element", operation.getElement()}};
    }
};
}  // namespace nlohmann

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_OPERATION_HPP_
