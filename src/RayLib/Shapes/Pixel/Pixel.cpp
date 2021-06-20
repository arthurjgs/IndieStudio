/**
 * @file Pixel.cpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Pixel.hpp"

RayLib::Shapes::Pixel::Pixel(const Type::Vector<2> &position, const Type::Color &color) :
    __position(position),
    __color(color)
{
}

RayLib::Shapes::Pixel::Pixel(const Pixel &cpy)  :
    __position(cpy.__position),
    __color(cpy.__color)
{
}

RayLib::Shapes::Pixel &RayLib::Shapes::Pixel::operator = (const Pixel &cpy)
{
    this->__position = cpy.__position;
    this->__color = cpy.__color;
    return (*this);
}

void RayLib::Shapes::Pixel::DrawPixelV() const
{
    ::DrawPixelV(
        ::Vector2 {this->__position.getX(), this->__position.getY()},
        ::Color {this->__color.getR(), this->__color.getG(), this->__color.getB(), this->__color.getA()}
    );
}

void RayLib::Shapes::Pixel::DrawPixel(const int &posX, const int &posY, const Type::Color &color)
{
    ::DrawPixel(
        posX,
        posY,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Pixel::DrawPixelV(const Type::Vector<2> &position, const Type::Color &color)
{
    ::DrawPixelV(
        ::Vector2 {position.getX(), position.getY()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}
