cmake_minimum_required(VERSION 2.8)

project(a1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")
file(COPY assignment1/temps.dat
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(Oving1 assignment1/Oving1.cpp)
add_executable(Oving2 assignment2/Oving2.cpp)
add_executable(Circle assignment3/circle.cpp)
add_executable(Commodity assignment3/commodity_main.cpp)
add_executable(string_fun assignment3/string_fun.cpp)