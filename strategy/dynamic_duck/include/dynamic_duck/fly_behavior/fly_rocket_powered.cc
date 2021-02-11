//
// Created by cosge on 2021-02-09.
//

#include <iostream>

#include "dynamic_duck/fly_behavior/fly_rocket_powered.h"

void FlyRocketPowered::fly() const {
  std::cout << "Fly rocket powered" << std::endl;
}
FlyRocketPowered* FlyRocketPowered::clone_impl() const {
  return new FlyRocketPowered(*this);
}
