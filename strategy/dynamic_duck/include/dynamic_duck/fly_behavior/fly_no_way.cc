//
// Created by cosge on 2021-02-09.
//

#include <iostream>

#include "dynamic_duck/fly_behavior/fly_no_way.h"

void FlyNoWay::fly() const {
  std::cout << "I can't fly" << std::endl;
}

FlyNoWay* FlyNoWay::clone_impl() const {
  return new FlyNoWay(*this);
}
