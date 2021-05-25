/**
 * @file Cursor.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Cursor.hpp"

RayLib::Cursor::Cursor()
{
}

RayLib::Cursor::~Cursor()
{
}

void RayLib::Cursor::showCursor(void) const
{
    ShowCursor();
}

void RayLib::Cursor::hideCursor(void) const
{
    HideCursor();
}

bool RayLib::Cursor::isCursorHidden(void) const
{
    return IsCursorHidden();
}

void RayLib::Cursor::enableCursor(void) const
{
    EnableCursor();
}

void RayLib::Cursor::disableCursor(void) const
{
    DisableCursor();
}

bool RayLib::Cursor::isCursorOnScreen(void) const
{
    return IsCursorOnScreen();
}
