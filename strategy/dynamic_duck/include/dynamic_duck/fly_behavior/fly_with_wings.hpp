//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_WITH_WINGS_HPP
#define STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_WITH_WINGS_HPP

#include "fly_behavior.hpp"

class FlyWithWings : public FlyBehavior {
 public:
  void fly() const override;
};


#endif //STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLY_WITH_WINGS_HPP
