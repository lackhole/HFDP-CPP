//
// Created by cosge on 2021-03-03.
//

#ifndef WEATHER_STATION_STANDARD_OBSERVER_OBSERVER_H_
#define WEATHER_STATION_STANDARD_OBSERVER_OBSERVER_H_

#include "weather_station_standard/observer/forward_declare.h"

#include <memory>

namespace wss {


template<typename R, typename ObservableType, typename ...Args>
class ObserverBase<R(ObservableType, Args...)> {
 public:
  using function_sig = R(Args...);
  using return_type = R;

  virtual return_type update(ObservableType, Args...) {}
  virtual return_type update(ObservableType) {}
};

template<typename R, typename ...Args, typename ObservableType>
class Observer<R(Args...), ObservableType> : public ObserverBase<R(ObservableType, Args...)> {
 public:
  using function_sig = R(Args...);
  using return_type = R;
  using observable_type = ObservableType;
};

//template<typename Derived, typename ...Args>
//inline
//std::unique_ptr<Observer<typename Derived::function_sig, typename Derived::observable_type>>
//make_unique_observer(Args&&... args) {
//  return std::make_unique<Derived>(std::forward<Args>(args)...);
//}
//
//template<typename Derived, typename ...Args>
//inline
//std::shared_ptr<Observer<typename Derived::function_sig, typename Derived::observable_type>>
//make_shared_observer(Args&&... args) {
//  return std::make_shared<Derived>(std::forward<Args>(args)...);
//}
//
//template<typename Derived, typename ...Args>
//inline
//std::shared_ptr<Observer<typename Derived::function_sig, typename Derived::observable_type>>
//make_shared_delayed_observer(Args&&... args) {
//  return std::make_unique<Derived>(std::forward<Args>(args)...);
//}

}

#endif //WEATHER_STATION_STANDARD_OBSERVER_OBSERVER_H_
