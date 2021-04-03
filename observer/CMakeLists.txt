cmake_minimum_required(VERSION 3.17)
project(observer)

set(CMAKE_CXX_STANDARD 17)

if(RUN_TEST)
    enable_testing()
endif()

add_subdirectory(weather_station)
add_subdirectory(weather_station_standard)

add_executable(observer main.cc)

target_link_libraries(observer PUBLIC
        weather_station
        weather_station_standard
        )