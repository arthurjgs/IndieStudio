/**
 * @file Pixel.hpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../../Types/Vector/Vector.hpp"
#include "../../../Types/Color/Color.hpp"
#include <raylib.h>

namespace RayLib {
    namespace Shapes {
        class Pixel {
            public:
                Pixel() = delete;
                Pixel(const Type::Vector<2> &position, const Type::Color &color);
                Pixel(const Pixel &cpy);
                Pixel &operator = (const Pixel &cpy);
                ~Pixel() = default;

                inline Type::Vector<2> &getPosition() { return (this->__position); }
                inline Type::Color &getColor() { return (this->__color); }

                inline Type::Vector<2> getPosition() const { return (this->__position); }
                inline Type::Color getColor() const { return (this->__color); }

                void DrawPixelV() const;

                static void DrawPixel(const int &posX, const int &posY, const Type::Color &color);
                static void DrawPixelV(const Type::Vector<2> &position, const Type::Color &color);
            protected:
            private:
                Type::Vector<2> __position;
                Type::Color __color;
        };
    }
}