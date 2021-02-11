//
// Created by cosge on 2021-02-09.
//

#include "dynamic_duck/quack_behavior/quack.h"

#include <iostream>

void Quack::quack() const {
  std::cout << "Quack" << std::endl;
}
Quack* Quack::clone_impl() const {
  return new Quack(*this);
}
