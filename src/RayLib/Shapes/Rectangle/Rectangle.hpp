/**
 * @file Rectangle.hpp
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
#include "../../../Types/Rectangle/Rectangle.hpp"
#include <raylib.h>

namespace RayLib {
    namespace Shapes {
        class Rectangle {
            public:
                Rectangle() = delete;
                ~Rectangle() = default;
                Rectangle(const Type::Vector<2> &position, const Type::Vector<2> &size, const Type::Color &color);
                Rectangle(const Rectangle &cpy);
                Rectangle &operator = (const Rectangle &cpy);

                inline Type::Vector<2> &getPosition() { return (this->__position); }
                inline Type::Vector<2> &getSize() { return (this->__size); }
                inline Type::Color &getColor() { return (this->__color); }

                inline Type::Vector<2> getPosition() const { return (this->__position); }
                inline Type::Vector<2> getSize() const { return (this->__size); }
                inline Type::Color getColor() const { return (this->__color); }

                void DrawRectangleV() const;

                static void DrawRectangle(int posX, int posY, int width, int height, const Type::Color &color);
                static void DrawRectangleV(const Type::Vector<2> &position, const Type::Vector<2> &size, const Type::Color &color);
                static void DrawRectangleRec(const Type::Rectangle &rec, const Type::Color &color);
                static void DrawRectanglePro(const Type::Rectangle &rec, const Type::Vector<2> &origin, float rotation, const Type::Color &color);
                static void DrawRectangleGradientV(int posX, int posY, int width, int height, const Type::Color &color1, const Type::Color &color2);
                static void DrawRectangleGradientH(int posX, int posY, int width, int height, const Type::Color &color1, const Type::Color &color2);
                static void DrawRectangleGradientEx(const Type::Rectangle &rec, const Type::Color &col1, const Type::Color &col2, const Type::Color &col3, const Type::Color &col4);
                static void DrawRectangleLines(int posX, int posY, int width, int height, const Type::Color &color);
                static void DrawRectangleLinesEx(const Type::Rectangle &rec, int lineThick, const Type::Color &color);
                static void DrawRectangleRounded(const Type::Rectangle &rec, float roundness, int segments, const Type::Color &color);
                static void DrawRectangleRoundedLines(const Type::Rectangle &rec, float roundness, int segments, int lineThick, const Type::Color &color);
            protected:
            private:
                Type::Vector<2> __position;
                Type::Vector<2> __size;
                Type::Color __color;
        };
    }
}