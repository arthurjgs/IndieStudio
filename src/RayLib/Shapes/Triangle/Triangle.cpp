/**
 * @file Triangle.cpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "Triangle.hpp"

RayLib::Shapes::Triangle::Triangle(const Type::Vector<2> &v1, const Type::Vector<2> &v2, const Type::Vector<2> &v3, const Type::Color &color) :
    __v1(v1),
    __v2(v2),
    __v3(v3),
    __color(color)
{
}

RayLib::Shapes::Triangle::Triangle(const Triangle &cpy) :
    __v1(cpy.__v1),
    __v2(cpy.__v2),
    __v3(cpy.__v3),
    __color(cpy.__color)
{

}

RayLib::Shapes::Triangle &RayLib::Shapes::Triangle::operator = (const Triangle &cpy)
{
    this->__v1 = cpy.__v1;
    this->__v2 = cpy.__v2;
    this->__v3 = cpy.__v3;
    this->__color = cpy.__color;
    return (*this);
}

void RayLib::Shapes::Triangle::DrawTriangle() const
{
    ::Vector2 dummyOne = {
        .x = this->__v1.getX(),
        .y = this->__v1.getY()
    };
    ::Vector2 dummyTwo = {
        .x = this->__v2.getX(),
        .y = this->__v2.getY()
    };
    ::Vector2 dummyThree = {
        .x = this->__v3.getX(),
        .y = this->__v3.getY()
    };
    ::Color dummyCol = {
        .r = this->__color.getR(),
        .g = this->__color.getG(),
        .b = this->__color.getB(),
        .a = this->__color.getA()
    };
    ::DrawTriangle(dummyOne, dummyThree, dummyThree, dummyCol);
}

void RayLib::Shapes::Triangle::DrawTriangle(const Type::Vector<2> &v1, const Type::Vector<2> &v2, const Type::Vector<2> &v3, const Type::Color &color)
{
    ::Vector2 dummyOne = {
        .x = v1.getX(),
        .y = v1.getY()
    };
    ::Vector2 dummyTwo = {
        .x = v2.getX(),
        .y = v2.getY()
    };
    ::Vector2 dummyThree = {
        .x = v3.getX(),
        .y = v3.getY()
    };
    ::Color dummyCol = {
        .r = color.getR(),
        .g = color.getG(),
        .b = color.getB(),
        .a = color.getA()
    };
    ::DrawTriangle(dummyOne, dummyThree, dummyThree, dummyCol);
}

void RayLib::Shapes::Triangle::DrawTriangleLines(const Type::Vector<2> &v1, const Type::Vector<2> &v2, const Type::Vector<2> &v3, const Type::Color &color)
{
    ::Vector2 dummyOne = {
        .x = v1.getX(),
        .y = v1.getY()
    };
    ::Vector2 dummyTwo = {
        .x = v2.getX(),
        .y = v2.getY()
    };
    ::Vector2 dummyThree = {
        .x = v3.getX(),
        .y = v3.getY()
    };
    ::Color dummyCol = {
        .r = color.getR(),
        .g = color.getG(),
        .b = color.getB(),
        .a = color.getA()
    };
    ::DrawTriangleLines(dummyOne, dummyTwo, dummyThree, dummyCol);
}

void RayLib::Shapes::Triangle::DrawTriangleFan(Type::Vector<2> &points, const int &pointsCount, const Type::Color &color)
{
    ::Vector2 dummyPoints = {
        .x = points.getX(),
        .y = points.getY()
    };
    ::Color dummyCol = {
        .r = color.getR(),
        .g = color.getG(),
        .b = color.getB(),
        .a = color.getA()
    };
    ::DrawTriangleFan(&dummyPoints, pointsCount, dummyCol);
    float &x = points.getX();
    float &y = points.getY();
    x = dummyPoints.x;
    y = dummyPoints.y;
}

void RayLib::Shapes::Triangle::DrawTriangleStrip(Type::Vector<2> &points, const int &pointsCount, const Type::Color &color)
{
    ::Vector2 dummyPoints = {
        .x = points.getX(),
        .y = points.getY()
    };
    ::Color dummyCol = {
        .r = color.getR(),
        .g = color.getG(),
        .b = color.getB(),
        .a = color.getA()
    };
    ::DrawTriangleStrip(&dummyPoints, pointsCount, dummyCol);
    float &x = points.getX();
    float &y = points.getY();
    x = dummyPoints.x;
    y = dummyPoints.y;
}  
