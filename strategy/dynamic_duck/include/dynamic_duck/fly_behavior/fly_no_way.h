//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_NO_WAY_H_
#define STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_NO_WAY_H_

#include "dynamic_duck/fly_behavior/fly_behavior.h"

class FlyNoWay : public FlyBehavior {
 public:
  void fly() const override;
 protected:
  FlyNoWay* clone_impl() const override;
};


#endif //STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_NO_WAY_H_
