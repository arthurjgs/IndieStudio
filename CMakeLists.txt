cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra --std=c++17")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories(src)
include_directories(shared)

add_executable(bomberman
        src/main.cpp
        shared/IGraphicalLibrary.hpp)

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

add_subdirectory("src/RayLib" "src/RayLib")

install(TARGETS bomberman)

enable_testing()
add_test(NAME bomberman COMMAND bomberman)