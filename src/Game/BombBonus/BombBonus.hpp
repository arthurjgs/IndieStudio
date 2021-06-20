/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_BOMBBONUS_HPP
#define BOMBERMAN_BOMBBONUS_HPP

#include <Types/Vector/Vector.hpp>
#include <Game/GameObject.hpp>

namespace Bomberman {
    class BombBonus : public GameObject {
    public:
        BombBonus(const Type::Vector<3> &position);
        ~BombBonus();
        void update(const double &elapsed);
        void render() const;
    protected:
    private:
        double _lifespan;
    };
}

#endif //BOMBERMAN_BOMBBONUS_HPP
