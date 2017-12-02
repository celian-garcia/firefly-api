//
// Created by celian on 02/12/17.
//

#ifndef FIREFLY_OPERATIONTYPE_HPP
#define FIREFLY_OPERATIONTYPE_HPP

#include "json/json.hpp"

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

#endif  //FIREFLY_OPERATIONTYPE_HPP
