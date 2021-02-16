//
// Created by cosge on 2021-02-17.
//

#ifndef OBSERVER_CURRENT_CONDITION_DISPLAY_H
#define OBSERVER_CURRENT_CONDITION_DISPLAY_H

#include "weather_station/display/display_interface.h"
#include "weather_station/weather_data/weather_data.h"

class CurrentConditionDisplay : public DisplayInterface {
 public:

  CurrentConditionDisplay(WeatherData& weatherData);
  ~CurrentConditionDisplay();

  void onUpdate(const WeatherData& w);

  void display() override;

 private:
  WeatherData& weatherData;
  WeatherData::key_type callback_key;

  float temperature = 0;
  float humidity = 0;
};


#endif //OBSERVER_CURRENT_CONDITION_DISPLAY_H
