// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_FCLOUDPOPULATION_BEANS_HPP_
#define INCLUDE_FIREFLY_MODEL_FCLOUDPOPULATION_BEANS_HPP_
#include <string>
#include <vector>

namespace firefly {
namespace model {

class FPoint3D {
 public:
    explicit FPoint3D(
        int id, double x, double y, double z, std::vector<int> op_indices);
    explicit FPoint3D(
        double x, double y, double z, std::vector<int> op_indices);

    int getId();
    double getX();
    double getY();
    double getZ();
    std::vector<int> getOperationsIndices();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setOperationsIndices(std::vector<int> op_indices);

 private:
    int m_id;
    double m_x;
    double m_y;
    double m_z;
    std::vector<int> m_op_indices;
};

class FCloud3D {
 public:
    explicit FCloud3D(int id, std::string state);
    explicit FCloud3D(std::string state);
    FCloud3D() = default;

    int getId();
    std::string const& getState() const;
    void setState(const std::string& state);

 private:
    // will raise an error from the database because the column is NOT NULL
    int m_id = 0;
    std::string m_state = "STARTED";
};

}  // namespace model
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_FCLOUDPOPULATION_BEANS_HPP_
