cmake_minimum_required(VERSION 3.17)
project(dynamic_duck)

set(DD_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/dynamic_duck")

add_library(dynamic_duck STATIC
        ${DD_INCLUDE_DIR}/duck/abstract_duck.cpp
        ${DD_INCLUDE_DIR}/duck/mallard_duck.cpp
        ${DD_INCLUDE_DIR}/duck/model_duck.cpp

        ${DD_INCLUDE_DIR}/fly_behavior/fly_with_wings.cpp
        ${DD_INCLUDE_DIR}/fly_behavior/fly_no_way.cpp
        ${DD_INCLUDE_DIR}/fly_behavior/fly_rocket_powered.cpp

        ${DD_INCLUDE_DIR}/quack_behavior/quack.cpp
        ${DD_INCLUDE_DIR}/quack_behavior/mute_quack.cpp
        ${DD_INCLUDE_DIR}/quack_behavior/squeak.cpp
        )

target_include_directories(dynamic_duck PUBLIC
        include)