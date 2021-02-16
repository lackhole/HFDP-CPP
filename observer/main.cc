#include <iostream>
#include "weather_station/weather_station.h"

template<typename T>
T bar() { return T{}; }
template<> void bar<void>() {}

template<typename T>
auto foo() {
  return bar<T>();
}

void faa(){
  return void();
}

int main() {

  Signal<void(std::string)> sig;

  auto id1 = sig.connect([](auto s){std::cout << "conn 1" << " : " << s << std::endl;});
//  auto id2 = sig.connect([](auto s){std::cout << "conn 2" << " : " << s << std::endl;});

  std::string str = "123435";
  sig(std::move(str));
  sig(str);

  sig.disconnect(id1);
//  sig.disconnect(id2);

  sig(str);

  return 0;
}