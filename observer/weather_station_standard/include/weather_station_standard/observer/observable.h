//
// Created by cosge on 2021-03-03.
//

#ifndef WEATHER_STATION_STANDARD_OBSERVER_OBSERVABLE_H_
#define WEATHER_STATION_STANDARD_OBSERVER_OBSERVABLE_H_

#include "weather_station_standard/observer/forward_declare.h"
#include <memory>

namespace wss {

template<typename R, typename ...Args, typename KeyType, typename SetType>
class Observable<R(Args...), KeyType, SetType> {
 public:
  using function_sig = R(Args...);
  using return_type = R;

  using key_type = KeyType;
  using set_type = SetType;

  Observable() = default;
  virtual ~Observable() = default;

  inline bool removeObserver(key_type observer) {
    return observers.erase(observer);
  }

  inline bool registerObserver(key_type observer) {
    return observers.emplace(observer).second;
  }

  inline bool isRegistered(const key_type observer) const {
    return observers.find(observer) != observers.cend();
  }

  void notifyObservers(Args&&... args) {
    if(isChanged()) {
      if(!observers.empty()) {
        auto it = observers.begin();

        for(;it != std::prev(observers.end()); ++it)
          onUpdate(*it, args...);

        // perfect forward arguments to the last observer
        onUpdate(*it, std::forward<Args>(args)...);
      }
      clearChanged();
    }
  }

  inline void setChanged() { changed = true; }
  inline void clearChanged() { changed = false; }
  inline bool isChanged() const { return changed; }

 protected:
  virtual void onUpdate(key_type observer, Args... args) = 0;

 private:

  bool changed = false;
  set_type observers;
};

template<typename Derived, typename ...Args>
inline
std::unique_ptr<Observable<typename Derived::function_sig,
                           typename Derived::key_type,
                           typename Derived::set_type>>
make_unique_observable(Args&&... args) {
  return std::make_unique<Derived>(std::forward<Args>(args)...);
}

template<typename Derived, typename ...Args>
inline
std::shared_ptr<Observable<typename Derived::function_sig,
                           typename Derived::key_type,
                           typename Derived::set_type>>
make_shared_observable(Args&&... args) {
  return std::make_unique<Derived>(std::forward<Args>(args)...);
}


}

#endif //WEATHER_STATION_STANDARD_OBSERVER_OBSERVABLE_H_
