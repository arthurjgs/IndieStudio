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
        src/DynamicLibrary/DynamicLibrary.cpp
        src/DynamicLibrary/DynamicLibrary.hpp
        src/DynamicLibrary/DynamicLibraryException.cpp
        src/DynamicLibrary/DynamicLibraryException.hpp
        src/RayLib/Model/Animate/Animate.cpp
        src/RayLib/Model/SimpleModel/SimpleModel.cpp
        src/RayLib/Model/Collision/Collision.cpp
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
        src/RayLib/Window.cpp
        src/RayLib/InputKeyboard.cpp
        src/RayLib/InputMouse.cpp
        src/RayLib/InputGamepad.cpp
        src/RayLib/Cursor.cpp
        src/Types/Camera/Camera2D.cpp
        src/Types/Camera/Camera3D.cpp
        src/Types/RenderTexture/Texture.cpp
        src/Types/RenderTexture/RenderTexture.cpp
        src/RayLib/Drawing.cpp
        src/RayLib/Texture/Texture.cpp
        src/RayLib/Camera.cpp
        src/Game/GameObject.cpp src/Game/GameObject.hpp)
        
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} raylib)
add_subdirectory("googletest" "googletest")
add_subdirectory("tests" "tests")

install(TARGETS bomberman)

enable_testing()