project(weather_station_book)

add_library(weather_station_book INTERFACE)

target_include_directories(weather_station_book INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(RUN_TEST)
    add_subdirectory(test)
endif()
