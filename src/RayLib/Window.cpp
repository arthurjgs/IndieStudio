/**
 *  @file   RayLib.cpp
 *  @brief  RayLib Encapsulation
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/

#include "Window.hpp"
#include "raylib.h"

RayLib::Window &RayLib::Window::getInstance()
{
    static RayLib::Window win = RayLib::Window(1920, 1080, "Bomberman");
    return (win);
}

RayLib::Window::Window(float width, float height, const std::string &title)
{
    ::InitWindow(width, height, title.c_str());
    if (!::IsWindowReady()) {
        throw std::runtime_error("salut");
    }
    ::ToggleFullscreen();
    ::SetTargetFPS(::GetMonitorRefreshRate(::GetCurrentMonitor()));
    ::InitAudioDevice();
    if (!::IsAudioDeviceReady()) {
        throw std::runtime_error("salut");
    }
    this->_clock = ::GetTime();
}

float RayLib::Window::getElapsedTime()
{
    float old = this->_clock;

    this->_clock = ::GetTime();
    return (this->_clock - old);
}

bool RayLib::Window::isOpen() const
{
    return (!::WindowShouldClose());
}

void RayLib::Window::draw() const
{
    ::BeginDrawing();
    ::ClearBackground(::RAYWHITE);
    // TODO: call scene draw method
    ::EndDrawing();
}

RayLib::InputMouse RayLib::Window::getInputMouse() const
{
    return _inputMouse;
}

RayLib::InputKeyboard RayLib::Window::getInputKeyboard() const
{
    return _inputKeyboard;
}

RayLib::InputGamepad RayLib::Window::getInputGamepad() const
{
    return _inputGamepad;
}

RayLib::Drawing RayLib::Window::getDrawing() const
{
    return _drawing;
}

RayLib::Window::~Window()
{
    ::CloseAudioDevice();
    ::CloseWindow();
}
