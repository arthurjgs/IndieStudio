/**
 * @file Image.cpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Image.hpp"

Types::Image::Image(const std::string &data, const int &width, const int &height)
{
    this->__data = data;
    this->__width = width;
    this->__height = height;
}

Types::Image::Image(const Image &cpy)
{
    this->__data = cpy.__data;
    this->__width = cpy.__width;
    this->__height = cpy.__height;
}

Types::Image::Image(const Image &&cpy)
{
    this->__data = cpy.__data;
    this->__width = cpy.__width;
    this->__height = cpy.__height;
}

Types::Image &Types::Image::operator = (const Image &cpy)
{
    this->__data = cpy.__data;
    this->__width = cpy.__width;
    this->__height = cpy.__height;
    return (*this);
}