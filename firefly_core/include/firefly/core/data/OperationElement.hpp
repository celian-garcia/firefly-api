//
// Created by celian on 02/12/17.
//

#ifndef FIREFLY_OPERATIONELEMENT_H
#define FIREFLY_OPERATIONELEMENT_H

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
        std::string x_key = "x";
        std::string y_key = "y";
        std::string z_key = "z";
        j = json{{x_key, v[0]},
                 {y_key, v[1]},
                 {z_key, v[2]}};
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
#endif //FIREFLY_OPERATIONELEMENT_H
