/**
 * @file Ellipse.cpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Ellipse.hpp"

RayLib::Shapes::Ellipse::Ellipse(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Type::Color &color) :
    __color(color)
{
    this->__centerX = centerX;
    this->__centerY = centerY;
    this->__radiusH = radiusH;
    this->__radiusV = radiusV;
}

RayLib::Shapes::Ellipse::Ellipse(const Ellipse &cpy) :
    __color(cpy.__color)
{
    this->__centerX = cpy.__centerX;
    this->__centerY = cpy.__centerY;
    this->__radiusH = cpy.__radiusH;
    this->__radiusV = cpy.__radiusV;
}

RayLib::Shapes::Ellipse &RayLib::Shapes::Ellipse::operator = (const Ellipse &cpy)
{
    this->__centerX = cpy.__centerX;
    this->__centerY = cpy.__centerY;
    this->__radiusH = cpy.__radiusH;
    this->__radiusV = cpy.__radiusV;
    this->__color = cpy.__color;
    return (*this);
}

void RayLib::Shapes::Ellipse::DrawEllipse() const
{
    ::Color dummyCol = {
        .r = this->__color.getR(),
        .g = this->__color.getG(),
        .b = this->__color.getB(),
        .a = this->__color.getA()
    };
    ::DrawEllipse(this->__centerX, this->__centerY, this->__radiusH, this->__radiusV, dummyCol);
}

void RayLib::Shapes::Ellipse::DrawEllipseLines() const
{
    ::Color dummyCol = {
        .r = this->__color.getR(),
        .g = this->__color.getG(),
        .b = this->__color.getB(),
        .a = this->__color.getA()
    };
    ::DrawEllipse(this->__centerX, this->__centerY, this->__radiusH, this->__radiusV, dummyCol);
}

void RayLib::Shapes::Ellipse::DrawEllipse(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Type::Color &color)
{
    ::Color dummyCol = {
        .r = color.getR(),
        .g = color.getG(),
        .b = color.getB(),
        .a = color.getA()
    };
    ::DrawEllipse(centerX, centerY, radiusH, radiusV, dummyCol);
}

void RayLib::Shapes::Ellipse::DrawEllipseLines(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Type::Color &color)
{
    ::Color dummyCol = {
        .r = color.getR(),
        .g = color.getG(),
        .b = color.getB(),
        .a = color.getA()
    };
    ::DrawEllipseLines(centerX, centerY, radiusH, radiusV, dummyCol);
}   
