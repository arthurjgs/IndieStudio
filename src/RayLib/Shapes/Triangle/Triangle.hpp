/**
 * @file Triangle.hpp
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
        class Triangle {
            public:
                Triangle() = delete;
                Triangle(const Type::Vector<2> &v1, const Type::Vector<2> &v2, const Type::Vector<2> &v3, const Type::Color &color);
                ~Triangle() = default;
                Triangle(const Triangle &cpy);
                Triangle &operator = (const Triangle &cpy);

                inline Type::Vector<2> &getV1() { return (this->__v1); }
                inline Type::Vector<2> &getV2() { return (this->__v2); }
                inline Type::Vector<2> &getV3() { return (this->__v3); }
                inline Type::Color &getColor() { return (this->__color); }

                inline Type::Vector<2> getV1() const { return (this->__v1); }
                inline Type::Vector<2> getV2() const { return (this->__v2); }
                inline Type::Vector<2> getV3() const { return (this->__v3); }
                inline Type::Color getColor() const { return (this->__color); }
                
                void DrawTriangle() const;

                static void DrawTriangle(const Type::Vector<2> &v1, const Type::Vector<2> &v2, const Type::Vector<2> &v3, const Type::Color &color);
                static void DrawTriangleLines(const Type::Vector<2> &v1, const Type::Vector<2> &v2, const Type::Vector<2> &v3, const Type::Color &color);
                static void DrawTriangleFan(Type::Vector<2> &points, const int &pointsCount, const Type::Color &color);
                static void DrawTriangleStrip(Type::Vector<2> &points, const int &pointsCount, const Type::Color &color);    
            protected:
            private:
                Type::Vector<2> __v1;
                Type::Vector<2> __v2;
                Type::Vector<2> __v3;
                Type::Color __color;
        };
    }
}