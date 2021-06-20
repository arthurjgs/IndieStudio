/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <RayLib/Manager3D.hpp>
#include "Bomb.hpp"

Bomberman::Bomb::Bomb(const Type::Vector<3> &position, Player *owner, int range) : GameObject("Bomb", BOMB, position), _lifespan(0), _exploded(false), _range(range)
{
    this->setPosition(position);
    this->_owner = owner;
}

Bomberman::Bomb::~Bomb() = default;


void Bomberman::Bomb::update(const double &elapsed)
{
    if (_lifespan > 3) {
        this->_state = DESTROYED;
        return;
    }
    _lifespan += elapsed;
}

void Bomberman::Bomb::render() const
{
    std::weak_ptr<RayLib::Models::Animate> model;

    if (_exploded) {
        return;
    } else {
        model = RayLib::Manager3D::getInstance().getModel("bomb");
        model.lock()->render(this->getPosition(), 0, Type::Vector<3>(35.0f, 35.0f, 35.0f), Type::Vector<3>(0.0f, 0.0f, 0.0f));
    }
}

std::vector<std::shared_ptr<Bomberman::Flame>> Bomberman::Bomb::explode()
{
    std::vector<std::shared_ptr<Flame>> flames;
    int side = 0;
    float coef = 1;

    for (int i = 0; i <= (_range * 4) + 1; i++, side++) {
        if (i == 0) {
            flames.emplace_back(std::make_shared<Bomberman::Flame>(this->getPosition(), 0));
            continue;
        }
        switch (side) {
            case UP:
                flames.emplace_back(std::make_shared<Bomberman::Flame>(this->getPosition() + Type::Vector<3>(0.0f, 0.0f, -coef), 1));
                break;
            case DOWN:
                flames.emplace_back(std::make_shared<Bomberman::Flame>(this->getPosition() + Type::Vector<3>(0.0f, 0.0f, coef), 3));
                break;
            case LEFT:
                flames.emplace_back(std::make_shared<Bomberman::Flame>(this->getPosition() + Type::Vector<3>(-coef, 0.0f, 0.0f), 4));
                break;
            case RIGHT:
                flames.emplace_back(std::make_shared<Bomberman::Flame>(this->getPosition() + Type::Vector<3>(coef, 0.0f, 0.0f), 2));
                break;
            default:
                side = 0;
                coef += 1;
                break;
        }
    }
    return flames;
}
