/**
 * @file Texture.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Texture.hpp"

Type::Texture::Texture(uint id, int width, int height, int mipmaps, int format)
{
    _id = id;
    _width = width;
    _height = height;
    _mipmaps = mipmaps;
    _format = format;
}

Type::Texture::Texture(const Texture &cpy)
{
    _id = cpy._id;
    _width = cpy._width;
    _height = cpy._height;
    _mipmaps = cpy._mipmaps;
    _format = cpy._format;
}

Type::Texture Type::Texture::operator =(const Texture &cpy)
{
    _id = cpy._id;
    _width = cpy._width;
    _height = cpy._height;
    _mipmaps = cpy._mipmaps;
    _format = cpy._format;
    return (*this);
}
