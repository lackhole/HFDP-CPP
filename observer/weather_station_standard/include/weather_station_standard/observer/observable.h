//
// Created by cosge on 2021-03-03.
//

#ifndef WEATHER_STATION_STANDARD_OBSERVER_OBSERVABLE_H_
#define WEATHER_STATION_STANDARD_OBSERVER_OBSERVABLE_H_

#include "weather_station_standard/observer/forward_declare.h"
#include <memory>
#include <type_traits>

namespace wss {

template<typename R, typename DerivedPtr, typename KeyType, typename SetType>
class Observable<R(DerivedPtr), KeyType, SetType> {
 public:
  using function_type         = R(DerivedPtr);
  using return_type           = R;
  using derived_pointer_type  = DerivedPtr;
  using derived_type          = std::remove_pointer_t<derived_pointer_type>;
  using key_type              = KeyType;
  using set_type              = SetType;

  virtual ~Observable() = default;

  inline bool removeObserver(key_type observer) {
    return observers.erase(observer);
  }

  inline void removeAllObservers() {
    observers.clear();
  }

  inline bool registerObserver(key_type observer) {
    return observers.emplace(observer).second;
  }

  inline bool isRegistered(const key_type observer) const {
    return observers.find(observer) != observers.cend();
  }

  void notifyObservers() {
    if(isChanged()) {
      for(auto& observer : observers)
        observer->update(static_cast<DerivedPtr>(this));
      clearChanged();
    }
  }

  inline void setChanged() { changed = true; }
  inline void clearChanged() { changed = false; }
  inline bool isChanged() const { return changed; }

 protected:
  bool changed = false;
  set_type observers;
};

template<typename R, typename ...Args, typename DerivedPtr, typename KeyType, typename SetType>
class Observable<R(DerivedPtr, Args...), KeyType, SetType> : public Observable<R(DerivedPtr), KeyType, SetType> {
 public:
  using function_type         = R(DerivedPtr, Args...);
  using return_type           = R;
  using derived_pointer_type  = DerivedPtr;
  using derived_type          = std::remove_pointer_t<derived_pointer_type>;
  using key_type              = KeyType;
  using set_type              = SetType;

  using base = Observable<R(DerivedPtr), KeyType, SetType>;

  virtual ~Observable() = default;


  using base::removeObserver;
  using base::removeAllObservers;
  using base::registerObserver;

  using base::isRegistered;
  using base::notifyObservers;
  using base::setChanged;
  using base::clearChanged;
  using base::isChanged;

  // push
  void notifyObservers(Args&&... args) {
    if(isChanged()) {
      if(!observers.empty()) {
        auto it = observers.begin();

        for(;it != std::prev(observers.end()); ++it)
          (*it)->update(static_cast<DerivedPtr>(this), args...);

        // perfect forward arguments to the last observer
        (*it)->update(static_cast<DerivedPtr>(this), std::forward<Args>(args)...);
      }
      clearChanged();
    }
  }

 protected:
  using base::observers;
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
