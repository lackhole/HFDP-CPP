//
// Created by cosge on 2021-02-25.
//
#include "static_duck/fly_behavior/fly_no_way.h"

#include <iostream>

namespace strategy {
namespace static_duck{

void FlyNoWay::fly() const {
  std::cout << "I can't fly!" << std::endl;
}

} // namespace static_duck
} // namespace strategy