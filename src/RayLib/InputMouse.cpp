/**
 * @file InputMouse.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "InputMouse.hpp"

RayLib::InputMouse::InputMouse()
{
}

RayLib::InputMouse::~InputMouse()
{
}

bool RayLib::InputMouse::isMouseButtonPressed(int button) const
{
    return IsMouseButtonPressed(button);
}

bool RayLib::InputMouse::isMouseButtonDown(int button) const
{
    return IsMouseButtonDown(button);
}

bool RayLib::InputMouse::isMouseButtonReleased(int button) const
{
    return IsMouseButtonReleased(button);
}

bool RayLib::InputMouse::isMouseButtonUp(int button) const
{
    return IsMouseButtonUp(button);
}

int RayLib::InputMouse::getMouseX(void) const
{
    return GetMouseX();
}

int RayLib::InputMouse::getMouseY(void) const
{
    return GetMouseX();
}

Type::Vector<2> RayLib::InputMouse::getMousePosition(void) const
{
    Vector2 res = GetMousePosition();
    Type::Vector<2> vec(res.x, res.y);
    return vec;
}

void RayLib::InputMouse::setMousePosition(int x, int y) const
{
    SetMousePosition(x, y);
}

void RayLib::InputMouse::setMouseOffset(int offsetX, int offsetY) const
{
    SetMouseOffset(offsetX, offsetY);
}

void RayLib::InputMouse::setMouseScale(float scaleX, float scaleY) const
{
    SetMouseScale(scaleX, scaleY);
}

float RayLib::InputMouse::getMouseWheelMove(void) const
{
    return GetMouseWheelMove();
}

void RayLib::InputMouse::setMouseCursor(int cursor) const
{
    SetMouseCursor(cursor);
}
