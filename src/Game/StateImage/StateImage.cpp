/**
 * @file StateImage.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "StateImage.hpp"

Bomberman::StateImage::StateImage(const std::string &path, const std::string &name, ObjectType type, const Type::Vector<3> &position, size_t states, bool display, bool animation) :
GameObject(name, type, position, display),
__texture(path),
_sourceRec(0, 0, __texture.getWidth() / states, __texture.getHeight())
{
    _display = display;
    _isAnimation = animation;
    _states = states;
    _isAnimation = animation;
    _actualState = 0;
    _frameWidth = __texture.getWidth() / states;
}

void Bomberman::StateImage::update(const double &elapsed)
{
    (void) elapsed;
    _sourceRec.setX(_actualState * _frameWidth);
    if (_isAnimation)
    {
        _sourceRec.setX(_actualState * _frameWidth);
        _actualState += 1;
        if (_sourceRec.getX() >= __texture.getWidth())
            _actualState = 0;
    }
}

void Bomberman::StateImage::render() const
{
    if (_display)
        __texture.drawTextureRec(_sourceRec, Type::Vector<2>(_position.getX(), _position.getY()), Type::Color(255, 255, 255, 255));
}