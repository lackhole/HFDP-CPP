//
// Created by cosge on 2021-02-17.
//

#ifndef WEATHER_STATION_WEATHER_DATA_DISPLAY_INTERFACE_H_
#define WEATHER_STATION_WEATHER_DATA_DISPLAY_INTERFACE_H_


class DisplayInterface {
 public:
  virtual ~DisplayInterface() = default;
  virtual void display() = 0;
};


#endif //WEATHER_STATION_WEATHER_DATA_DISPLAY_INTERFACE_H_
