//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLYBEHAVIOR_H_
#define STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLYBEHAVIOR_H_

namespace strategy{
namespace dynamic_duck{

class FlyBehavior {
 public:
  virtual ~FlyBehavior() = default;
  virtual void fly() const = 0;
};

} // namespace dynamic_duck
} // namespace strategy

#endif //STRATEGY_DYNAMIC_DUCK_FLY_BEHAVIOR_FLYBEHAVIOR_H_
