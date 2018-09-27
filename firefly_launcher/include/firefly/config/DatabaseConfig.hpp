// Copyright 2018 <Célian Garcia>

#pragma once

#include <stdint.h>
#include <string>

namespace firefly {

struct DatabaseConfig {
    std::string host;
    int16_t port;
    std::string database;
    std::string user;
    std::string password;
};

}  // namespace firefly

