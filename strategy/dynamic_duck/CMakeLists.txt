cmake_minimum_required(VERSION 3.17)
project(dynamic_duck)

set(DD_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/dynamic_duck")

add_library(dynamic_duck STATIC
        ${DD_INCLUDE_DIR}/duck/abstract_duck.cc
        ${DD_INCLUDE_DIR}/duck/mallard_duck.cc
        ${DD_INCLUDE_DIR}/duck/model_duck.cc

        ${DD_INCLUDE_DIR}/fly_behavior/fly_with_wings.cc
        ${DD_INCLUDE_DIR}/fly_behavior/fly_no_way.cc
        ${DD_INCLUDE_DIR}/fly_behavior/fly_rocket_powered.cc

        ${DD_INCLUDE_DIR}/quack_behavior/quack.cc
        ${DD_INCLUDE_DIR}/quack_behavior/mute_quack.cc
        ${DD_INCLUDE_DIR}/quack_behavior/squeak.cc
        )

target_include_directories(dynamic_duck PUBLIC
        include)