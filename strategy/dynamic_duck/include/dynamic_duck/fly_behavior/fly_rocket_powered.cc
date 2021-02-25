//
// Created by cosge on 2021-02-09.
//

#include <iostream>

#include "dynamic_duck/fly_behavior/fly_rocket_powered.h"

namespace strategy {
namespace dynamic_duck{

void FlyRocketPowered::fly() const {
  std::cout << "Fly rocket powered" << std::endl;
}

} // namespace dynamic_duck
} // namespace strategy