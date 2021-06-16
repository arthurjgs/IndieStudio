/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <RayLib/Manager3D.hpp>
#include "Crates.hpp"

Bomberman::Crate::Crate(const Type::Vector<3> &position) : GameObject("Crate", DESTRUCTIBLE, position)
{
    this->setPosition(position);
}

Bomberman::Crate::~Crate() = default;


void Bomberman::Crate::update(const double &elapsed)
{
    RayLib::Manager3D::getInstance().getModel("crate")->update(elapsed);
}

void Bomberman::Crate::render() const
{
    std::weak_ptr<RayLib::Models::Animate> model;

    model = RayLib::Manager3D::getInstance().getModel("crate");
    Type::Vector<3> crateScale(0.17f, 0.17f, 0.17f);
    model.lock()->render(this->getPosition(), 0, crateScale, Type::Vector<3>(0.0f, 0.0f, 0.0f));
}