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
}

void RayLib::Shapes::Circle::DrawCircle(const int &centerX, const int &centerY, const float &radius, const Type::Color &col)
{
    ::Color dummy = {
        .r = col.getR(),
        .g = col.getG(),
        .b = col.getB(),
        .a = col.getA()
    };
    ::DrawCircle(centerX, centerY, radius, dummy);
}

void RayLib::Shapes::Circle::DrawCircleSector(const Type::Vector<2> &vec, float radius, float startAngle, float endAngle, int segments, const Type::Color &col)
{
    ::Vector2 dummyVec = {
        .x = vec.getX(),
        .y = vec.getY()
    };
    ::Color dummyCol = {
        .r = col.getR(),
        .g = col.getG(),
        .b = col.getB(),
        .a = col.getA()
    };
    ::DrawCircleSector(dummyVec, radius, startAngle, endAngle, segments, dummyCol);
}

void RayLib::Shapes::Circle::DrawCircleSectorLines(const Type::Vector<2> &center, float radius, float startAngle, float endAngle, int segments, const Type::Color & color)
{
    ::Vector2 dummyVec = {
        .x = center.getX(),
        .y = center.getY()
    };
    ::Color dummyCol = {
        .r = color.getR(),
        .g = color.getG(),
        .b = color.getB(),
        .a = color.getA()
    };
    ::DrawCircleSectorLines(dummyVec, radius, startAngle, endAngle, segments, dummyCol);
}

void RayLib::Shapes::Circle::DrawCircleGradient(int centerX, int centerY, float radius, const Type::Color & color1, const Type::Color & color2)
{
    ::Color dummyCol1 = {
        .r = color1.getR(),
        .g = color1.getG(),
        .b = color1.getB(),
        .a = color1.getA()
    };
    ::Color dummyCol2 = {
        .r = color2.getR(),
        .g = color2.getG(),
        .b = color2.getB(),
        .a = color2.getA()
    };
    ::DrawCircleGradient(centerX, centerY, radius, dummyCol1, dummyCol2);
}

void RayLib::Shapes::Circle::DrawCircleV(const Type::Vector<2> &center, float radius, const Type::Color &color)
{
    ::Vector2 dummyVec = {
        .x = center.getX(),
        .y = center.getY()
    };
    ::Color dummyCol = {
        .r = color.getR(),
        .g = color.getG(),
        .b = color.getB(),
        .a = color.getA()
    };
    ::DrawCircleV(dummyVec, radius, dummyCol);
}

void RayLib::Shapes::Circle::DrawCircleLines(int centerX, int centerY, float radius, const Type::Color & color)
{
    ::Color dummyCol = {
        .r = color.getR(),
        .g = color.getG(),
        .b = color.getB(),
        .a = color.getA()
    };
    ::DrawCircleLines(centerX, centerY, radius, dummyCol);
}

void RayLib::Shapes::Circle::DrawCircle() const
{
    ::Color dummy = {
        .r = this->__col.getR(),
        .g = this->__col.getG(),
        .b = this->__col.getB(),
        .a = this->__col.getA()
    };
    ::DrawCircle(this->__centerX, this->__centerY, this->__radius, dummy);
}