/**
 * @file Line.cpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Line.hpp"

RayLib::Shapes::Line::Line(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, const Type::Color &color) :
    __startPos(startPos),
    __endPos(endPos),
    __color(color)
{
}

RayLib::Shapes::Line::Line(const Line &cpy) :
    __startPos(cpy.__startPos),
    __endPos(cpy.__endPos),
    __color(cpy.__color)
{
}

RayLib::Shapes::Line &RayLib::Shapes::Line::operator = (const Line &cpy)
{
    this->__startPos = cpy.__startPos;
    this->__endPos = cpy.__endPos;
    this->__color = cpy.__color;
    return (*this);
}

void RayLib::Shapes::Line::DrawLineV() const
{
    ::DrawLineV(
        ::Vector2 {this->__startPos.getX(), this->__startPos.getY()},
        ::Vector2 {this->__endPos.getX(), this->__endPos.getY()},
        ::Color {this->__color.getR(), this->__color.getG(), this->__color.getB(), this->__color.getA()}
    );
}

void RayLib::Shapes::Line::DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, const Type::Color &color)
{
    ::DrawLine(
        startPosX,
        startPosY,
        endPosX,
        endPosY,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Line::DrawLineV(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, const Type::Color &color)
{
    ::DrawLineV(
        ::Vector2 {startPos.getX(), startPos.getY()},
        ::Vector2 {endPos.getX(), endPos.getY()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Line::DrawLineEx(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, float thick, const Type::Color &color)
{
    ::DrawLineEx(
        ::Vector2 {startPos.getX(), startPos.getY()},
        ::Vector2 {endPos.getX(), endPos.getY()},
        thick,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Line::DrawLineBezier(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, float thick, const Type::Color &color)
{
    ::DrawLineBezier(
        ::Vector2 {startPos.getX(), startPos.getY()},
        ::Vector2 {endPos.getX(), endPos.getY()},
        thick,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Line::DrawLineBezierQuad(const Type::Vector<2> &startPos, const Type::Vector<2> &endPos, const Type::Vector<2> &controlPos, float thick, const Type::Color &color)
{
    ::DrawLineBezierQuad(
        ::Vector2 {startPos.getX(), startPos.getY()},
        ::Vector2 {endPos.getX(), endPos.getY()},
        ::Vector2 {controlPos.getX(), controlPos.getY()},
        thick,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Shapes::Line::DrawLineStrip(Type::Vector<2> &points, int pointsCount, const Type::Color &color)
{
    ::Vector2 dummyPoint;

    dummyPoint.x = points.getX();
    dummyPoint.y = points.getY();
    ::DrawLineStrip(
        &dummyPoint,
        pointsCount,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
    float &x = points.getX();
    float &y = points.getY();
    x = dummyPoint.x;
    y = dummyPoint.y;
}
