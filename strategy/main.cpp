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

  // *mallard = *model; blocked!
  try {
    dynamic_cast<ModelDuck&>(*mallard) =
        dynamic_cast<const ModelDuck&>(*model);
  }
  catch (const std::exception& e){
    std::cout << "Bad casting" << std::endl;
  }

  return 0;
}
