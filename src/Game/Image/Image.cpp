/**
 * @file Image.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Image.hpp"

Bomberman::Image::Image(const std::string &path, const std::string &name, ObjectType type, const Type::Vector<3> &position, bool display) :
GameObject(name, type, position, display),
__texture(path),
__color(255, 255, 255, 255)
{
    this->__path = path;
}

void Bomberman::Image::update(const double &elapsed)
{
    (void)elapsed;
}

void Bomberman::Image::render() const
{
    this->__texture.drawTexture(this->getPosition().getX(), this->getPosition().getY(), this->__color);
}
