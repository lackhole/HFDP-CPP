cmake_minimum_required(VERSION 3.17)
project(observer)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(weather_station)

add_executable(observer main.cc)

target_link_libraries(observer PUBLIC weather_station)