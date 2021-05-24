/**
 * @file Poly.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Poly.hpp"

RayLib::Shapes::Poly::Poly(const Type::Vector<2> center, const int &sides, const float &radius, const float &rotation, const Type::Color &color) :
    __center(center),
    __color(color)
{
    this->__sides = sides;
    this->__radius = radius;
    this->__rotation = rotation;
}

RayLib::Shapes::Poly::Poly(const Poly &cpy) :
    __center(cpy.__center),
    __color(cpy.__color)
{
    this->__sides = cpy.__sides;
    this->__radius = cpy.__radius;
    this->__rotation = cpy.__rotation;
}

RayLib::Shapes::Poly &RayLib::Shapes::Poly::operator = (const Poly &cpy)
{
    this->__sides = cpy.__sides;
    this->__radius = cpy.__radius;
    this->__rotation = cpy.__rotation;
    this->__center = cpy.__center;
    this->__color = cpy.__color;
    return (*this);
}

void RayLib::Shapes::Poly::DrawPoly() const
{
    ::DrawPoly(
        ::Vector2 {this->__center.getX(), this->__center.getY()},
        this->__sides,
        this->__radius,
        this->__rotation,
        ::Color {this->__color.getR(), this->__color.getG(), this->__color.getB(), this->__color.getA()}
    );
}

void RayLib::Shapes::Poly::DrawPolyLines() const
{
    ::DrawPolyLines(
        ::Vector2 {this->__center.getX(), this->__center.getY()},
        this->__sides,
        this->__radius,
        this->__rotation,
        ::Color {this->__color.getR(), this->__color.getG(), this->__color.getB(), this->__color.getA()}
    );
}

void RayLib::Shapes::Poly::DrawPoly(const Type::Vector<2> &center, const int &sides, const float &radius, const float &rotation, const Type::Color &color)
{
    ::DrawPoly(
        ::Vector2 {center.getX(), center.getY()},
        sides,
        radius,
        rotation,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Poly::DrawPolyLines(const Type::Vector<2> &center, const int &sides, const float &radius, const float &rotation, const Type::Color &color)
{
    ::DrawPolyLines(
        ::Vector2 {center.getX(), center.getY()},
        sides,
        radius,
        rotation,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}
