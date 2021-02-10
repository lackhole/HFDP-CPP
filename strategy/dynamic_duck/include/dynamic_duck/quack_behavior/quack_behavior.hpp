//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_HPP
#define STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_HPP

class QuackBehavior {
 public:
  virtual ~QuackBehavior() = default;
  virtual void quack() const = 0;
};


#endif //STRATEGY_DYNAMIC_DUCK_QUACK_BEHAVIOR_QUACK_BEHAVIOR_HPP
