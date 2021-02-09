//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_MUTE_QUACK_HPP
#define STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_MUTE_QUACK_HPP

#include "quack_behavior.hpp"

class MuteQuack : public QuackBehavior {
 public:
  void quack() const override;
};


#endif //STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_MUTE_QUACK_HPP
