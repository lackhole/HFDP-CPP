//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_DUCK_ABSTRACT_DUCK_H_
#define STRATEGY_DYNAMIC_DUCK_DUCK_ABSTRACT_DUCK_H_

#include <memory>

#include "dynamic_duck/fly_behavior/fly_behavior.h"
#include "dynamic_duck/quack_behavior/quack_behavior.h"

namespace strategy{
namespace dynamic_duck{

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
  AbstractDuck() = default;
  AbstractDuck(const AbstractDuck& rhs) = default;
  AbstractDuck(AbstractDuck&& rhs) = default;
  AbstractDuck& operator = (const AbstractDuck& rhs) = default;
  AbstractDuck& operator = (AbstractDuck&& rhs) = default;

  std::shared_ptr<FlyBehavior> flyBehavior;
  std::shared_ptr<QuackBehavior> quackBehavior;
};

}} // namespace strategy::dynamic_duck

#endif //STRATEGY_DYNAMIC_DUCK_DUCK_ABSTRACT_DUCK_H_
