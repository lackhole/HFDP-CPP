//
// Created by cosge on 2021-02-09.
//

#ifndef STRATEGY_DYNAMIC_DUCK_DUCK__MODELDUCK_HPP
#define STRATEGY_DYNAMIC_DUCK_DUCK__MODELDUCK_HPP

#include "dynamic_duck/duck/abstract_duck.hpp"

class ModelDuck : public AbstractDuck {
 public:
  ModelDuck();
  ~ModelDuck();

  void display() override;
};


#endif //STRATEGY_DYNAMIC_DUCK_DUCK__MODELDUCK_HPP
