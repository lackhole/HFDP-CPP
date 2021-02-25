//
// Created by cosge on 2021-02-09.
//

#include "dynamic_duck/quack_behavior/quack.h"

#include <iostream>

namespace strategy{
namespace dynamic_duck{

void Quack::quack() const {
  std::cout << "Quack" << std::endl;
}

} // namespace dynamic_duck
} // namespace strategy