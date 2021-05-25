/**
 * @file Rectangle.cpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Rectangle.hpp"

Type::Rectangle::Rectangle(const float &x, const float &y, const float &width, const float &height)
{
    this->__x = x;
    this->__y = y;
    this->__width = width;
    this->__height = height;
}

Type::Rectangle::Rectangle(const Rectangle &cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    this->__width = cpy.__width;
    this->__height = cpy.__height;
}

Type::Rectangle::Rectangle(const Rectangle &&cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    this->__width = cpy.__width;
    this->__height = cpy.__height;
}

Type::Rectangle &Type::Rectangle::operator = (const Rectangle &cpy)
{
    this->__x = cpy.__x;
    this->__y = cpy.__y;
    this->__width = cpy.__width;
    this->__height = cpy.__height;
    return (*this);
}

Type::Rectangle Type::Rectangle::operator + (const Rectangle &val)
{
    Rectangle res(*this);
    
    res.__x += val.__x;
    res.__y += val.__y;
    res.__width += val.__width;
    res.__height += val.__height;
    return (res);
}

Type::Rectangle Type::Rectangle::operator - (const Rectangle &val)
{
    Rectangle res(*this);
    
    res.__x -= val.__x;
    res.__y -= val.__y;
    res.__width -= val.__width;
    res.__height -= val.__height;
    return (res);
}

Type::Rectangle Type::Rectangle::operator * (const Rectangle &val)
{
    Rectangle res(*this);
    
    res.__x *= val.__x;
    res.__y *= val.__y;
    res.__width *= val.__width;
    res.__height *= val.__height;
    return (res);
}

Type::Rectangle Type::Rectangle::operator / (const Rectangle &val)
{
    Rectangle res(*this);
    
    res.__x /= val.__x;
    res.__y /= val.__y;
    res.__width /= val.__width;
    res.__height /= val.__height;
    return (res);
}