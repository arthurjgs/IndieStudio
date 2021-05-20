/**
 * @file Vector2.cpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Vector2.hpp"

Types::Vector2::Vector2(const float &x, const float &y)
{
    this->__x = x;
    this->__y = y;
}

Types::Vector2::Vector2(const Vector2 &cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
}

Types::Vector2::Vector2(const Vector2 &&cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
}

Types::Vector2 &Types::Vector2::operator = (const Vector2 &cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    return (*this);
}

Types::Vector2 Types::Vector2::operator + (const Vector2 &val)
{
    Vector2 res(*this);

    res.__x += val.__x;
    res.__y += val.__y;
    return (res);
}

Types::Vector2 Types::Vector2::operator - (const Vector2 &val)
{
    Vector2 res(*this);

    res.__x -= val.__x;
    res.__y -= val.__y;
    return (res);
}

Types::Vector2 Types::Vector2::operator / (const Vector2 &val)
{
    Vector2 res(*this);

    res.__x /= val.__x;
    res.__y /= val.__y;
    return (res);
}

Types::Vector2 Types::Vector2::operator * (const Vector2 &val)
{
    Vector2 res(*this);

    res.__x *= val.__x;
    res.__y *= val.__y;
    return (res);
}