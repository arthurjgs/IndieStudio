/**
 * @file Vector3.cpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Vector3.hpp"

Types::Vector3::Vector3(const float &x, const float &y, const float &z)
{
    this->__x = x;
    this->__y = y;
    this->__z = z;
}

Types::Vector3::Vector3(const Vector3 &cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    this->__z = cpy.__z;   
}

Types::Vector3::Vector3(const Vector3 &&cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    this->__z = cpy.__z;   
}

Types::Vector3 &Types::Vector3::operator = (const Vector3 &cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    this->__z = cpy.__z;   
    return (*this);
}

Types::Vector3 Types::Vector3::operator + (const Vector3 &val)
{
    Vector3 res(*this);

    res.__x += val.__x;
    res.__y += val.__y;
    res.__z += val.__z;
    return (res);
}

Types::Vector3 Types::Vector3::operator - (const Vector3 &val)
{
    Vector3 res(*this);

    res.__x -= val.__x;
    res.__y -= val.__y;
    res.__z -= val.__z;
    return (res);
}

Types::Vector3 Types::Vector3::operator / (const Vector3 &val)
{
    Vector3 res(*this);

    res.__x /= val.__x;
    res.__y /= val.__y;
    res.__z /= val.__z;
    return (res);
}

Types::Vector3 Types::Vector3::operator * (const Vector3 &val)
{
    Vector3 res(*this);

    res.__x *= val.__x;
    res.__y *= val.__y;
    res.__z *= val.__z;
    return (res);
}