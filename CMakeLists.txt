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

find_package(raylib REQUIRED)

add_executable(bomberman
        src/main.cpp
        src/RayLib/Shapes/Circle/Circle.cpp
        src/RayLib/Shapes/Collision/Collision.cpp
        src/RayLib/Shapes/Ellipse/Ellipse.cpp
        src/RayLib/Shapes/Line/Line.cpp
        src/RayLib/Shapes/Pixel/Pixel.cpp
        src/RayLib/Shapes/Poly/Poly.cpp
        src/RayLib/Shapes/Rectangle/Rectangle.cpp
        src/RayLib/Shapes/Ring/Ring.cpp
        src/RayLib/Shapes/Triangle/Triangle.cpp
        src/RayLib/Text/Text.cpp
        src/RayLib/Audio/AudioStream/AudioStream.cpp
        src/RayLib/Audio/Music/Music.cpp
        src/RayLib/Audio/Sound/Sound.cpp
        src/Types/Color/Color.cpp
        src/Types/Image/Image.cpp
        src/Types/Matrix/Matrix.cpp
        src/Types/Rectangle/Rectangle.cpp
        src/Types/Texture/Texture.cpp
        src/RayLib/Window.cpp
        src/RayLib/InputKeyboard.cpp
        src/RayLib/InputMouse.cpp
        src/RayLib/InputGamepad.cpp
        src/RayLib/Cursor.cpp
        )

target_link_libraries(${PROJECT_NAME} raylib)

install(TARGETS bomberman)

enable_testing()
add_test(NAME bomberman COMMAND bomberman)