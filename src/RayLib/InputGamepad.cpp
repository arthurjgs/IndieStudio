/**
 * @file InputGamepad.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "InputGamepad.hpp"

RayLib::InputGamepad::InputGamepad()
{
}

RayLib::InputGamepad::~InputGamepad()
{
}

bool RayLib::InputGamepad::isGamepadAvailable(int gamepad) const
{
    return IsGamepadAvailable(gamepad);
}

bool RayLib::InputGamepad::isGamepadName(int gamepad, const std::string &name) const
{
    return IsGamepadName(gamepad, name.c_str());
}

const std::string RayLib::InputGamepad::getGamepadName(int gamepad) const
{
    return std::string(GetGamepadName(gamepad));
}

bool RayLib::InputGamepad::isGamepadButtonPressed(int gamepad, int button) const
{
    return IsGamepadButtonPressed(gamepad, button);
}

bool RayLib::InputGamepad::isGamepadButtonDown(int gamepad, int button) const
{
    return IsGamepadButtonDown(gamepad, button);
}

bool RayLib::InputGamepad::isGamepadButtonReleased(int gamepad, int button) const
{
    return IsGamepadButtonReleased(gamepad, button);
}

bool RayLib::InputGamepad::isGamepadButtonUp(int gamepad, int button) const
{
    return IsGamepadButtonUp(gamepad, button);
}

int RayLib::InputGamepad::getGamepadButtonPressed(void) const
{
    return GetGamepadButtonPressed();
}

int RayLib::InputGamepad::getGamepadAxisCount(int gamepad) const
{
    return GetGamepadAxisCount(gamepad);
}

float RayLib::InputGamepad::getGamepadAxisMovement(int gamepad, int axis) const
{
    return getGamepadAxisMovement(gamepad, axis);
}

int RayLib::InputGamepad::setGamepadMappings(const std::string &mappings) const
{
    return SetGamepadMappings(mappings.c_str());
}
