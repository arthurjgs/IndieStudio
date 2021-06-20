/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_RANGEBONUS_HPP
#define BOMBERMAN_RANGEBONUS_HPP

#include <Types/Vector/Vector.hpp>
#include <Game/GameObject.hpp>

namespace Bomberman {
    class RangeBonus : public GameObject {
    public:
        RangeBonus(const Type::Vector<3> &position);
        ~RangeBonus();
        void update(const double &elapsed);
        void render() const;
    protected:
    private:
        double _lifespan;
    };
}

#endif //BOMBERMAN_BOMBBONUS_HPP
