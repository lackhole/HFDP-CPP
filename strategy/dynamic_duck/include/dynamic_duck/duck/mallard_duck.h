//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_DUCK_MALLARD_DUCK_H_
#define STRATEGY_DYNAMIC_DUCK_DUCK_MALLARD_DUCK_H_

#include "dynamic_duck/duck/abstract_duck.h"

class MallardDuck : public AbstractDuck {
 public:
  MallardDuck();

  void display() override;

};


#endif //STRATEGY_DYNAMIC_DUCK_DUCK_MALLARD_DUCK_H_
