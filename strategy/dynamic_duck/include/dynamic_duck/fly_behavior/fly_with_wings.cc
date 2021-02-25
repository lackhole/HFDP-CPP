//
// Created by cosge on 2021-02-09.
//

#include <iostream>

#include "dynamic_duck/fly_behavior/fly_with_wings.h"

namespace strategy{
namespace dynamic_duck{

void FlyWithWings::fly() const {
  std::cout << "I'm flying!!" << std::endl;
}

} // namespace dynamic_duck
} // namespace strategy