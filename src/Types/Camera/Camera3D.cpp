/**
 * @file Camera3D.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Camera3D.hpp"

Type::Camera3D::Camera3D(Type::Vector<3> position, Type::Vector<3> target, Type::Vector<3> up, float fovy, int projection)
{
    _position = position;
    _target = target;
    _up = up;
    _fovy = fovy;
    _projection = projection;
}

Type::Camera3D::Camera3D(const Camera3D &cpy)
{
    _position = cpy._position;
    _target = cpy._target;
    _up = cpy._up;
    _fovy = cpy._fovy;
    _projection = cpy._projection;
}

Type::Camera3D Type::Camera3D::operator =(const Camera3D &cpy)
{
    _position = cpy._position;
    _target = cpy._target;
    _up = cpy._up;
    _fovy = cpy._fovy;
    _projection = cpy._projection;
    return (*this);
}
