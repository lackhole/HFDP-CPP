//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_DUCK__MODELDUCK_H_
#define STRATEGY_DYNAMIC_DUCK_DUCK__MODELDUCK_H_

#include "dynamic_duck/duck/abstract_duck.h"

class ModelDuck : public AbstractDuck {
 public:
  ModelDuck();

  void display() override;
};


#endif //STRATEGY_DYNAMIC_DUCK_DUCK__MODELDUCK_H_
