/**
 * @file RenderTexture.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "RenderTexture.hpp"

Type::RenderTexture::RenderTexture(uint id, Type::Texture texture, Type::Texture depth) : _texture(texture), _depth(depth)
{
    _id = id;
}

Type::RenderTexture::RenderTexture(const RenderTexture &cpy) : _texture(cpy._texture), _depth(cpy._depth)
{
    _id = cpy._id;
}

Type::RenderTexture Type::RenderTexture::operator =(const RenderTexture &cpy)
{
    _id = cpy._id;
    _texture = cpy._texture;
    _depth = cpy._depth;
    return (*this);
}


