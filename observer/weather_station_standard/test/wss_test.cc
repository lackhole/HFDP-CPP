//
// Created by YongGyu Lee on 2021/04/03.
//

#include "test.hpp"
#include "weather_station_standard/weather_station_standard.h"

#include <iostream>

int value = 0;

struct ConcreteObservable : public wss::Observable<void(int)> {
 public:

 protected:
  void onUpdate(key_type observer, int args) override {
    observer->update(args);
  }
};

struct ConcreteObserver : public wss::Observer<void(int)> {
  void update(int args) override {
    std::cout << "Get " << args << std::endl;
    value = args;
  }
};

struct ConcreteObservable2 : public wss::Observable<void(int), std::shared_ptr<wss::Observer<void(int)>>> {
 public:

 protected:
  void onUpdate(key_type observer, int args) override {
    observer->update(args);
  }
};

int main() {
  INIT_TEST("wss-test")

  {
    ConcreteObservable observable;
    ConcreteObserver observer;

    observable.registerObserver(&observer);

    observable.setChanged();
    observable.notifyObservers(1);
    TEST_ENSURES(value == 1);

    observable.notifyObservers(2);
    TEST_ENSURES(value != 2);

    observable.removeObserver(&observer);
    observable.setChanged();
    observable.notifyObservers(3);
    TEST_ENSURES(value != 3);
  }

  {
    auto observable2 = wss::make_unique_observable<ConcreteObservable2>();
    auto observer2 = wss::make_shared_observer<ConcreteObserver>();
    observable2->registerObserver(observer2);

    observable2->setChanged();
    observable2->notifyObservers(4);
    TEST_ENSURES(value == 4);
  }


  return EXIT_SUCCESS;
}