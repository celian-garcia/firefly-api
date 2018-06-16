// Copyright 2017 <Célian Garcia>

#pragma once

#include <ml.h>  // opencv import
#include <string>
#include <json/json.hpp>

namespace firefly {

class OperationElement {
 public:
    OperationElement(int id, const std::string &type, const cv::Vec3f &value) : id(id), type(type), value(value) {}

    OperationElement(const std::string &type, const cv::Vec3f &value) : type(type), value(value) {}

    int getId() const {
        return id;
    }

    const std::string &getType() const {
        return type;
    }

    const cv::Vec3f &getValue() const {
        return value;
    }

 private:
    int id;
    std::string type;
    cv::Vec3f value;
};

}  // namespace firefly

namespace nlohmann {

template<>
struct __attribute__((unused)) adl_serializer<cv::Vec3f> {
    static void __attribute__((unused)) to_json(json &j, const cv::Vec3f &v) {
        j = json{{"x", v[0]},
                 {"y", v[1]},
                 {"z", v[2]}};
    }
};

template<>
struct __attribute__((unused)) adl_serializer<firefly::OperationElement> {
    static void __attribute__((unused)) to_json(json &j, const firefly::OperationElement &operation) {
        j = json{{"id",    operation.getId()},
                 {"type",  operation.getType()},
                 {"value", operation.getValue()}};
    }
};

}  // namespace nlohmann

