#include <iostream>
#include <memory>
#include <string>

#include <dynamic_duck.hpp>


int main() {

  std::unique_ptr<AbstractDuck> mallard = std::make_unique<MallardDuck>();

  mallard->performQuack();
  mallard->performFly();

  return 0;
}
