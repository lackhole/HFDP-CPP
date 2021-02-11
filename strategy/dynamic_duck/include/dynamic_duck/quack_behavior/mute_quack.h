//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_MUTE_QUACK_H_
#define STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_MUTE_QUACK_H_

#include "dynamic_duck/quack_behavior/quack_behavior.h"

class MuteQuack : public QuackBehavior {
 public:
  void quack() const override;

 protected:
  MuteQuack* clone_impl() const override;
};


#endif //STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_MUTE_QUACK_H_
