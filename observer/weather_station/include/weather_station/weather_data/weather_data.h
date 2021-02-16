//
// Created by cosge on 2021-02-16.
//

#ifndef WEATHER_STATION_WEATHER_DATA_WEATHER_DATA_H_
#define WEATHER_STATION_WEATHER_DATA_WEATHER_DATA_H_

#include "weather_station/signal/signal.h"

class WeatherData : public Signal<void(const WeatherData&)> {
 public:

  void measurementsChanged();

  void setMeasurements(float temperature, float humidity, float pressure);

  inline auto getTemperature() const { return temperature; }
  inline auto getHumidity() const { return humidity; }
  inline auto getPressure() const { return pressure; }

 private:
  float temperature = 0;
  float humidity = 0;
  float pressure = 0;
};


#endif //WEATHER_STATION_WEATHER_DATA_WEATHER_DATA_H_
