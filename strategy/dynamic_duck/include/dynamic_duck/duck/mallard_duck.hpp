//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_DUCK_MALLARD_DUCK_HPP
#define STRATEGY_DYNAMIC_DUCK_DUCK_MALLARD_DUCK_HPP

#include "dynamic_duck/duck/abstract_duck.hpp"

class MallardDuck : public AbstractDuck {
 public:
  MallardDuck();
  ~MallardDuck();

  void display() override;

};


#endif //STRATEGY_DYNAMIC_DUCK_DUCK_MALLARD_DUCK_HPP
