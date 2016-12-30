// Copyright 2017 <Célian Garcia>
#ifndef INCLUDE_FLY_EXTENT_CONCURRENT_CLOUD_HPP_
#define INCLUDE_FLY_EXTENT_CONCURRENT_CLOUD_HPP_
#include <./fly.h>
#include <string>
#include <opencv2/core.hpp>

namespace fly {

class concurrent_cloud : public cloud {
 protected:
    boost::mutex mtx_;
 public:
    virtual void add_point(cv::Vec3f v);
    virtual void remove_point(const std::string& id);
};

}  // end namespace fly
#endif  // INCLUDE_FLY_EXTENT_CONCURRENT_CLOUD_HPP_
