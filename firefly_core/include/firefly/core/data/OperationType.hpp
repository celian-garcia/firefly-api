// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_OPERATIONTYPE_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_OPERATIONTYPE_HPP_

#include <json/json.hpp>

namespace firefly {

enum OperationType {
    ADD, DELETE
};

}  // namespace firefly

namespace nlohmann {
template<>
struct __attribute__((unused)) adl_serializer<firefly::OperationType> {
    static void __attribute__((unused)) to_json(json &j, const firefly::OperationType &operation_type) {
        j = operation_type == firefly::OperationType::ADD ? "add" : "delete";
    }
};
}  // namespace nlohmann

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_OPERATIONTYPE_HPP_
