project(weather_station_standard)

add_library(weather_station_standard INTERFACE)

target_include_directories(weather_station_standard INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(RUN_TEST)
    add_subdirectory(test)
endif()
