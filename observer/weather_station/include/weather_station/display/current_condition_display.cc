//
// Created by cosge on 2021-02-17.
//

#include "current_condition_display.h"

#include <iostream>

void CurrentConditionDisplay::display() {
  std::cout
    << "Current conditions: "
    << temperature << "C degree and "
    << humidity << "% humidity"
    << std::endl;
}

CurrentConditionDisplay::CurrentConditionDisplay(WeatherData &weatherData)
: weatherData(weatherData) {
  callback_key = weatherData.connect([this](const WeatherData& w) {
    onUpdate(w);
  });
}

CurrentConditionDisplay::~CurrentConditionDisplay() {
  weatherData.disconnect(callback_key);
}

void CurrentConditionDisplay::onUpdate(const WeatherData &w) {
  temperature = w.getTemperature();
  humidity = w.getHumidity();
  display();
}
