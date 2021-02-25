cmake_minimum_required(VERSION 3.17)
project(static_duck)

set(SD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/static_duck)

add_library(static_duck STATIC
        ${SD_INCLUDE_DIR}/fly_behavior/fly_no_way.cc
        ${SD_INCLUDE_DIR}/fly_behavior/fly_rocket_powered.cc
        ${SD_INCLUDE_DIR}/fly_behavior/fly_with_wings.cc

        ${SD_INCLUDE_DIR}/quack_behavior/mute_quack.cc
        ${SD_INCLUDE_DIR}/quack_behavior/quack.cc
        ${SD_INCLUDE_DIR}/quack_behavior/squeak.cc
        )

target_include_directories(static_duck PUBLIC
        include)