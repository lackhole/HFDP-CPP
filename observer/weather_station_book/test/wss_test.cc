//
// Created by YongGyu Lee on 2021/04/03.
//

#include "test.hpp"
#include "weather_station_book/weather_station.h"

#include <iostream>

int value = 0;

struct ConcreteObservable : public book::Observable<void(ConcreteObservable*, int)> {
 public:

  void setData(int x) {
    data = x;
  }

  int pullData() {
    return data;
  }

  int data = -1;
};

struct ConcreteObserver : public book::Observer<ConcreteObservable> {


  void update(ConcreteObservable* observable, int args) override {
    std::cout << "Pushed " << args << std::endl;
    value = args;
  }

  void update(ConcreteObservable* observable) override {
    std::cout << "Pulled " << observable->pullData() << std::endl;
    value = observable->pullData();
  }
};

int main() {
  INIT_TEST("wss-test")

  {
    ConcreteObservable observable;
    ConcreteObserver observer;

    // default test
    value = 0;
    observable.setChanged();
    observable.notifyObservers(50);
    TEST_ENSURES(value == 0);

    // registerObserver() test
    observable.registerObserver(&observer);
    TEST_ENSURES(observable.isRegistered(&observer) == true);

    // Push test
    observable.setChanged();
    observable.notifyObservers(100);
    TEST_ENSURES(value == 100);

    // Pull test
    observable.setData(200);
    observable.setChanged();
    observable.notifyObservers();
    TEST_ENSURES(value == 200);

    // setChanged() test
    observable.notifyObservers(300);
    TEST_ENSURES(value != 300);

    // removeObserver() test
    observable.removeObserver(&observer);
    observable.setChanged();
    observable.notifyObservers(400);
    TEST_ENSURES(value != 400);
  }

  {
//    auto observable2 = book::make_unique_observable<ConcreteObservable2>();
//    auto observer2 = book::make_shared_observer<ConcreteObserver>();
//    observable2->registerObserver(observer2);
//
//    observable2->setChanged();
//    observable2->notifyObservers(4);
//    TEST_ENSURES(value == 4);
  }


  return EXIT_SUCCESS;
}