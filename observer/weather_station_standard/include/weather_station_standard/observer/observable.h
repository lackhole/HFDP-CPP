//
// Created by cosge on 2021-03-03.
//

#ifndef WEATHER_STATION_STANDARD_OBSERVER_OBSERVABLE_H_
#define WEATHER_STATION_STANDARD_OBSERVER_OBSERVABLE_H_

#include "weather_station_standard/observer/forward_declare.h"
#include <type_traits>
#include <cassert>

namespace wss {

namespace internal {

template<typename ...Args>
using void_t = void;

template<typename T, typename = void> struct is_indirect_accessible : public std::is_pointer<T> {};
template<typename T> struct is_indirect_accessible<T, void_t<decltype(std::declval<T>().operator->())>> : public std::true_type {};

template<typename T>
using is_indirect_accessible_t = typename is_indirect_accessible<T>::type;

template<typename T>
constexpr bool is_indirect_accessible_v = is_indirect_accessible<T>::value;

}

template<typename R, typename ...Args, typename KeyType, typename ContainerType>
class Observable<R(Args...), KeyType, ContainerType> {
 public:
  using function_sig = R(Args...);
  using return_type = R;

  using key_type = KeyType;
  using container_type = ContainerType;

  Observable() = default;

  bool removeObserver(key_type observer) {
    return observers.erase(observer);
  }

  bool registerObserver(key_type observer) {
    auto p = observers.emplace(observer);
    return p.second;
  }

  void notifyObservers(Args&&... args) {
    if(isChanged()) {
      for(auto& observer : observers) {
        onUpdate(observer, args...);
      }
      clearChanged();
    }
  }

  virtual void onUpdate(key_type observer, Args... args) {
    onUpdateImpl(internal::is_indirect_accessible_t<key_type>{}, observer, args...);
  }

  bool isRegistered(const key_type observer) const {
    return observers.find(observer) != observers.cend();
  }

  inline void setChanged() { changed = true; }
  inline void clearChanged() { changed = false; }
  inline bool isChanged() const { return changed; }

 private:
  void onUpdateImpl(std::true_type, key_type observer, Args... args) {
    observer->update(args...);
  }

  void onUpdateImpl(std::false_type, key_type observer, Args... args) {
    assert(((void)"You have to override your own Observable::onUpdate(key_type observer, Args... args)", false));
  }

  bool changed = false;
  container_type observers;
};

}

#endif //WEATHER_STATION_STANDARD_OBSERVER_OBSERVABLE_H_
