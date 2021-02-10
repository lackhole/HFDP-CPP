//
// Created by cosge on 2021-02-09.
//

#include "dynamic_duck/duck/model_duck.h"

#include <iostream>
#include <memory>

#include "dynamic_duck/fly_behavior/fly_no_way.h"
#include "dynamic_duck/quack_behavior/quack.h"

ModelDuck::ModelDuck() {
  flyBehavior = std::make_unique<FlyNoWay>();
  quackBehavior = std::make_unique<Quack>();
}

void ModelDuck::display() {
  std::cout << "I am a model duck" << std::endl;
}