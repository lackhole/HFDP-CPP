//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_H_
#define STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_H_

#include "dynamic_duck/interface/cloneable.h"

class QuackBehavior : public Cloneable<QuackBehavior> {
 public:
  virtual ~QuackBehavior() = default;
  virtual void quack() const = 0;
};


#endif //STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_H_
