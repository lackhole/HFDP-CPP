#include <iostream>
#include <memory>
#include <string>

#include <dynamic_duck.hpp>


int main() {

  std::unique_ptr<AbstractDuck> mallard = std::make_unique<MallardDuck>();

  mallard->performQuack();
  mallard->performFly();

  std::unique_ptr<AbstractDuck> model = std::make_unique<ModelDuck>();
  model->performFly();
  model->setFlyBehavior(std::make_unique<FlyRocketPowered>());
  model->performFly();

  std::cout << "====================" << std::endl;
  ModelDuck d1;
  d1.performFly();
  d1.setFlyBehavior(std::make_unique<FlyRocketPowered>());
  d1.performFly();

  ModelDuck d2 = d1;
  d2.performFly();


  return 0;
}
