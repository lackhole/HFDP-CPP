//
// Created by cosge on 2021-02-09.
//

#include <iostream>

#include "dynamic_duck/fly_behavior/fly_no_way.h"

namespace strategy{
namespace dynamic_duck{

void FlyNoWay::fly() const {
  std::cout << "I can't fly" << std::endl;
}

} // namespace dynamic_duck
} // namespace strategy