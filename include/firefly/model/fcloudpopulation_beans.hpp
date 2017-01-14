// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_FCLOUDPOPULATION_BEANS_HPP_
#define INCLUDE_FIREFLY_MODEL_FCLOUDPOPULATION_BEANS_HPP_
#include <string>
#include <vector>
#include <opencv2/core.hpp>

namespace firefly {
namespace model {

class FPoint3D {
 public:
    explicit FPoint3D(int id, cv::Vec3f value,
        int cloud_id, std::vector<int> operations);

    explicit FPoint3D(cv::Vec3f value,
        int cloud_id, std::vector<int> operations);

    int const& getId() const;
    cv::Vec3f const& getValue() const;
    int const& getCloudId() const;
    std::vector<int> const& getOperations() const;
    void setValue(const cv::Vec3f& value);
    void setOperations(const std::vector<int>& operations);
    void setCloudId(const int& cloud_id);
    void addOperation(const int& operation);

 private:
    int m_id = 0;
    cv::Vec3f m_value;
    int m_cloud_id;
    std::vector<int> m_operations;
};

class FCloud3D {
 public:
    explicit FCloud3D(int id, std::string state);
    explicit FCloud3D(std::string state);
    FCloud3D() = default;

    int const& getId() const;
    std::string const& getState() const;
    void setState(const std::string& state);

 private:
    int m_id = 0;
    std::string m_state = "STARTED";
};

}  // namespace model
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_FCLOUDPOPULATION_BEANS_HPP_
