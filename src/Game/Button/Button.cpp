/**
 * @file Button.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Button.hpp"

Bomberman::Button::Button(const std::string &name, const Type::Vector<3> &position, const std::string &texturePath, const std::string &soundPath, bool display) :
GameObject(name, Bomberman::GameObject::BUTTON, position, display),
_texture(texturePath),
_sound(soundPath),
_btnBounds(position.getX(), position.getY(), _texture.getWidth() / 3, _texture.getHeight()),
_sourceRec(0, 0, _texture.getWidth() / 3, _texture.getHeight())
{
    _frameWidth = _texture.getWidth() / 3;
    _state = 0;    
}

Bomberman::Button::~Button()
{
}

bool Bomberman::Button::isClick() const
{
    if (_collision.CheckCollisionPointRec(_mouse.getMousePosition(), _btnBounds))
        if (_mouse.isMouseButtonReleased(MOUSE_BUTTON_LEFT))
            return true;
    return false;
}

void Bomberman::Button::render() const
{
    if (_display)
    {
        _texture.drawTexture(800, 700, Type::Color(255, 255, 255, 255));
        std::cout << "OUI" << std::endl;
    }
}

void Bomberman::Button::update(const double &elapsed)
{
    if (_collision.CheckCollisionPointRec(_mouse.getMousePosition(), _btnBounds))
    {
        if (_mouse.isMouseButtonDown(MOUSE_BUTTON_LEFT))
            _state = 2;
        else
            _state = 1;
    }
    else
        _state = 0;
}