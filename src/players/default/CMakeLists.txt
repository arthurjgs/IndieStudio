CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(bomberman_player)

SET(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -fPIC")
endif(CMAKE_COMPILER_IS_GNUCXX)

ADD_LIBRARY(bomberman_player SHARED
        default.cpp
        default.hpp
        ../AbstractPlayer.cpp
        ../AbstractPlayer.hpp)

SET_TARGET_PROPERTIES(bomberman_player PROPERTIES PREFIX "")
