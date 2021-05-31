/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include "GameObject.hpp"

void Bomberman::GameObject::setDisplay(bool display)
{
    this->_display = display;
}

bool Bomberman::GameObject::getDisplay() const
{
    return this->_display;
}

Bomberman::GameObject::ObjectType Bomberman::GameObject::getType() const
{
    return this->_type;
}

Type::Vector<3> Bomberman::GameObject::getPosition() const
{
    return this->_position;
}

void Bomberman::GameObject::setPosition(Type::Vector<3> position)
{
    this->_position = position;
}

Bomberman::GameObject::GameObject(const std::string &name, Bomberman::GameObject::ObjectType type, const Type::Vector<3> &position, bool display)
{
    this->_type = type;
    this->_position = position;
    this->_display = display;
    this->_name = name;
}

std::string Bomberman::GameObject::getName() const
{
    return this->_name;
}

Bomberman::GameObject::~GameObject() = default;
