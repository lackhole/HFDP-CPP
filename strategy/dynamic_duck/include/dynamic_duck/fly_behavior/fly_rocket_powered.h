//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_ROCKET_POWERED_HPP
#define STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_ROCKET_POWERED_HPP

#include "dynamic_duck/fly_behavior/fly_behavior.h"

class FlyRocketPowered : public FlyBehavior {
 public:
  void fly() const override;
};


#endif //STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_ROCKET_POWERED_HPP
