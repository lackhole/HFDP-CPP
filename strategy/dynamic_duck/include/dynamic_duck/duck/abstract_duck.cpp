//
// Created by cosge on 2021-02-09.
//

#include <memory>
#include <iostream>
#include "dynamic_duck/duck_core.hpp"
#include "abstract_duck.hpp"
#include "dynamic_duck/fly_behavior/fly_behavior.hpp"
#include "dynamic_duck/quack_behavior/quack_behavior.hpp"

AbstractDuck::~AbstractDuck() {}

AbstractDuck &AbstractDuck::operator = (const AbstractDuck &rhs) {
  *flyBehavior = *rhs.flyBehavior;
  *quackBehavior = *rhs.quackBehavior;
  return *this;
}

void AbstractDuck::performFly() const {
  flyBehavior->fly();
}

void AbstractDuck::performQuack() const {
  quackBehavior->quack();
}

void AbstractDuck::swim() const {
  std::cout << "Every duck float on water. Even decoy duck floats." << std::endl;
}

void AbstractDuck::setFlyBehavior(std::unique_ptr<FlyBehavior> fb) {
  flyBehavior = std::move(fb);
}

void AbstractDuck::setQuackBehavior(std::unique_ptr<QuackBehavior> qb) {
  quackBehavior = std::move(qb);
}
