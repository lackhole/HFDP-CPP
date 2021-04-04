//
// Created by cosge on 2021-03-03.
//

#ifndef WEATHER_STATION_STANDARD_OBSERVER_FORWARD_DECLARE_H_
#define WEATHER_STATION_STANDARD_OBSERVER_FORWARD_DECLARE_H_

#include <set>

namespace wss {

template<typename Func> class ObserverBase;

template<typename ObservableType> class Observer;

template<typename FuncType,
         typename KeyType = ObserverBase<FuncType>*,
         typename SetType = std::set<KeyType>
> class Observable;

}

#endif //WEATHER_STATION_STANDARD_OBSERVER_FORWARD_DECLARE_H_
