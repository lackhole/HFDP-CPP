//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_HPP
#define STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_HPP

#include "dynamic_duck/quack_behavior/quack_behavior.hpp"

class Quack : public QuackBehavior {
 public:
  void quack() const override;
};


#endif //STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_HPP
