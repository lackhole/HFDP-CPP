//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_H_
#define STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_H_

namespace strategy{
namespace dynamic_duck{

class QuackBehavior {
 public:
  virtual ~QuackBehavior() = default;
  virtual void quack() const = 0;
};

} // namespace dynamic_duck
} // namespace strategy

#endif //STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_H_
