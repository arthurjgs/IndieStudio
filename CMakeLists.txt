cmake_minimum_required(VERSION 3.19)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra --std=c++17")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

find_package(raylib 2.5.0 REQUIRED)

add_executable(bomberman
        main.cpp)

target_link_libraries(bomberman raylib)