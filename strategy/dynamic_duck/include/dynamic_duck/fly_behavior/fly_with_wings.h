//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_WITH_WINGS_H_
#define STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_WITH_WINGS_H_

#include "dynamic_duck/fly_behavior/fly_behavior.h"

class FlyWithWings : public FlyBehavior {
 public:
  void fly() const override;

 protected:
  FlyWithWings *clone_impl() const override;
};


#endif //STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_WITH_WINGS_H_
