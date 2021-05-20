/**
 * @file Line.hpp
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

namespace RayLib {
    namespace Shapes {
        class Line {
            public:
                Line() = delete;
                Line(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, const Type::Color &color);
                Line(const Line &cpy);
                Line &operator = (const Line &cpy);
                ~Line() = default;

                inline Type::Vector<2> &getStartPos() { return (this->__startPos); }
                inline Type::Vector<2> &getEndPos() { return (this->__endPos); }
                inline Type::Color &getColor() { return (this->__color); }

                inline Type::Vector<2> getStartPos() const { return (this->__startPos); }
                inline Type::Vector<2> getEndPos() const { return (this->__endPos); }
                inline Type::Color getColor() const { return (this->__color); }

                void DrawLineV() const;

                static void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, const Type::Color &color);
                static void DrawLineV(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, const Type::Color &color);
                static void DrawLineEx(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, float thick, const Type::Color &color);
                static void DrawLineBezier(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, float thick, const Type::Color &color);
                static void DrawLineBezierQuad(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, const Type::Vector<2> &controlPos, float thick, const Type::Color &color);
                static void DrawLineStrip(const Type::Vector<2> *&points, int pointsCount, const Type::Color &color);
            protected:
            private:
                Type::Vector<2> __startPos;
                Type::Vector<2> __endPos;
                Type::Color __color;
        };
    }
}