//
// Created by cosge on 2021-02-09.
//

#include "dynamic_duck/quack_behavior/squeak.h"

#include <iostream>

void Squeak::quack() const {
  std::cout << "Squeak" << std::endl;
}

Squeak* Squeak::clone_impl() const {
  return new Squeak(*this);
}
