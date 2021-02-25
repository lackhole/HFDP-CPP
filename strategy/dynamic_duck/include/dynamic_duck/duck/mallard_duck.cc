//
// Created by cosge on 2021-02-09.
//

#include "dynamic_duck/duck/mallard_duck.h"

#include <iostream>
#include <memory>

#include "dynamic_duck/quack_behavior/quack.h"
#include "dynamic_duck/fly_behavior/fly_with_wings.h"

namespace strategy{
namespace dynamic_duck{

MallardDuck::MallardDuck() {
  quackBehavior = std::make_unique<Quack>();
  flyBehavior = std::make_unique<FlyWithWings>();
}

void MallardDuck::display() {
  std::cout << "I am mallard duck" << std::endl;
}

} // namespace dynamic_duck
} // namespace strategy
