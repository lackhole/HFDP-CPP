//
// Created by cosge on 2021-02-16.
//

#include "weather_data.h"

void WeatherData::measurementsChanged() {
  operator()(*this);
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure) {
  this->temperature = temperature;
  this->humidity = humidity;
  this->pressure = pressure;
}
