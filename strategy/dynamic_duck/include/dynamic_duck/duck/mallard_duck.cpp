//
// Created by cosge on 2021-02-09.
//

#include <iostream>
#include <memory>
#include "dynamic_duck/duck/mallard_duck.hpp"
#include "dynamic_duck/quack_behavior/quack.hpp"
#include "dynamic_duck/fly_behavior/fly_with_wings.hpp"

MallardDuck::MallardDuck() {
  AbstractDuck::quackBehavior = std::make_unique<Quack>();
  AbstractDuck::flyBehavior = std::make_unique<FlyWithWings>();
}
MallardDuck::~MallardDuck() {}

void MallardDuck::display() {
  std::cout << "I am mallard duck" << std::endl;
}

