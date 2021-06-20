/**
 * @file Ring.cpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Ring.hpp"

RayLib::Shapes::Ring::Ring(const Type::Vector<2> &center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, const Type::Color &color) :
    __center(center),
    __color(color)
{
    this->__innerRadius = innerRadius;
    this->__outerRadius = outerRadius;
    this->__endAngle = endAngle;
    this->__segments = segments;
    this->__startAngle = startAngle;
}

RayLib::Shapes::Ring::Ring(const Ring &cpy) :
    __center(cpy.__center),
    __color(cpy.__color)
{
    this->__innerRadius = cpy.__innerRadius;
    this->__outerRadius = cpy.__outerRadius;
    this->__endAngle = cpy.__endAngle;
    this->__segments = cpy.__segments;
    this->__startAngle = cpy.__startAngle;
}

RayLib::Shapes::Ring &RayLib::Shapes::Ring::operator = (const Ring &cpy)
{
    this->__center = cpy.__center;
    this->__innerRadius = cpy.__innerRadius;
    this->__outerRadius = cpy.__outerRadius;
    this->__endAngle = cpy.__endAngle;
    this->__segments = cpy.__segments;
    this->__startAngle = cpy.__startAngle;
    this->__color = cpy.__color;
    return (*this);
}

void RayLib::Shapes::Ring::DrawRing() const
{
    ::DrawRing(
        ::Vector2 {this->__center.getX(), this->__center.getY()},
        this->__innerRadius,
        this->__outerRadius,
        this->__startAngle,
        this->__endAngle,
        this->__segments,
        ::Color {this->__color.getR(), this->__color.getG(), this->__color.getB(), this->__color.getA()}
    );
}

void RayLib::Shapes::Ring::DrawRingLines() const
{
    ::DrawRingLines(
        ::Vector2 {this->__center.getX(), this->__center.getY()},
        this->__innerRadius,
        this->__outerRadius,
        this->__startAngle,
        this->__endAngle,
        this->__segments,
        ::Color {this->__color.getR(), this->__color.getG(), this->__color.getB(), this->__color.getA()}
    );
}

void RayLib::Shapes::Ring::DrawRing(const Type::Vector<2> &center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, const Type::Color &color)
{
    ::DrawRing(
        ::Vector2 {center.getX(), center.getY()},
        innerRadius,
        outerRadius,
        startAngle,
        endAngle,
        segments,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Ring::DrawRingLines(const Type::Vector<2> &center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, const Type::Color &color)
{
    ::DrawRingLines(
        ::Vector2 {center.getX(), center.getY()},
        innerRadius,
        outerRadius,
        startAngle,
        endAngle,
        segments,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}
