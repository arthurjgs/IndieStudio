cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories(src)
include_directories(shared)

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

find_package(raylib REQUIRED)

add_executable(bomberman
        src/main.cpp
        src/RayLib/RayLib.cpp
        src/RayLib/RayLibCore.cpp
        src/RayLib/RayLibShapes.cpp
        src/RayLib/RayLibTextures.cpp
        src/RayLib/RayLibText.cpp
        src/RayLib/RayLibModels.cpp
        src/RayLib/RayLibRaudio.cpp
        src/RayLib/RayLibPhysac.cpp
        src/RayLib/RayLib.hpp
        src/DynamicLibrary/DynamicLibrary.cpp
        src/DynamicLibrary/DynamicLibrary.hpp
        src/DynamicLibrary/DynamicLibraryException.cpp
        src/DynamicLibrary/DynamicLibraryException.hpp src/RayLib/RayLibModel.cpp src/RayLib/RayLibModel.hpp)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} raylib)

add_subdirectory("googletest" "googletest")
add_subdirectory("tests" "tests")

install(TARGETS bomberman)

enable_testing()
add_test(NAME bomberman COMMAND bomberman)