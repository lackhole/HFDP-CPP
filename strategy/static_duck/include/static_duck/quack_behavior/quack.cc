//
// Created by cosge on 2021-02-25.
//
#include "static_duck/quack_behavior/quack.h"

#include <iostream>

namespace strategy {
namespace static_duck{

void Quack::quack() const {
  std::cout << "Quack" << std::endl;
};

} // namespace static_duck
} // namespace strategy