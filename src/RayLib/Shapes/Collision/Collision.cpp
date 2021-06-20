/**
 * @file Collision.cpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Collision.hpp"

bool RayLib::Shapes::Collision::CheckCollisionRecs(const Type::Rectangle &rec1, const Type::Rectangle &rec2)
{
    return (::CheckCollisionRecs(
        ::Rectangle {rec1.getX(), rec1.getY(), rec1.getWidth(), rec1.getHeight()},
        ::Rectangle {rec2.getX(), rec2.getY(), rec2.getWidth(), rec2.getHeight()}
    ));
}

bool RayLib::Shapes::Collision::CheckCollisionCircles(const Type::Vector<2> &center1, float radius1, const Type::Vector<2> &center2, float radius2)
{
    return (::CheckCollisionCircles(
        ::Vector2 {center1.getX(), center1.getY()},
        radius1,
        ::Vector2 {center2.getX(), center2.getY()},
        radius2
    ));
}

bool RayLib::Shapes::Collision::CheckCollisionCircleRec(const Type::Vector<2> &center, float radius, const Type::Rectangle &rec)
{
    return (::CheckCollisionCircleRec(
        ::Vector2 {center.getX(), center.getY()},
        radius,
        ::Rectangle {rec.getX(), rec.getY(), rec.getWidth(), rec.getHeight()}
    ));
}

bool RayLib::Shapes::Collision::CheckCollisionPointRec(const Type::Vector<2> &point, const Type::Rectangle &rec)
{
    return (::CheckCollisionPointRec(
        ::Vector2 {point.getX(), point.getY()},
        ::Rectangle {rec.getX(), rec.getY(), rec.getWidth(), rec.getHeight()}
    ));
}

bool RayLib::Shapes::Collision::CheckCollisionPointCircle(const Type::Vector<2> &point, const Type::Vector<2> &center, float radius)
{
    return (::CheckCollisionPointCircle(
        ::Vector2 {point.getX(), point.getY()},
        ::Vector2 {center.getX(), center.getY()},
        radius
    ));
}

bool RayLib::Shapes::Collision::CheckCollisionPointTriangle(const Type::Vector<2> &point, const Type::Vector<2> &p1, const Type::Vector<2> &p2, const Type::Vector<2> &p3)
{
    return (::CheckCollisionPointTriangle(
        ::Vector2 {point.getX(), point.getY()},
        ::Vector2 {p1.getX(), p1.getY()},
        ::Vector2 {p2.getX(), p2.getY()},
        ::Vector2 {p3.getX(), p3.getY()}
    ));
}

bool RayLib::Shapes::Collision::CheckCollisionLines(const Type::Vector<2> &startPos1, const Type::Vector<2> &endPos1, const Type::Vector<2> &startPos2, const Type::Vector<2> &endPos2, Type::Vector<2> &collisionPoint)
{
    bool res = false;
    ::Vector2 dummy = {collisionPoint.getX(), collisionPoint.getY()};

    res = ::CheckCollisionLines(
        ::Vector2 {startPos1.getX(), startPos1.getY()},
        ::Vector2 {endPos1.getX(), endPos1.getY()},
        ::Vector2 {startPos2.getX(), startPos2.getY()},
        ::Vector2 {endPos2.getX(), endPos2.getY()},
        &dummy
    );
    float &x = collisionPoint.getX();
    float &y = collisionPoint.getY();
    x = dummy.x;
    y = dummy.y;
    return (res);
}

Type::Rectangle RayLib::Shapes::Collision::GetCollisionRec(const Type::Rectangle &rec1, const Type::Rectangle &rec2)
{
    ::Rectangle res = ::GetCollisionRec(
        ::Rectangle {rec1.getX(), rec1.getY(), rec1.getWidth(), rec1.getHeight()},
        ::Rectangle {rec2.getX(), rec2.getY(), rec2.getWidth(), rec2.getHeight()}
    );
    return (Type::Rectangle(res.x, res.y, res.width, res.height));
}
