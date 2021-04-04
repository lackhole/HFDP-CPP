//
// Created by YongGyu Lee on 2021/04/03.
//

#include "test.hpp"
#include "weather_station_standard/weather_station_standard.h"

#include <iostream>

int value = 0;

struct ConcreteObservable : public wss::Observable<void(ConcreteObservable*, int)> {
 public:

  void setData(int x) {
    data = x;
  }

  int pullData() {
    return data;
  }

  int data = -1;
};

struct ConcreteObserver : public wss::Observer<void(int), ConcreteObservable*> {

  void update(ConcreteObservable* observable, int args) override {
    std::cout << "Pushed " << args << std::endl;
    value = args;
  }

  void update(ConcreteObservable* observable) override {
    std::cout << "Pulled " << observable->pullData() << std::endl;
  }
};

int main() {
  INIT_TEST("wss-test")

  {
    ConcreteObservable observable;
    ConcreteObserver observer;

    observable.registerObserver(&observer);

    observable.setData(1);
    observable.notifyObservers();

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
//    auto observable2 = wss::make_unique_observable<ConcreteObservable2>();
//    auto observer2 = wss::make_shared_observer<ConcreteObserver>();
//    observable2->registerObserver(observer2);
//
//    observable2->setChanged();
//    observable2->notifyObservers(4);
//    TEST_ENSURES(value == 4);
  }


  return EXIT_SUCCESS;
}