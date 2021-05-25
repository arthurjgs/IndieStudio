/**
 * @file Ring.hpp
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
        class Ring {
            public:
                Ring() = delete;
                Ring(const Type::Vector<2> &center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, const Type::Color &color);
                Ring(const Ring &cpy);
                Ring &operator = (const Ring &cpy);
                ~Ring() = default;
                
                inline Type::Vector<2> &getCenter() { return (this->__center); }
                inline float &getInnerRadius() { return (this->__innerRadius); }
                inline float &getOuterRadius() { return (this->__outerRadius); }
                inline float &getStartAngle() { return (this->__startAngle); }
                inline float &getEndAngle() { return (this->__endAngle); }
                inline int &getSegments() { return (this->__segments); }
                inline Type::Color &getColor() { return (this->__color); }

                inline Type::Vector<2> getCenter() const { return (this->__center); }
                inline float getInnerRadius() const { return (this->__innerRadius); }
                inline float getOuterRadius() const { return (this->__outerRadius); }
                inline float getStartAngle() const { return (this->__startAngle); }
                inline float getEndAngle() const { return (this->__endAngle); }
                inline int getSegments() const { return (this->__segments); }
                inline Type::Color getColor() const { return (this->__color); }

                void DrawRing() const;
                void DrawRingLines() const;

                static void DrawRing(const Type::Vector<2> &center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, const Type::Color &color);
                static void DrawRingLines(const Type::Vector<2> &center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, const Type::Color &color);
            protected: 
            private:
                Type::Vector<2> __center;
                float __innerRadius;
                float __outerRadius;
                float __startAngle;
                float __endAngle;
                int __segments;
                Type::Color __color;
        };
    }
}