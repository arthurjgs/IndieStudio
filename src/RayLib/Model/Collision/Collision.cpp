/**
 * @file Collision.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Collision.hpp"

bool CheckCollisionSpheres(const Type::Vector<3> &center1, float radius1, const Type::Vector<3> &center2, float radius2)
{
    return (
        ::CheckCollisionSpheres(
            ::Vector3 {center1.getX(), center1.getY(), center1.getZ()},
            radius1,
            ::Vector3 {center2.getX(), center2.getY(), center2.getZ()},
            radius2
        )
    );
}

bool CheckCollisionBoxes(const Type::BoundingBox &box1, const Type::BoundingBox &box2)
{
    return (
        ::CheckCollisionBoxes(
            ::BoundingBox {
                ::Vector3 {box1.getMin().getX(), box1.getMin().getY(), box1.getMin().getZ()},
                ::Vector3 {box1.getMax().getX(), box1.getMax().getY(), box1.getMax().getZ()}
            },
            ::BoundingBox {
                ::Vector3 {box2.getMin().getX(), box2.getMin().getY(), box2.getMin().getZ()},
                ::Vector3 {box2.getMax().getX(), box2.getMax().getY(), box2.getMax().getZ()}
            }
        )
    );
}

bool CheckCollisionBoxSphere(const Type::BoundingBox &box, const Type::Vector<3> &center, float radius)
{
    return (
        ::CheckCollisionBoxSphere(
            ::BoundingBox {
                ::Vector3 {box.getMin().getX(), box.getMin().getY(), box.getMin().getZ()},
                ::Vector3 {box.getMax().getX(), box.getMax().getY(), box.getMax().getZ()}
            },
            ::Vector3 {center.getX(), center.getY(), center.getZ()},
            radius
        )
    );
}
