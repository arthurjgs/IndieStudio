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
__min(min),
__max(max)
{
}

Type::BoundingBox::BoundingBox(const BoundingBox &cpy) :
__min(cpy.__min),
__max(cpy.__max)
{
}

Type::BoundingBox &Type::BoundingBox::operator = (const BoundingBox &cpy)
{
    this->__min = cpy.__min;
    this->__max = cpy.__max;
    return (*this);
}

Type::BoundingBox Type::BoundingBox::operator + (const BoundingBox &cpy)
{
    BoundingBox res(*this);

    res.__min += cpy.__min;
    res.__max += cpy.__max;
    return (res);
}

Type::BoundingBox &Type::BoundingBox::operator += (const BoundingBox &cpy)
{
    this->__min += cpy.__min;
    this->__max += cpy.__max;
    return (*this);
}

Type::BoundingBox Type::BoundingBox::operator - (const BoundingBox &cpy)
{
    BoundingBox res(*this);

    res.__min -= cpy.__min;
    res.__max -= cpy.__max;
    return (res);
}

Type::BoundingBox &Type::BoundingBox::operator -= (const BoundingBox &cpy)
{
    this->__min -= cpy.__min;
    this->__max -= cpy.__max;
    return (*this);
}

Type::BoundingBox Type::BoundingBox::operator * (const BoundingBox &cpy)
{
    BoundingBox res(*this);

    res.__min *= cpy.__min;
    res.__max *= cpy.__max;
    return (res);
}

Type::BoundingBox &Type::BoundingBox::operator *= (const BoundingBox &cpy)
{
    this->__min *= cpy.__min;
    this->__max *= cpy.__max;
    return (*this);
}

Type::BoundingBox Type::BoundingBox::operator / (const BoundingBox &cpy)
{
    BoundingBox res(*this);

    res.__min /= cpy.__min;
    res.__max /= cpy.__max;
    return (res);
}

Type::BoundingBox &Type::BoundingBox::operator /= (const BoundingBox &cpy)
{
    this->__min /= cpy.__min;
    this->__max /= cpy.__max;
    return (*this);
}