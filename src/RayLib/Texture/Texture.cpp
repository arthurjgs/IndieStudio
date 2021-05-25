/**
 * @file Texture.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Texture.hpp"

RayLib::Texture::~Texture()
{
    ::UnloadTexture(_texture);
}

RayLib::Texture::Texture(const std::string &filename)
{
    _filename = filename;
    _texture = ::LoadTexture(_filename.c_str());
}

void RayLib::Texture::drawTexture(int posX, int posY, Type::Color tint) const
{
    ::DrawTexture(_texture, posX, posY, ::Color {tint.getR(), tint.getG(), tint.getB(), tint.getA()});
}

void RayLib::Texture::drawTextureV(Type::Vector<2> position, Type::Color tint) const
{
    ::DrawTextureV(
        _texture,
        ::Vector2 {position.getX(), position.getY()},
        ::Color {tint.getR(), tint.getG(), tint.getB(), tint.getA()}
    );
}

void RayLib::Texture::drawTextureEx(Type::Vector<2> position, float rotation, float scale, Type::Color tint) const
{
    ::DrawTextureEx(
        _texture,
        ::Vector2 {position.getX(), position.getY()},
        rotation,
        scale,
        ::Color {tint.getR(), tint.getG(), tint.getB(), tint.getA()}
    );
}

void RayLib::Texture::drawTextureRec(Type::Rectangle source, Type::Vector<2> position, Type::Color tint) const
{
    ::DrawTextureRec(
        _texture,
        ::Rectangle {source.getX(), source.getY(), source.getWidth(), source.getHeight()},
        ::Vector2 {position.getX(), position.getY()},
        ::Color {tint.getR(), tint.getG(), tint.getB(), tint.getA()}
    );
}
