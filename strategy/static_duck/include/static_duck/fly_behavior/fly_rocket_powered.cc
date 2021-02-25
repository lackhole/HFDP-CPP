//
// Created by cosge on 2021-02-25.
//

#include "static_duck/fly_behavior/fly_rocket_powered.h"

#include <iostream>

namespace strategy {
namespace static_duck{

void FlyRocketPowered::fly() const {
  std::cout << "Fly rocket powered" << std::endl;
}

} // namespace static_duck
} // namespace strategy