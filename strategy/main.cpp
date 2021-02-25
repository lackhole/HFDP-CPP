#include <iostream>
#include <memory>
#include <string>

#include <dynamic_duck.hpp>
#include <static_duck.h>

using namespace strategy;

int main() {

  std::unique_ptr<dynamic_duck::AbstractDuck> mallard = std::make_unique<dynamic_duck::MallardDuck>();

  mallard->performQuack();
  mallard->performFly();

  std::unique_ptr<dynamic_duck::AbstractDuck> model = std::make_unique<dynamic_duck::ModelDuck>();
  model->performFly();
  model->setFlyBehavior(std::make_unique<dynamic_duck::FlyRocketPowered>());
  model->performFly();

  model = std::make_unique<dynamic_duck::MallardDuck>();
  model->performQuack();

  std::cout << "====================" << std::endl;
  dynamic_duck::ModelDuck d1;
  d1.performFly();
  d1.setFlyBehavior(std::make_unique<dynamic_duck::FlyRocketPowered>());
  d1.performFly();

  dynamic_duck::ModelDuck d2 = d1;
  d2.performFly();

  // *mallard = *model; blocked!
  try {
    dynamic_cast<dynamic_duck::ModelDuck&>(*mallard) =
      dynamic_cast<const dynamic_duck::ModelDuck&>(*model);
  }
  catch (const std::exception& e){
    std::cout << "Bad casting" << std::endl;
  }

  return 0;
}
