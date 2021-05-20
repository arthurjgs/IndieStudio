/**
 * @file Color.cpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Color.hpp"

Type::Color::Color(const uChar &r, const uChar &g, const uChar &b, const uChar &a)
{
    this->__r = r;
    this->__g = g;
    this->__b = b;
    this->__a = a;
}

Type::Color::Color(const Color &cpy)
{
    this->__a = cpy.__a;
    this->__r = cpy.__r;
    this->__g = cpy.__g;
    this->__b = cpy.__b;
}

Type::Color::Color(const Color &&cpy)
{
    this->__a = cpy.__a;
    this->__r = cpy.__r;
    this->__g = cpy.__g;
    this->__b = cpy.__b;
}

Type::Color &Type::Color::operator = (const Color &cpy)
{
    this->__a = cpy.__a;
    this->__r = cpy.__r;
    this->__g = cpy.__g;
    this->__b = cpy.__b;
    return (*this);
}

Type::Color Type::Color::operator + (const Color &add)
{
    Color res(*this);

    res.__a = static_cast<int>(res.__a + add.__a) > 255 ? 255 : res.__a + add.__a;
    res.__a = static_cast<int>(res.__r + add.__r) > 255 ? 255 : res.__r + add.__r;
    res.__a = static_cast<int>(res.__g + add.__g) > 255 ? 255 : res.__g + add.__g;
    res.__a = static_cast<int>(res.__b + add.__b) > 255 ? 255 : res.__b + add.__b;
    return (res);
}