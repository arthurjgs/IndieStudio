/**
 * @file InputKeyboard.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "InputKeyboard.hpp"

RayLib::InputKeyboard::InputKeyboard()
{
}

RayLib::InputKeyboard::~InputKeyboard()
{
}

bool RayLib::InputKeyboard::isKeyPressed(int key) const
{
    return IsKeyPressed(key);
}

bool RayLib::InputKeyboard::isKeyDown(int key) const
{
    return IsKeyDown(key);
}

bool RayLib::InputKeyboard::isKeyReleased(int key) const
{
    return IsKeyReleased(key);
}

bool RayLib::InputKeyboard::isKeyUp(int key) const
{
    return IsKeyUp(key);
}

void RayLib::InputKeyboard::setExitKey(int key) const
{
    SetExitKey(key);
}

int RayLib::InputKeyboard::getKeyPressed(void) const
{
    return GetKeyPressed();
}

int RayLib::InputKeyboard::getCharPressed(void) const
{
    return GetCharPressed();
}