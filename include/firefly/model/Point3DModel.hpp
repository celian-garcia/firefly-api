// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_POINT3DMODEL_HPP_
#define INCLUDE_FIREFLY_MODEL_POINT3DMODEL_HPP_

#include <vector>
#include <string>
#include "firefly/model/beans/Point3DBean.hpp"
#include "firefly/model/DatabaseManager.hpp"

namespace firefly {
namespace model {

class Point3DModel : public BaseModel {
 public:
    using BaseModel::BaseModel;
    Point3DBean getPointByValueAndCloudId(cv::Vec3f value, int cloud_id);
    std::vector<Point3DBean> getPointListByCloudId(int cloud_id);
    void insertPoint(Point3DBean point);
    void updatePointOperations(Point3DBean point);

    static constexpr double INTERSECT_MIN_DISTANCE = 0.00001;
};

}  // namespace model
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_POINT3DMODEL_HPP_
