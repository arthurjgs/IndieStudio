/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_SPEEDBONUS_HPP
#define BOMBERMAN_SPEEDBONUS_HPP

#include <Types/Vector/Vector.hpp>
#include <Game/GameObject.hpp>

namespace Bomberman {
    class SpeedBonus : public GameObject {
    public:
        SpeedBonus(const Type::Vector<3> &position);
        ~SpeedBonus();
        void update(const double &elapsed);
        void render() const;
    protected:
    private:
        double _lifespan;
    };
}

#endif //BOMBERMAN_SPEEDBONUS_HPP
