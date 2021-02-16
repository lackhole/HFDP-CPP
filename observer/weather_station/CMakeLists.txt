project(weather_station)

set(WEATHER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/weather_station")

add_library(weather_station STATIC
        ${WEATHER_INCLUDE_DIR}/weather_data/weather_data.cc
        )

target_include_directories(weather_station PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)