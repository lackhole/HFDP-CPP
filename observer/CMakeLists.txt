cmake_minimum_required(VERSION 3.17)
project(observer)

set(CMAKE_CXX_STANDARD 14)

#add_subdirectory(weather_station)

add_executable(observer main.cc)

target_include_directories(observer PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/weather_station/include)
#target_link_libraries(observer PUBLIC weather_station)