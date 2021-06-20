/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <RayLib/Manager3D.hpp>
#include "RangeBonus.hpp"

Bomberman::RangeBonus::RangeBonus(const Type::Vector<3> &position) : GameObject("RangeBonus", BONUS, position), _lifespan(0)
{
    this->setPosition(position);
}

Bomberman::RangeBonus::~RangeBonus() = default;


void Bomberman::RangeBonus::update(const double &elapsed)
{
    if (_lifespan > 3) {
        this->_state = DESTROYED;
    }
    _lifespan += elapsed;
    RayLib::Manager3D::getInstance().getModel("range")->update(elapsed);
}

void Bomberman::RangeBonus::render() const
{
    std::weak_ptr<RayLib::Models::Animate> model;

    model = RayLib::Manager3D::getInstance().getModel("range");
    model.lock()->render(this->getPosition(), 0, Type::Vector<3>(10.0f, 10.0f, 10.0f), Type::Vector<3>(0.0f, 0.0f, 0.0f));
}