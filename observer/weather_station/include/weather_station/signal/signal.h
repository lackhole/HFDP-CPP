//
// Created by cosge on 2021-02-16.
//

#ifndef WEATHER_STATION_SIGNAL_H_
#define WEATHER_STATION_SIGNAL_H_

#include <functional>
#include <map>
#include <mutex>

template<typename Func, typename Key = int>
class Signal {
 public:
  using func_type = std::function<Func>;
  using result_type = typename func_type::result_type;
  using argument_type = typename func_type::argument_type;
  using key_type = Key;
  using container_type = std::map<key_type, func_type>;
  using mutex_type = std::mutex;

  template<typename F>
  key_type connect(F f);

  template<typename F>
  key_type connect(key_type k, F f);

  bool disconnect(key_type k);

  template<typename ...Args>
  decltype(auto) operator()(Args&&... args);

 private:
  mutex_type m;
  key_type key{0};
  container_type connections;
};

template<typename Func, typename Key>
template<typename F>
typename Signal<Func, Key>::key_type
Signal<Func, Key>::connect(F f) {
  std::lock_guard<mutex_type> lck(m);
  key_type new_key = key;
  connections[new_key] = std::move(f);
  ++key;
  return new_key;
}

template<typename Func, typename Key>
template<typename F>
typename Signal<Func, Key>::key_type
Signal<Func, Key>::connect(Signal::key_type k, F f) {
  std::lock_guard<mutex_type> lck(m);
  connections[k] = std::move(f);
  key = std::max(k, key) + 1;
  return k;
}

template<typename Func, typename Key>
bool Signal<Func, Key>::disconnect(Signal::key_type k) {
  std::lock_guard<mutex_type> lck(m);
  return connections.erase(k);
}

template<typename Func, typename Key>
template<typename... Args>
decltype(auto) Signal<Func, Key>::operator()(Args &&... args) {
  std::lock_guard<mutex_type> lck(m);
  if(connections.empty()) return typename func_type::result_type();

  for(auto it = connections.begin(); it != std::prev(connections.end()); ++it) {
    (it->second)(args...);
  }
  return (std::prev(connections.end())->second)(std::forward<Args>(args)...);
}


#endif //WEATHER_STATION_SIGNAL_H_
