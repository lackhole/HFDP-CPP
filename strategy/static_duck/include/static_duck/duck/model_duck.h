//
// Created by cosge on 2021-02-25.
//

#ifndef STRATEGY_STATIC_DUCK_DUCK_MODEL_DUCK_H_
#define STRATEGY_STATIC_DUCK_DUCK_MODEL_DUCK_H_

#include "static_duck/duck/abstract_duck.h"

namespace strategy {
namespace static_duck {

class ModelDuck : public AbstractDuck<ModelDuck> {
 public:
  ModelDuck();

  void display() const;
};

} // namespace static_duck
} // namespace strategy

#endif //STRATEGY_STATIC_DUCK_DUCK_MODEL_DUCK_H_
