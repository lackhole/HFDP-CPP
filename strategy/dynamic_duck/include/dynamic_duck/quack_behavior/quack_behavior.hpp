//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_HPP
#define STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_HPP

#include "dynamic_duck/duck_core.hpp"

class QuackBehavior {
 public:
  virtual void quack() const = 0;
};


#endif //STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_HPP
