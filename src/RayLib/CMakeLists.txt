cmake_minimum_required(VERSION 3.17)
project(indie_raylib)

set(CMAKE_CXX_STANDARD 17)
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra --std=c++17")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(raylib REQUIRED)

add_library(${PROJECT_NAME} SHARED
        RayLib.cpp
        RayLibCore.cpp
        RayLibShapes.cpp
        RayLibTextures.cpp
        RayLibText.cpp
        RayLibModels.cpp
        RayLibRaudio.cpp
        RayLibPhysac.cpp
        RayLib.hpp
        ../../shared/IGraphicalLibrary.hpp)

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")

target_link_libraries(${PROJECT_NAME} raylib)