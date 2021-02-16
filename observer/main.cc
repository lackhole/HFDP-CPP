#include <iostream>
#include "weather_station/weather_station.h"

int main() {

  Signal<void()> sig;

  auto id1 = sig.connect([](){std::cout << "conn 1" << std::endl;});
  auto id2 = sig.connect([](){std::cout << "conn 2" << std::endl;});

  sig();
  sig();

  sig.disconnect(id1);
  sig.disconnect(id2);

  sig();

  return 0;
}