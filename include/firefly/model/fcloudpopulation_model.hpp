// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_FCLOUDPOPULATION_MODEL_HPP_
#define INCLUDE_FIREFLY_MODEL_FCLOUDPOPULATION_MODEL_HPP_
#include <string>
#include <vector>
#include "firefly/model/DatabaseManager.hpp"
#include "firefly/model/fcloudpopulation_beans.hpp"

namespace firefly {
namespace model {

class ObjectNotFound : public std::exception {};
class FCloud3DModel : public BaseModel {
 public:
    using BaseModel::BaseModel;
    FCloud3D getCloudById(int id);
    int insertCloud(const FCloud3D& cloud);
    void updateCloud(const FCloud3D& cloud);
};

class FPoint3DModel : public BaseModel {
    using BaseModel::BaseModel;
 public:
    FPoint3D getPointByValueAndCloudId(cv::Vec3f value, int cloud_id);
    std::vector<FPoint3D> getPointListByCloudId(int cloud_id);
    void insertPoint(FPoint3D point);
    void updatePointOperations(FPoint3D point);

    static constexpr double INTERSECT_MIN_DISTANCE = 0.00001;
};

}  // namespace model
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_FCLOUDPOPULATION_MODEL_HPP_
