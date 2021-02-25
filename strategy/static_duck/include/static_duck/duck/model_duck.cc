//
// Created by cosge on 2021-02-25.
//
#include "static_duck/duck/model_duck.h"

#include "static_duck/fly_behavior/fly_no_way.h"
#include "static_duck/quack_behavior/quack.h"

#include <iostream>

namespace strategy {
namespace static_duck {

ModelDuck::ModelDuck()
  : AbstractDuck(FlyNoWay{}, Quack{}){}

void ModelDuck::display() const {
  std::cout << "I am a model duck" << std::endl;
}

} // namespace static_duck
} // namespace strategy
