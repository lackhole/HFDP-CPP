//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLYBEHAVIOR_H_
#define STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLYBEHAVIOR_H_

class FlyBehavior {
 public:
  virtual ~FlyBehavior() = default;
  virtual void fly() const = 0;
};

#endif //STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLYBEHAVIOR_H_
