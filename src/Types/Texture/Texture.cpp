/**
 * @file Texture.cpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Texture.hpp"

Types::Texture::Texture(const std::string &texturePath, const int &width, const int &height)
{
    this->__texturePath = texturePath;
    this->__width = width;
    this->__height = height;
}

Types::Texture::Texture(const Texture &cpy)
{
    this->__texturePath = cpy.__texturePath;
    this->__width = cpy.__width;
    this->__height = cpy.__height;
}

Types::Texture::Texture(const Texture &&cpy)
{
    this->__texturePath = cpy.__texturePath;
    this->__width = cpy.__width;
    this->__height = cpy.__height;
}

Types::Texture &Types::Texture::operator = (const Texture &cpy)
{
    this->__texturePath = cpy.__texturePath;
    this->__width = cpy.__width;
    this->__height = cpy.__height;
    return (*this);
}
