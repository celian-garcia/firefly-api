// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_POINT3DMODEL_HPP_
#define INCLUDE_FIREFLY_MODEL_POINT3DMODEL_HPP_

#include <vector>
#include <string>
#include "firefly/modules/fly/model/beans/Point3DBean.hpp"
#include "firefly/modules/common/model/DatabaseManager.hpp"
#include "firefly/modules/common/model/exceptions.hpp"

namespace firefly {
    namespace module_fly {

        class Point3DModel : public BaseModel {
        public:
            using BaseModel::BaseModel;

            Point3DBean getPointByValueAndCloudId(cv::Vec3f value, int cloud_id);

            std::vector <Point3DBean> getPointListByCloudId(int cloud_id);

            void insertPoint(Point3DBean point);

            void updatePointOperations(Point3DBean point);

            static constexpr double INTERSECT_MIN_DISTANCE = 0.00001;
        };

    }  // namespace module_fly
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_POINT3DMODEL_HPP_
