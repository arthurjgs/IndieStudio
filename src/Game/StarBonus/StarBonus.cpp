/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/


#include <RayLib/Manager3D.hpp>
#include "StarBonus.hpp"


Bomberman::StarBonus::StarBonus(const Type::Vector<3> &position, int side) : GameObject("SpeedBonus", BONUS, position), _lifespan(0)
{
    this->setPosition(position);
}

Bomberman::StarBonus::~StarBonus() = default;


void Bomberman::StarBonus::update(const double &elapsed)
{
    if (_lifespan > 1.5) {
        this->_state = DESTROYED;
    }
    _lifespan += elapsed;
    RayLib::Manager3D::getInstance().getModel("star")->update(elapsed);
}

void Bomberman::StarBonus::render() const
{
    std::weak_ptr<RayLib::Models::Animate> model;

    model = RayLib::Manager3D::getInstance().getModel("star");
    model.lock()->render(this->getPosition(), 0, Type::Vector<3>(1.0f, 1.0f, 1.0f), Type::Vector<3>(0.0f, 0.0f, 0.0f));
}