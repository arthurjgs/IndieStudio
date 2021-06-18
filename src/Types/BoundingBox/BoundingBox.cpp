/**
 * @file BoundingBox.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "BoundingBox.hpp"

Type::BoundingBox::BoundingBox(const Vector<3> &min, const Vector<3> &max) :
_min(min),
_max(max)
{
}

Type::BoundingBox::BoundingBox(const BoundingBox &cpy) :
_min(cpy._min),
_max(cpy._max)
{
}

Type::BoundingBox &Type::BoundingBox::operator = (const BoundingBox &cpy)
{
    this->_min = cpy._min;
    this->_max = cpy._max;
    return (*this);
}

Type::BoundingBox Type::BoundingBox::operator + (const BoundingBox &cpy)
{
    BoundingBox res(*this);

    res._min += cpy._min;
    res._max += cpy._max;
    return (res);
}

Type::BoundingBox &Type::BoundingBox::operator += (const BoundingBox &cpy)
{
    this->_min += cpy._min;
    this->_max += cpy._max;
    return (*this);
}

Type::BoundingBox Type::BoundingBox::operator - (const BoundingBox &cpy)
{
    BoundingBox res(*this);

    res._min -= cpy._min;
    res._max -= cpy._max;
    return (res);
}

Type::BoundingBox &Type::BoundingBox::operator -= (const BoundingBox &cpy)
{
    this->_min -= cpy._min;
    this->_max -= cpy._max;
    return (*this);
}

Type::BoundingBox Type::BoundingBox::operator * (const BoundingBox &cpy)
{
    BoundingBox res(*this);

    res._min *= cpy._min;
    res._max *= cpy._max;
    return (res);
}

Type::BoundingBox &Type::BoundingBox::operator *= (const BoundingBox &cpy)
{
    this->_min *= cpy._min;
    this->_max *= cpy._max;
    return (*this);
}

Type::BoundingBox Type::BoundingBox::operator / (const BoundingBox &cpy)
{
    BoundingBox res(*this);

    res._min /= cpy._min;
    res._max /= cpy._max;
    return (res);
}

Type::BoundingBox &Type::BoundingBox::operator /= (const BoundingBox &cpy)
{
    this->_min /= cpy._min;
    this->_max /= cpy._max;
    return (*this);
}