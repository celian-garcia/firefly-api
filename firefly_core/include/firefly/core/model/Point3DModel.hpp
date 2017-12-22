// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_POINT3DMODEL_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_POINT3DMODEL_HPP_

#include <libpqtypes.h>
#include <vector>
#include <string>
#include <firefly/core/data/Operation.hpp>
#include <firefly/core/model/DatabaseManager.hpp>
#include <firefly/core/model/beans/Point3DBean.hpp>
#include <firefly/core/model/interpreters/Point3DInterpreter.hpp>

namespace firefly {

class Point3DModel : public BaseModel {
 public:
    using BaseModel::BaseModel;

    Point3DBean getPointByValueAndTaskId(cv::Vec3f value, int cloud_id);

    std::vector<Point3DBean> getPointListByTaskId(int task_id);

    void insertPoint(Point3DBean point);

    int insertOperation(Operation operation, int cloud_id);

    void updatePoint(Point3DBean point);

    static constexpr double INTERSECT_MIN_DISTANCE = 0.00001;
};

}  // namespace firefly

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_POINT3DMODEL_HPP_
