/**
 * @file Circle.hpp
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
        class Circle {
            public:
                Circle() = delete;
                Circle(const int &centerX, const int &centerY, const float &radius, const Type::Color &col);
                Circle(const Circle &cpy);
                Circle &operator = (const Circle &cpy);
                ~Circle() = default;

                inline int &getCenterX() { return (this->__centerX); }
                inline int &getCenterY() { return (this->__centerY); }
                inline float &getRadius() { return (this->__radius); }
                inline Type::Color &getCol() { return (this->__col); }

                inline int getCenterX() const { return (this->__centerX); }
                inline int getCenterY() const { return (this->__centerY); }
                inline float getRadius() const { return (this->__radius); }
                inline Type::Color getCol() const { return (this->__col); }

                void DrawCircle() const;
                
                static void DrawCircle(const int &centerX, const int &centerY, const float &radius, const Type::Color &col);
                static void DrawCircleSector(const Type::Vector<2> &vec, float radius, float startAngle, float endAngle, int segments, const Type::Color &col);
                static void DrawCircleSectorLines(const Type::Vector<2> &center, float radius, float startAngle, float endAngle, int segments, const Type::Color & color);
                static void DrawCircleGradient(int centerX, int centerY, float radius, const Type::Color & color1, const Type::Color & color2);
                static void DrawCircleV(const Type::Vector<2> &center, float radius, const Type::Color & color);
                static void DrawCircleLines(int centerX, int centerY, float radius, const Type::Color & color);
            private:
                int __centerX;
                int __centerY;
                float __radius;
                Type::Color __col;
            protected:
        };
    }
}
