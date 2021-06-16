/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <RayLib/Manager3D.hpp>
#include "Flame.hpp"

Bomberman::Flame::Flame(const Type::Vector<3> &position, int side) : GameObject("Flame", FLAME, position), _lifespan(0), _side(side)
{
    this->setPosition(position);
}

Bomberman::Flame::~Flame() = default;


void Bomberman::Flame::update(const double &elapsed)
{
    if (_lifespan > 1.5) {
        this->_state = DESTROYED;
    }
    _lifespan += elapsed;
    RayLib::Manager3D::getInstance().getModel("fire")->update(elapsed);
}

void Bomberman::Flame::render() const
{
    std::weak_ptr<RayLib::Models::Animate> model;

    model = RayLib::Manager3D::getInstance().getModel("fire");
    Type::Vector<3> flameScale(0.8f, 0.8f, 0.8f);
    model.lock()->render(this->getPosition(), 0, flameScale, Type::Vector<3>(0.0f, 0.0f, 0.0f));
}

int Bomberman::Flame::getSide() const
{
    return this->_side;
}
