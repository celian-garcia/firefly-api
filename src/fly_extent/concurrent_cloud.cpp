// Copyright 2017 <Célian Garcia>
#include "fly_extent/concurrent_cloud.hpp"

namespace fly {
// TODO(Célian): see if it is really necessary
using cloud::add_point;
using cloud::remove_point;

void concurrent_cloud::add_point(cv::Vec3f v) {
    boost::lock_guard<boost::mutex> guard(this->mtx_);
    cloud::add_point(v);
}
void concurrent_cloud::remove_point(const std::string& id) {
    boost::lock_guard<boost::mutex> guard(this->mtx_);
    cloud::remove_point(id);
}

}  // end namespace fly
