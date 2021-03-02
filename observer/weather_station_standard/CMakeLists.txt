project(weather_station_standard)

set(WEATHER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/weather_station_standard")

#add_library(weather_station_standard STATIC
#        ${WEATHER_INCLUDE_DIR}/weather_data/weather_data.cc
#
#        ${WEATHER_INCLUDE_DIR}/display/current_condition_display.cc)

target_include_directories(weather_station_standard PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)