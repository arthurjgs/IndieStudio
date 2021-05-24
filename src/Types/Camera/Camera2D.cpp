/**
 * @file Camera2D.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Camera2D.hpp"

Type::Camera2D::Camera2D(const Type::Vector<2> offset, const Type::Vector<2> target, const float rotation, const float zoom)
{
    _offset = offset;
    _target = target;
    _rotation = rotation;
    _zoom = zoom;
}

Type::Camera2D::Camera2D(const Type::Camera2D &cpy)
{
    _offset = cpy._offset;
    _target = cpy._target;
    _rotation = cpy._rotation;
    _zoom = cpy._zoom;
}

Type::Camera2D Type::Camera2D::operator =(const Camera2D &cpy)
{
    _offset = cpy._offset;
    _target = cpy._target;
    _rotation = cpy._rotation;
    _zoom = cpy._zoom;
    return (*this);
}