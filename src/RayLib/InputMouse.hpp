/**
 * @file InputMouse.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INPUTMOUSE_HPP_
#define INPUTMOUSE_HPP_

#include <raylib.h>
#include <iostream>
#include "../Types/Vector/Vector.hpp"

namespace RayLib
{
    class InputMouse {
        public:
            InputMouse();
            ~InputMouse();
            bool isMouseButtonPressed(int button) const;
            bool isMouseButtonDown(int button) const;
            bool isMouseButtonReleased(int button) const;
            bool isMouseButtonUp(int button) const;
            int getMouseX(void) const;
            int getMouseY(void) const;
            Type::Vector<2> getMousePosition(void) const;
            void setMousePosition(int x, int y) const;
            void setMouseOffset(int offsetX, int offsetY) const;
            void setMouseScale(float scaleX, float scaleY) const;
            float getMouseWheelMove(void) const;
            void setMouseCursor(int cursor) const;

        protected:
        private:
    };
}

#endif /* !INPUTMOUSE_HPP_ */
