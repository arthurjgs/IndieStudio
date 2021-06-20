CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(Duck)

SET(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -fPIC")
endif(CMAKE_COMPILER_IS_GNUCXX)

ADD_LIBRARY(Duck SHARED
        duck.cpp
        duck.hpp
        ../AbstractPlayer.cpp
        ../AbstractPlayer.hpp)

SET_TARGET_PROPERTIES(Duck PROPERTIES PREFIX "")
