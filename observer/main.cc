#include <iostream>
#include <memory>
#include <atomic>
#include <functional>
#include <memory>
#include <unordered_set>
#include <weather_station_standard/weather_station_standard.h>

#include "weather_station_standard/weather_station_standard.h"

struct ConcreteObserver : public wss::Observer<void(int)> {
  void update(int args) override {
    std::cout << "Get " << args << std::endl;
  }
};

struct ConcreteObservable : public wss::Observable<void(int), std::weak_ptr<ConcreteObserver>> {
  void onUpdate(key_type observer, int args) override {
    if(observer.expired()) return;
    observer.lock()->update(args);
  }
};

// custom predicate example
bool operator < (const std::weak_ptr<ConcreteObserver>& w1, const std::weak_ptr<ConcreteObserver>& w2) {
  return w1.lock() < w2.lock();
}

int main() {
  wss::Observable<void(int)> subject;
  ConcreteObserver observer;

  subject.registerObserver(&observer);
  subject.setChanged();
  subject.notifyObservers(10);
  subject.removeObserver(&observer);
  subject.setChanged();
  subject.notifyObservers(11);

  ConcreteObservable subject2;
  auto observer2 = std::make_shared<ConcreteObserver>();

  subject2.registerObserver(observer2);
  subject2.setChanged();
  subject2.notifyObservers(99);
  subject2.removeObserver(observer2);
  subject2.setChanged();
  subject2.notifyObservers(100);

  std::shared_ptr<ConcreteObserver> p1 = observer2;
  std::cout << std::boolalpha;

  using namespace wss::internal;

  std::cout << is_indirect_accessible<int>::value << std::endl;
  std::cout << is_indirect_accessible<int *>::value << std::endl;
  std::cout << is_indirect_accessible<std::shared_ptr<int>>::value << std::endl;


  std::cout << "End of main()" << std::endl;

  return 0;
}