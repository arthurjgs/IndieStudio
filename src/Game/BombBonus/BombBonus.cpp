/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <RayLib/Manager3D.hpp>
#include "BombBonus.hpp"

Bomberman::BombBonus::BombBonus(const Type::Vector<3> &position) : GameObject("BombBonus", BONUS, position), _lifespan(0)
{
    this->setPosition(position);
}

Bomberman::BombBonus::~BombBonus() = default;


void Bomberman::BombBonus::update(const double &elapsed)
{
    if (_lifespan > 5) {
        this->_state = DESTROYED;
    }
    _lifespan += elapsed;
    RayLib::Manager3D::getInstance().getModel("atomicbomb")->update(elapsed);
}

void Bomberman::BombBonus::render() const
{
    std::weak_ptr<RayLib::Models::Animate> model;

    model = RayLib::Manager3D::getInstance().getModel("atomicbomb");
    model.lock()->render(this->getPosition(), 0, Type::Vector<3>(0.4f, 0.4f, 0.4f), Type::Vector<3>(0.0f, 0.0f, 0.0f));
}