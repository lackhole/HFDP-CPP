//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_DUCK_ABSTRACT_DUCK_HPP
#define STRATEGY_DYNAMIC_DUCK_DUCK_ABSTRACT_DUCK_HPP

#include <memory>
#include "dynamic_duck/fly_behavior/fly_behavior.h"
#include "dynamic_duck/quack_behavior/quack_behavior.h"

class AbstractDuck {
 public:
  virtual ~AbstractDuck();

  virtual void display() = 0;
  void performFly() const;
  void performQuack() const;
  void swim() const;

  void setFlyBehavior(std::unique_ptr<FlyBehavior> fb);
  void setQuackBehavior(std::unique_ptr<QuackBehavior> qb);

 protected:
  AbstractDuck& operator = (const AbstractDuck& rhs);
  AbstractDuck& operator = (AbstractDuck&& rhs) = default;

  std::unique_ptr<FlyBehavior> flyBehavior;
  std::unique_ptr<QuackBehavior> quackBehavior;
};


#endif //STRATEGY_DYNAMIC_DUCK_DUCK_ABSTRACT_DUCK_HPP
