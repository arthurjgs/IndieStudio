/**
 * @file Ellipse.hpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../../Types/Color/Color.hpp"
#include <raylib.h>

namespace RayLib {
    namespace Shapes {
        class Ellipse {
            public:
                Ellipse() = delete;
                Ellipse(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Type::Color &color);
                ~Ellipse() = default;
                Ellipse(const Ellipse &cpy);
                Ellipse &operator = (const Ellipse &cpy);

                inline int &getCenterX() { return (this->__centerX); }
                inline int &getCenterY() { return (this->__centerY); }
                inline float &getRadiusH() { return (this->__radiusH); }
                inline float &getRadiusV() { return (this->__radiusV); }
                inline Type::Color &getColor() { return (this->__color); }

                inline int getCenterX() const { return (this->__centerX); }
                inline int getCenterY() const { return (this->__centerY); }
                inline float getRadiusH() const { return (this->__radiusH); }
                inline float getRadiusV() const { return (this->__radiusV); }
                inline Type::Color getColor() const { return (this->__color); }

                void DrawEllipse() const;
                void DrawEllipseLines() const;
                void DrawEllipse(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Type::Color &color);
                void DrawEllipseLines(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Type::Color &color);       
            protected:
            private:
                int __centerX;
                int __centerY;
                float __radiusH;
                float __radiusV;
                Type::Color __color;
        };
    }
}