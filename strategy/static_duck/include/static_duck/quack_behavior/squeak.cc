//
// Created by cosge on 2021-02-25.
//
#include "static_duck/quack_behavior/squeak.h"

#include <iostream>

namespace strategy {
namespace static_duck{

void Squeak::quack() const {
  std::cout << "Squeak" << std::endl;
}

} // namespace static_duck
} // namespace strategy