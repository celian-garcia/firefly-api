// Copyright 2017 <Célian Garcia>

#pragma once

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

