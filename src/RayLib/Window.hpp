/**
 *  @file   RayLib.cpp
 *  @brief  RayLib Encapsulation Header
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/


#ifndef BOMBERMAN_RAYLIB_HPP
#define BOMBERMAN_RAYLIB_HPP

#include <raylib.h>
#include <iostream>
#include "InputKeyboard.hpp"
#include "InputMouse.hpp"
#include "InputGamepad.hpp"
#include "Cursor.hpp"
#include "Drawing.hpp"

namespace RayLib
{
    class Window {
        public:
            static Window &getInstance();
            float getElapsedTime();
            bool isOpen() const;
            void draw() const;
            RayLib::InputMouse getInputMouse() const;
            RayLib::InputKeyboard getInputKeyboard() const;
            RayLib::InputGamepad getInputGamepad() const;
            RayLib::Cursor getCursor() const;
            RayLib::Drawing getDrawing() const;
        private:
            Window() = delete;
            Window(float width, float height, const std::string &title);
            Window(const Window &) = delete;
            Window &operator = (const Window &) = delete;
            ~Window();
            float _clock;
            RayLib::InputMouse _inputMouse;
            RayLib::InputKeyboard _inputKeyboard;
            RayLib::InputGamepad _inputGamepad;
            RayLib::Cursor _cursor;
            RayLib::Drawing _drawing;

        protected:
    };
}

#endif //BOMBERMAN_RAYLIB_HPP
