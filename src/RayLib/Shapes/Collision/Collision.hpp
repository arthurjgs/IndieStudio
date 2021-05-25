/**
 * @file Collision.hpp
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
        class Collision {
            public:
                Collision() = default;
                ~Collision() = default;
                Collision(const Collision &cpy) = delete;
                Collision &operator = (const Collision &cpy) = delete;

                static bool CheckCollisionRecs(const Type::Rectangle &rec1, const Type::Rectangle &rec2);
                static bool CheckCollisionCircles(const Type::Vector<2> &center1, float radius1, const Type::Vector<2> &center2, float radius2);
                static bool CheckCollisionCircleRec(const Type::Vector<2> &center, float radius, const Type::Rectangle &rec);
                static bool CheckCollisionPointRec(const Type::Vector<2> &point, const Type::Rectangle &rec);
                static bool CheckCollisionPointCircle(const Type::Vector<2> &point, const Type::Vector<2> &center, float radius);
                static bool CheckCollisionPointTriangle(const Type::Vector<2> &point, const Type::Vector<2> &p1, const Type::Vector<2> &p2, const Type::Vector<2> &p3);
                static bool CheckCollisionLines(const Type::Vector<2> &startPos1, const Type::Vector<2> &endPos1, const Type::Vector<2> &startPos2, const Type::Vector<2> &endPos2, Type::Vector<2> &collisionPoint);
                static Type::Rectangle GetCollisionRec(const Type::Rectangle &rec1, const Type::Rectangle &rec2);
            protected:
            private:
        };
    }
}