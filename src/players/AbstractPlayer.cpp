/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include "AbstractPlayer.hpp"

Bomberman::AbstractPlayer::AbstractPlayer(const std::string &name, float speed, int bombs, int range, float scale) :
                                          _speed(speed),
                                          _bombs(bombs),
                                          _range(range) ,
                                          _scale(scale)
{
    this->_name = name;
}

float Bomberman::AbstractPlayer::getSpeed() const
{
    return this->_speed;
}

int Bomberman::AbstractPlayer::getBombs() const
{
    return this->_bombs;
}

int Bomberman::AbstractPlayer::getRange() const
{
    return this->_range;
}

float Bomberman::AbstractPlayer::getScale() const
{
    return this->_scale;
}

std::string Bomberman::AbstractPlayer::getName() const
{
    return this->_name;
}
