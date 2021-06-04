/**
 * @file FlashingText.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "FlashingText.hpp"
#include <math.h>

Bomberman::FlashingText::FlashingText(const std::string &text, const Type::Color &col, const size_t &size, const double &speed, const std::string &name, const GameObject::ObjectType &type, const Type::Vector<2> &position, bool display) :
GameObject(name, type, Type::Vector<3>(position.getX(), position.getY(), 0.0f), display),
__color(col),
__RayText() // TODO: Load custom font here
{
    this->__text = text;
    this->__size = size;
    this->__speed = speed;
    this->__dummy = 0.0f;
}

Bomberman::FlashingText::FlashingText(const std::string &text, const Type::Color &col, const size_t &size, const double &speed, const std::string &name, const GameObject::ObjectType &type, const Type::Vector<2> &position, const std::string &font, bool display) :
GameObject(name, type, Type::Vector<3>(position.getX(), position.getY(), 0.0f), display),
__color(col),
__RayText(font) // TODO: Load custom font here
{
    this->__text = text;
    this->__size = size;
    this->__speed = speed;
    this->__dummy = 0.0f;
}

void Bomberman::FlashingText::render() const
{
    this->__RayText.DrawText(this->__text, this->getPosition().getX(), this->getPosition().getY(), this->__size, this->__color);
}

void Bomberman::FlashingText::update(const double &elapsed)
{
    const double speed = this->__speed * elapsed;
    uChar &transparency = this->__color.getA();
    static bool sub = true;
    
    this->__dummy += speed;
    if (sub == true) {
        if (this->__dummy >= 1.0f) {
            transparency -= this->__dummy;
            this->__dummy = 0.0f;
        }
        if (transparency == 0) {
            sub = false;
        }
    } else {
        if (this->__dummy >= 1.0f) {
            transparency += this->__dummy;
            this->__dummy = 0.0f;
        }
        if (transparency == 255) {
            sub = true;
        }
    }

}
