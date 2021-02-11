cmake_minimum_required(VERSION 3.17)
project(static_duck)

add_library(static_duck INTERFACE)

target_include_directories(static_duck INTERFACE
        include)