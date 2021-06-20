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
#include "../../RayLib/Window.hpp"

Bomberman::Button::Button(const std::string &name, const Type::Vector<3> &position,
    const std::string &texturePath, const std::string &text, size_t fontSize, const Type::Color &textColor,
    const std::string &soundPath, bool display) :
GameObject(name, Bomberman::GameObject::BUTTON, position, display),
_texture(texturePath),
_sound(soundPath),
_frameWidth(_texture.getWidth() / 3),
_sourceRec(0, 0, _texture.getWidth() / 3, _texture.getHeight()),
// TODO: LOAD CUSTOM FONT FOR RAYLIB TEXT
_btnBounds(position.getX(), position.getY(), _texture.getWidth() / 3, _texture.getHeight()),
_textColor(textColor)
{
    _frameWidth = _texture.getWidth() / 3;
    _state = 0;
    this->_text = text;
    this->_fontSize = fontSize;
    this->_manual = false;
}

Bomberman::Button::~Button()
{
}

bool Bomberman::Button::isClick() const
{
    if (this->_manual) {
        return (false);
    }
    if (_collision.CheckCollisionPointRec(_mouse.getMousePosition(), _btnBounds))
        if (_mouse.isMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            this->_sound.PlaySound();
            return true;
        }
    return false;
}

bool Bomberman::Button::isValidate() const
{
    if (!this->_manual) {
        return (false);
    }
    return (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonPressed(0, RayLib::Window::A));
}

void Bomberman::Button::render() const
{
    if (_display)
    {
        _texture.drawTextureRec(_sourceRec, Type::Vector<2>(_btnBounds.getX(), _btnBounds.getY()), Type::Color(255, 255, 255, 255));
        if (this->_text != "") {
            int posX = (this->_btnBounds.getX() + this->_btnBounds.getWidth() / 2) - (this->_text.length() * this->_fontSize) / 3;
            int posY = (this->_btnBounds.getY() + this->_btnBounds.getHeight() / 2) - (this->_fontSize / 2);
            this->_textDisplayer.DrawText(this->_text, posX, posY, this->_fontSize, this->_textColor);
        }
    }
}

void Bomberman::Button::update(const double &elapsed)
{
    (void) elapsed;
    if (this->_manual == true) {
        _sourceRec.setX(_state * _frameWidth);
        if (RayLib::Window::getInstance().getInputKeyboard().getKeyPressed() > 0) {
            this->_manual = false;
            std::cout << "salut" << std::endl;
        }
        return;
    }
    if (_collision.CheckCollisionPointRec(_mouse.getMousePosition(), _btnBounds))
    {
        if (_mouse.isMouseButtonDown(MOUSE_BUTTON_LEFT))
            _state = 2;
        else
            _state = 1;
    }
    else
        _state = 0;
    _sourceRec.setX(_state * _frameWidth);
}
