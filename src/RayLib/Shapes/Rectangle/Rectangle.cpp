/**
 * @file Rectangle.cpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Rectangle.hpp"

RayLib::Shapes::Rectangle::Rectangle(const Type::Vector<2> &position, const Type::Vector<2> &size, const Type::Color &color) :
    __position(position),
    __size(size),
    __color(color)
{
}

RayLib::Shapes::Rectangle::Rectangle(const Rectangle &cpy) :
    __position(cpy.__position),
    __size(cpy.__size),
    __color(cpy.__color)
{
}

RayLib::Shapes::Rectangle &RayLib::Shapes::Rectangle::operator = (const Rectangle &cpy)
{
    this->__position = cpy.__position;
    this->__size = cpy.__size;
    this->__color = cpy.__color;
    return (*this);
}

void RayLib::Shapes::Rectangle::DrawRectangleV() const
{
    ::DrawRectangleV(
        ::Vector2 {this->__position.getX(), this->__position.getY()},
        ::Vector2 {this->__size.getX(), this->__size.getY()},
        ::Color {this->__color.getR(), this->__color.getG(), this->__color.getB(), this->__color.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangle(int posX, int posY, int width, int height, const Type::Color &color)
{
    ::DrawRectangle(
        posX,
        posY,
        width,
        height,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangleV(const Type::Vector<2> &position, const Type::Vector<2> &size, const Type::Color &color)
{
    ::DrawRectangleV(
        ::Vector2 {position.getX(), position.getY()},
        ::Vector2 {size.getX(), size.getY()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangleRec(const Type::Rectangle &rec, const Type::Color &color)
{
    ::DrawRectangleRec(
        ::Rectangle {rec.getX(), rec.getY(), rec.getWidth(), rec.getHeight()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectanglePro(const Type::Rectangle &rec, const Type::Vector<2> &origin, float rotation, const Type::Color &color)
{
    ::DrawRectanglePro(
        ::Rectangle {rec.getX(), rec.getY(), rec.getWidth(), rec.getHeight()},
        ::Vector2 {origin.getX(), origin.getY()},
        rotation,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangleGradientV(int posX, int posY, int width, int height, const Type::Color &color1, const Type::Color &color2)
{
    ::DrawRectangleGradientV(
        posX,
        posY,
        height,
        width,
        ::Color {color1.getR(), color1.getG(), color1.getB(), color1.getA()},
        ::Color {color2.getR(), color2.getG(), color2.getB(), color2.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangleGradientH(int posX, int posY, int width, int height, const Type::Color &color1, const Type::Color &color2)
{
    ::DrawRectangleGradientH(
        posX,
        posY,
        height,
        width,
        ::Color {color1.getR(), color1.getG(), color1.getB(), color1.getA()},
        ::Color {color2.getR(), color2.getG(), color2.getB(), color2.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangleGradientEx(const Type::Rectangle &rec, const Type::Color &col1, const Type::Color &col2, const Type::Color &col3, const Type::Color &col4)
{
    ::DrawRectangleGradientEx(
        ::Rectangle {rec.getX(), rec.getY(), rec.getWidth(), rec.getHeight()},
        ::Color {col1.getR(), col1.getG(), col1.getB(), col1.getA()},
        ::Color {col2.getR(), col2.getG(), col2.getB(), col2.getA()},
        ::Color {col3.getR(), col3.getG(), col3.getB(), col3.getA()},
        ::Color {col4.getR(), col4.getG(), col4.getB(), col4.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangleLines(int posX, int posY, int width, int height, const Type::Color &color)
{
    ::DrawRectangleLines(
        posX,
        posY,
        height,
        width,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangleLinesEx(const Type::Rectangle &rec, int lineThick, const Type::Color &color)
{
    ::DrawRectangleLinesEx(
        ::Rectangle {rec.getX(), rec.getY(), rec.getWidth(), rec.getHeight()},
        lineThick,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangleRounded(const Type::Rectangle &rec, float roundness, int segments, const Type::Color &color)
{
    ::DrawRectangleRounded(
        ::Rectangle {rec.getX(), rec.getY(), rec.getWidth(), rec.getHeight()},
        roundness,
        segments,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Rectangle::DrawRectangleRoundedLines(const Type::Rectangle &rec, float roundness, int segments, int lineThick, const Type::Color &color)
{
    ::DrawRectangleRoundedLines(
        ::Rectangle {rec.getX(), rec.getY(), rec.getWidth(), rec.getHeight()},
        roundness,
        segments,
        lineThick,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}