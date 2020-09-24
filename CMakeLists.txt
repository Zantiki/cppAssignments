cmake_minimum_required(VERSION 2.8)

project(a1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")
file(COPY assignment1/temps.dat
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(Oving1 assignment1/Oving1.cpp)
add_executable(Oving2 assignment2/Oving2.cpp)
add_executable(Oving4 assignment4/Oving4.cpp)
add_executable(Circle assignment3/circle.cpp)
add_executable(Commodity assignment3/commodity_main.cpp)
add_executable(string_fun assignment3/string_fun.cpp)
add_executable(Oving5 assignment5/chess.cpp)
add_executable(chess6 assignment6/chess.cpp)
add_executable(server6 assignment6/server.cpp)
add_executable(7_a1 assignment7/part1.cpp)
target_link_libraries(server6 ${Boost_LIBRARIES})

INCLUDE(FindPkgConfig)

if(APPLE)
    set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/usr/local/lib/pkgconfig:/opt/X11/lib/pkgconfig:/usr/local/Cellar/libffi/3.2.1/lib/pkgconfig:/usr/local/Cellar/libsigc++@2/2.10.2/lib/pkgconfig")
endif()

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(oving4_gtkmm assignment4/main_gtkmm.cpp)
target_link_libraries(oving4_gtkmm ${GTKMM_LIBRARIES})
