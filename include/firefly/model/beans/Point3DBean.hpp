// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_BEANS_POINT3DBEAN_HPP_
#define INCLUDE_FIREFLY_MODEL_BEANS_POINT3DBEAN_HPP_
#include <vector>
#include <opencv2/opencv.hpp>

namespace firefly {
namespace model {

class Point3DBean {
 public:
    explicit Point3DBean(int id, cv::Vec3f value,
        int cloud_id, std::vector<int> operations_ids);

    explicit Point3DBean(cv::Vec3f value,
        int cloud_id, std::vector<int> operations_ids);

    int const& getId() const;
    cv::Vec3f const& getValue() const;
    int const& getCloudId() const;
    std::vector<int> const& getOperationsIds() const;
    void setValue(const cv::Vec3f& value);
    void setOperationsIds(const std::vector<int>& operations_ids);
    void setCloudId(const int& cloud_id);
    void addOperationId(const int& operation_id);

 private:
    int m_id = 0;
    cv::Vec3f m_value;
    int m_cloud_id;
    std::vector<int> m_operations_ids;
};

}  // namespace model
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_BEANS_POINT3DBEAN_HPP_
