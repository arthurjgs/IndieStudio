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
    ::DrawTriangle(
        Vector2{ this->__v1.getX(), this->__v1.getY() },
        Vector2{ this->__v2.getX(), this->__v2.getY() },
        Vector2{ this->__v3.getX(), this->__v3.getY() },
        ::Color{ this->__color.getR(), this->__color.getG(), this->__color.getB(),this->__color.getA() });
}

void RayLib::Shapes::Triangle::DrawTriangle(const Type::Vector<2> &v1, const Type::Vector<2> &v2, const Type::Vector<2> &v3, const Type::Color &color)
{
    ::DrawTriangle(
        Vector2{ v1.getX(), v1.getY() },
        Vector2{v2.getX(), v2.getY()},
        Vector2{ v3.getX(), v3.getY() },
        ::Color{ color.getR(), color.getG(), color.getB(), color.getA() });
}

void RayLib::Shapes::Triangle::DrawTriangleLines(const Type::Vector<2> &v1, const Type::Vector<2> &v2, const Type::Vector<2> &v3, const Type::Color &color)
{
    ::DrawTriangle(
        Vector2{ v1.getX(), v1.getY() },
        Vector2{ v2.getX(), v2.getY() },
        Vector2{ v3.getX(), v3.getY() },
        ::Color{ color.getR(), color.getG(), color.getB(), color.getA() });
}

void RayLib::Shapes::Triangle::DrawTriangleFan(Type::Vector<2> &points, const int &pointsCount, const Type::Color &color)
{
    ::Vector2 dummyPoints;

    dummyPoints.x = points.getX();
    dummyPoints.y = points.getY();
    ::DrawTriangleFan(&dummyPoints, pointsCount, ::Color{ color.getR(), color.getG(), color.getB(), color.getA() });
    float &x = points.getX();
    float &y = points.getY();
    x = dummyPoints.x;
    y = dummyPoints.y;
}

void RayLib::Shapes::Triangle::DrawTriangleStrip(Type::Vector<2> &points, const int &pointsCount, const Type::Color &color)
{
    ::Vector2 dummyPoints;

    dummyPoints.x = points.getX();
    dummyPoints.y = points.getY();
    ::DrawTriangleStrip(&dummyPoints, pointsCount, ::Color{ color.getR(), color.getG(), color.getB(), color.getA() });
    float &x = points.getX();
    float &y = points.getY();
    x = dummyPoints.x;
    y = dummyPoints.y;
}  
