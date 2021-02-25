//
// Created by cosge on 2021-02-25.
//
#include "static_duck/fly_behavior/fly_with_wings.h"

#include <iostream>

namespace strategy {
namespace static_duck{

void FlyWithWings::fly() const{
  std::cout << "I'm flying!!" << std::endl;
}

} // namespace static_duck
} // namespace strategy