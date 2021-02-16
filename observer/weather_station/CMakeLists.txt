project(weather_station)

set(WEATHER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/weather_station")

add_library(dynamic_duck STATIC
        ${WEATHER_INCLUDE_DIR}/weather-station.h
        )

target_include_directories(weather_station PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)