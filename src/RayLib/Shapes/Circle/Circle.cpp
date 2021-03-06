/**
 * @file Circle.cpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Circle.hpp"

RayLib::Shapes::Circle::Circle(const int &centerX, const int &centerY, const float &radius, const Type::Color &col) :
    __col(col)
{
    this->__centerX = centerX;
    this->__centerY = centerY;
    this->__radius = radius;
}

RayLib::Shapes::Circle::Circle(const Circle &cpy) :
    __col(cpy.__col)
{
    this->__centerX = cpy.__centerX;
    this->__centerY = cpy.__centerY;
    this->__radius = cpy.__radius;
}

RayLib::Shapes::Circle &RayLib::Shapes::Circle::operator = (const Circle &cpy)
{
    this->__col = cpy.__col;
    this->__centerX = cpy.__centerX;
    this->__centerY = cpy.__centerY;
    this->__radius = cpy.__radius;
    return (*this);
}

void RayLib::Shapes::Circle::DrawCircle(const int &centerX, const int &centerY, const float &radius, const Type::Color &col)
{
    ::DrawCircle(centerX, centerY, radius, ::Color{col.getR(), col.getG(), col.getB(), col.getA() });
}

void RayLib::Shapes::Circle::DrawCircleSector(const Type::Vector<2> &vec, float radius, float startAngle, float endAngle, int segments, const Type::Color &col)
{
    ::DrawCircleSector(::Vector2{vec.getX(), vec.getY()}, radius, startAngle, endAngle, segments, ::Color{ col.getR(), col.getG(), col.getB(), col.getA() });
}

void RayLib::Shapes::Circle::DrawCircleSectorLines(const Type::Vector<2> &center, float radius, float startAngle, float endAngle, int segments, const Type::Color & color)
{
    ::DrawCircleSector(::Vector2{ center.getX(), center.getY() }, radius, startAngle, endAngle, segments, ::Color{ color.getR(), color.getG(), color.getB(), color.getA() });
}

void RayLib::Shapes::Circle::DrawCircleGradient(int centerX, int centerY, float radius, const Type::Color & color1, const Type::Color & color2)
{
    ::DrawCircleGradient(centerX, centerY, radius, ::Color{ color1.getR(), color1.getG(), color1.getB(), color1.getA() }, ::Color{ color2.getR(), color2.getG(), color2.getB(), color2.getA() });
}

void RayLib::Shapes::Circle::DrawCircleV(const Type::Vector<2> &center, float radius, const Type::Color &color)
{
    ::DrawCircleV(::Vector2{center.getX(), center.getY()}, radius, ::Color{ color.getR(), color.getG(), color.getB(), color.getA() });
}

void RayLib::Shapes::Circle::DrawCircleLines(int centerX, int centerY, float radius, const Type::Color & color)
{
    ::DrawCircleLines(centerX, centerY, radius, ::Color{ color.getR(), color.getG(), color.getB(), color.getA() });
}

void RayLib::Shapes::Circle::DrawCircle() const
{
    ::DrawCircle(this->__centerX, this->__centerY, this->__radius, ::Color{this->__col.getR(), this->__col.getG(), this->__col.getB(), this->__col.getA()});
}