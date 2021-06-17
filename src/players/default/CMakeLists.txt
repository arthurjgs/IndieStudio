CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(default)

SET(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

ADD_LIBRARY(default SHARED
        default.cpp
        default.hpp
        ../Player.cpp
        ../Player.hpp
        ../../Types/Vector/Vector.hpp
        ../../Game/GameObject.cpp
        ../../Game/GameObject.hpp
        ../../Game/GameException.cpp
        ../../Game/GameException.hpp
        ../../Game/Bomb/Bomb.cpp
        ../../Game/Bomb/Bomb.hpp
        ../../Game/Flame/Flame.cpp
        ../../Game/Flame/Flame.hpp
        ../../Game/SceneManager/SceneManager.cpp
        ../../Game/SceneManager/SceneManager.hpp
        ../../RayLib/Model/Animate/Animate.cpp
        ../../RayLib/Model/Animate/Animate.hpp
        ../../RayLib/Window.cpp
        ../../RayLib/InputGamepad.cpp
        ../../RayLib/InputGamepad.hpp
        ../../RayLib/InputKeyboard.cpp
        ../../RayLib/InputKeyboard.hpp
        ../../RayLib/InputGamepad.hpp
        ../../RayLib/InputMouse.cpp
        ../../RayLib/InputMouse.hpp
        ../../RayLib/Manager3D.cpp
        ../../RayLib/Manager3D.hpp
        ../../RayLib/Drawing.cpp
        ../../RayLib/Drawing.hpp
        ../../RayLib/Cursor.cpp
        ../../RayLib/Cursor.hpp
        ../../RayLib/Camera.cpp
        ../../RayLib/Camera.hpp)

target_link_libraries(${PROJECT_NAME} raylib)

SET_TARGET_PROPERTIES(default PROPERTIES PREFIX "")
