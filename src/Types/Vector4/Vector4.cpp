/**
 * @file Vector4.cpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Vector4.hpp"

Types::Vector4::Vector4(const float &x, const float &y, const float &z, const float &a)
{
    this->__x = x;
    this->__y = y;
    this->__z = z;
    this->__a = a;
}

Types::Vector4::Vector4(const Vector4 &cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    this->__z = cpy.__z;
    this->__a = cpy.__a;
}

Types::Vector4::Vector4(const Vector4 &&cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    this->__z = cpy.__z;
    this->__a = cpy.__a;
}

Types::Vector4 &Types::Vector4::operator = (const Vector4 &cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    this->__z = cpy.__z;
    this->__a = cpy.__a;
    return (*this);
}

Types::Vector4 Types::Vector4::operator + (const Vector4 &val)
{
    Vector4 res(*this);

    res.__x += val.__x;
    res.__y += val.__y;
    res.__z += val.__z;
    res.__a += val.__a;
    return (res);
}

Types::Vector4 Types::Vector4::operator - (const Vector4 &val)
{
    Vector4 res(*this);

    res.__x -= val.__x;
    res.__y -= val.__y;
    res.__z -= val.__z;
    res.__a -= val.__a;   
    return (res);
}

Types::Vector4 Types::Vector4::operator / (const Vector4 &val)
{
    Vector4 res(*this);

    res.__x /= val.__x;
    res.__y /= val.__y;
    res.__z /= val.__z;
    res.__a /= val.__a;
    return (res);
}

Types::Vector4 Types::Vector4::operator * (const Vector4 &val)
{
    Vector4 res(*this);

    res.__x *= val.__x;
    res.__y *= val.__y;
    res.__z *= val.__z;
    res.__a *= val.__a;
    return (res);
}