// Copyright 2018 <Célian Garcia>

#pragma once

#include <stdint.h>
#include <boost/filesystem.hpp>

namespace firefly {

struct ServerConfig {
    int16_t port;
    int16_t threads_count;
    boost::filesystem::path resources_path;
};

}  // namespace firefly