//
// Created by cosge on 2021-03-03.
//

#ifndef WEATHER_STATION_STANDARD_OBSERVER_OBSERVER_H_
#define WEATHER_STATION_STANDARD_OBSERVER_OBSERVER_H_

#include "weather_station_standard/observer/forward_declare.h"

#include <memory>

namespace wss {


template<typename R, typename ObservablePtrType, typename ...Args>
class ObserverBase<R(ObservablePtrType, Args...)> {
 public:
  using function_type   = R(ObservablePtrType, Args...);
  using return_type     = R;

  virtual ~ObserverBase() = 0;

  // push observable can override both push and pull
  virtual return_type update(ObservablePtrType, Args...) {}
  virtual return_type update(ObservablePtrType) {}
};

template<typename R, typename ObservablePtrType>
class ObserverBase<R(ObservablePtrType)> {
 public:
  using function_type   = R(ObservablePtrType);
  using return_type     = R;

  // pull-only observable must override pull-update function
  virtual return_type update(ObservablePtrType) = 0;
};

template<typename ObservableType>
 class Observer : public ObserverBase<typename ObservableType::function_type> {
 public:
  using function_type     = typename ObservableType::function_type;
  using return_type       = typename ObservableType::return_type;
  using observable_type   = ObservableType;

  virtual ~Observer() = 0;
};


template<typename R, typename ObservableType, typename ...Args>
ObserverBase<R(ObservableType, Args...)>::~ObserverBase() = default;

template<typename ObservableType>
Observer<ObservableType>::~Observer() = default;

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
