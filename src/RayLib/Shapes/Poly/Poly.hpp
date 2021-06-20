/**
 * @file Poly.hpp
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
        class Poly {
            public:
                Poly() = delete;
                Poly(const Type::Vector<2> center, const int &Sides, const float &radius, const float &rotation, const Type::Color &color);
                Poly(const Poly &cpy);
                Poly &operator = (const Poly &cpy);
                ~Poly();
                
                inline Type::Vector<2> &getCenter() { return (this->__center); }
                inline int &getSides() { return (this->__sides); }
                inline float &getRadius() { return (this->__radius); }
                inline float &getRotation() { return (this->__rotation); }
                inline Type::Color &getColor() { return (this->__color); }

                inline Type::Vector<2> getCenter() const { return (this->__center); }
                inline int getSides() const { return (this->__sides); }
                inline float getRadius() const { return (this->__radius); }
                inline float getRotation() const { return (this->__rotation); }
                inline Type::Color getColor() const { return (this->__color); }

                void DrawPoly() const;
                void DrawPolyLines() const;

                void DrawPoly(const Type::Vector<2> &center, const int &Sides, const float &radius, const float &rotation, const Type::Color &color);
                void DrawPolyLines(const Type::Vector<2> &center, const int &Sides, const float &radius, const float &rotation, const Type::Color &color);
            protected:
            private:
                Type::Vector<2> __center;
                int __sides;
                float __radius;
                float __rotation;
                Type::Color __color;
        };
    }
}