/**
 * @file Cursor.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CURSOR_HPP_
#define CURSOR_HPP_

#include <raylib.h>
#include <iostream>

namespace RayLib
{
    class Cursor {
        public:
            Cursor();
            ~Cursor();
            void showCursor(void) const;
            void hideCursor(void) const;
            bool isCursorHidden(void) const;
            void enableCursor(void) const;
            void disableCursor(void) const;
            bool isCursorOnScreen(void) const;

        protected:
        private:
    };
}

#endif /* !CURSOR_HPP_ */
