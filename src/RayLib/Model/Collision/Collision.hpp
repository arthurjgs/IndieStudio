/**
 * @file Collision.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <raylib.h>
#include "../../../Types/Vector/Vector.hpp"
#include "../../../Types/BoundingBox/BoundingBox.hpp"

namespace RayLib {
    namespace Models {
        class Collision {
            public:
                Collision() = default;
                ~Collision() = default;
                Collision(const Collision &cpy) = delete;
                Collision &operator = (const Collision &cpy) = delete;

                static bool CheckCollisionSpheres(const Type::Vector<3> &center1, float radius1, const Type::Vector<3> &center2, float radius2);
                static bool CheckCollisionBoxes(const Type::BoundingBox &box1, const Type::BoundingBox &box2);
                static bool CheckCollisionBoxSphere(const Type::BoundingBox &box, const Type::Vector<3> &center, float radius);
            protected:
            private:
        };
    }
}