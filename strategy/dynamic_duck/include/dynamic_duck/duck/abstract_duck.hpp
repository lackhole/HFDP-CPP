//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_DUCK_ABSTRACT_DUCK_HPP
#define STRATEGY_DYNAMIC_DUCK_DUCK_ABSTRACT_DUCK_HPP

#include <memory>
#include "dynamic_duck/duck_core.hpp"

class AbstractDuck {
 public:
  virtual ~AbstractDuck();

  virtual void display() = 0;
  void performFly() const;
  void performQuack() const;
  void swim() const;

 protected:
  AbstractDuck& operator = (const AbstractDuck& rhs);

  std::unique_ptr<FlyBehavior> flyBehavior;
  std::unique_ptr<QuackBehavior> quackBehavior;
};


#endif //STRATEGY_DYNAMIC_DUCK_DUCK_ABSTRACT_DUCK_HPP
