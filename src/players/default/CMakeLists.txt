CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(default)

SET(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

ADD_LIBRARY(default SHARED
        default.cpp
        default.hpp
        ../AbstractPlayer.cpp
        ../AbstractPlayer.hpp)

target_link_libraries(${PROJECT_NAME} raylib)

SET_TARGET_PROPERTIES(default PROPERTIES PREFIX "")
