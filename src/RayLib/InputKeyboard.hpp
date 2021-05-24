/**
 * @file InputKeyboard.hpp
 * @author alexandre burger
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INPUTKEYBOARD_HPP_
#define INPUTKEYBOARD_HPP_

#include <raylib.h>
#include <iostream>

namespace RayLib
{
    class InputKeyboard {
        public:
            InputKeyboard();
            ~InputKeyboard();
            bool isKeyPressed(int key) const;
            bool isKeyDown(int key) const;
            bool isKeyReleased(int key) const;
            bool isKeyUp(int key) const;
            void setExitKey(int key) const;
            int getKeyPressed(void) const;
            int getCharPressed(void) const;
        protected:
        private:
    };
}

#endif /* !INPUTKEYBOARD_HPP_ */
