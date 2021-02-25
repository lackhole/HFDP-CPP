//
// Created by cosge on 2021-02-09.
//

#include "dynamic_duck/quack_behavior/squeak.h"

#include <iostream>

namespace strategy {
namespace dynamic_duck{

void Squeak::quack() const {
  std::cout << "Squeak" << std::endl;
}

} // namespace dynamic_duck
} // namespace strategy