//
// Created by cosge on 2021-03-03.
//

#ifndef WEATHER_STATION_STANDARD_OBSERVER_OBSERVER_H_
#define WEATHER_STATION_STANDARD_OBSERVER_OBSERVER_H_

#include "weather_station_standard/observer/forward_declare.h"

namespace wss {

template<typename R, typename ...Args>
class Observer<R(Args...)> {
 public:
  using function_sig = R(Args...);
  using return_type = R;

  virtual return_type update(Args... args) = 0;
};

}

#endif //WEATHER_STATION_STANDARD_OBSERVER_OBSERVER_H_
