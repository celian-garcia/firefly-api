// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_CLOUD3DMODEL_HPP_
#define INCLUDE_FIREFLY_MODEL_CLOUD3DMODEL_HPP_

#include <string>
#include "firefly/model/beans/Cloud3DBean.hpp"
#include "firefly/model/DatabaseManager.hpp"

namespace firefly {
namespace model {

class Cloud3DModel : public BaseModel {
 public:
    using BaseModel::BaseModel;
    Cloud3DBean getCloudById(int id);
    int insertCloud(const Cloud3DBean& cloud);
    void updateCloud(const Cloud3DBean& cloud);
};

}  // namespace model
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_CLOUD3DMODEL_HPP_
