cmake_minimum_required(VERSION 3.17)
project(strategy)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(dynamic_duck)

add_executable(strategy main.cpp)
target_link_libraries(strategy PUBLIC dynamic_duck)