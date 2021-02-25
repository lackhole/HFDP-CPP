//
// Created by cosge on 2021-02-25.
//
#include "static_duck/duck/mallard_duck.h"

#include "static_duck/fly_behavior/fly_with_wings.h"
#include "static_duck/quack_behavior/quack.h"

#include <iostream>

namespace strategy {
namespace static_duck {

MallardDuck::MallardDuck()
  : AbstractDuck(FlyWithWings{}, Quack{}) {}

void MallardDuck::display() const {
  std::cout << "I am mallard duck" << std::endl;
}

} // namespace static_duck
} // namespace strategy