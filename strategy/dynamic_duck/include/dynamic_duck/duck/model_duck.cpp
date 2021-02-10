//
// Created by cosge on 2021-02-09.
//

#include <iostream>
#include <memory>
#include "dynamic_duck/duck/model_duck.hpp"
#include "dynamic_duck/fly_behavior/fly_no_way.hpp"
#include "dynamic_duck/quack_behavior/quack.hpp"

ModelDuck::ModelDuck() {
  flyBehavior = std::make_unique<FlyNoWay>();
  quackBehavior = std::make_unique<Quack>();
}

ModelDuck::~ModelDuck() {}

void ModelDuck::display() {
  std::cout << "I am a model duck" << std::endl;
}