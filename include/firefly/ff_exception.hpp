// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_FF_EXCEPTION_HPP_
#define INCLUDE_FIREFLY_FF_EXCEPTION_HPP_
#include <iostream>
#include <exception>

namespace firefly {
class ff_exception: public std::exception {
 public:
  virtual const char* what() const throw() {
    return "Firefly Exception";
  }
};
}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_FF_EXCEPTION_HPP_
