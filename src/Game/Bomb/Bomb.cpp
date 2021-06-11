/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <RayLib/Manager3D.hpp>
#include "Bomb.hpp"

Bomberman::Bomb::Bomb(Type::Vector<3> position, int range) : GameObject("Bomb", BOMB, position), _lifespan(0), _exploded(false), _range(range)
{
    this->setPosition(position);
}

Bomberman::Bomb::~Bomb() = default;


void Bomberman::Bomb::update(const double &elapsed)
{
    if (_lifespan > 3) {
        _exploded = true;
    } if (_lifespan > 4.5) {
        this->_state = DESTROYED;
        return;
    }
    _lifespan += elapsed;
    if (_exploded) {
        RayLib::Manager3D::getInstance().getModel("fire")->update(elapsed);
    }
}

void Bomberman::Bomb::render() const
{
    std::weak_ptr<RayLib::Models::Animate> model;
    int side = 0;
    float coef = 1;

    if (_exploded) {
        model = RayLib::Manager3D::getInstance().getModel("fire");
        Type::Vector<3> flameScale(0.8f, 0.8f, 0.8f);
        for (int i = 0; i < (_range * 4) + 1; i++, side++) {
            if (i == 0) {
                model.lock()->render(this->getPosition(), 0, flameScale, Type::Vector<3>(0.0f, 0.0f, 0.0f));
                continue;
            }
            switch (side) {
                case UP:
                    model.lock()->render(this->getPosition() + Type::Vector<3>(0.0f, 0.0f, -coef), 0, flameScale, Type::Vector<3>(0.0f, 0.0f, 0.0f));
                    break;
                case DOWN:
                    model.lock()->render(this->getPosition() + Type::Vector<3>(0.0f, 0.0f, coef), 0, flameScale, Type::Vector<3>(0.0f, 0.0f, 0.0f));
                    break;
                case LEFT:
                    model.lock()->render(this->getPosition() + Type::Vector<3>(-coef, 0.0f, 0.0f), 0, flameScale, Type::Vector<3>(0.0f, 0.0f, 0.0f));
                    break;
                case RIGHT:
                    model.lock()->render(this->getPosition() + Type::Vector<3>(coef, 0.0f, 0.0f), 0, flameScale, Type::Vector<3>(0.0f, 0.0f, 0.0f));
                    break;
                default:
                    side = 0;
                    coef += 1;
                    break;
            }
        }
    } else {
        model = RayLib::Manager3D::getInstance().getModel("bomb");
        model.lock()->render(this->getPosition(), 0, Type::Vector<3>(35.0f, 35.0f, 35.0f), Type::Vector<3>(0.0f, 0.0f, 0.0f));
    }
}