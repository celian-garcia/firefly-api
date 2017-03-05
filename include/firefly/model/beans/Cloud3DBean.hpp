// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_BEANS_CLOUD3DBEAN_HPP_
#define INCLUDE_FIREFLY_MODEL_BEANS_CLOUD3DBEAN_HPP_
#include <string>

namespace firefly {
namespace model {

class Cloud3DBean {
 public:
    explicit Cloud3DBean(int id, std::string state);
    explicit Cloud3DBean(std::string state);
    Cloud3DBean() = default;

    int const& getId() const;
    std::string const& getState() const;
    void setState(const std::string& state);

 private:
    int m_id = 0;
    std::string m_state = "STARTED";
};

}  // namespace model
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_BEANS_CLOUD3DBEAN_HPP_
