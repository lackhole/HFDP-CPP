set(CMAKE_CXX_STANDARD 17)

macro(MAKE_TEST name target)
    add_executable(${name} ${target})
    target_link_libraries(${name} ${ARGN})
    add_test(NAME ${name} COMMAND ${name})
endmacro()

MAKE_TEST(wss_test wss_test.cc weather_station_book)