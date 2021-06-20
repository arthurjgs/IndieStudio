/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_STARBONUS_HPP
#define BOMBERMAN_STARBONUS_HPP

#include <Types/Vector/Vector.hpp>
#include <Game/GameObject.hpp>

namespace Bomberman {
    class StarBonus : public GameObject {
    public:
        StarBonus(const Type::Vector<3> &position);
        ~StarBonus();
        void update(const double &elapsed);
        void render() const;
    protected:
    private:
        double _lifespan;
    };
}

#endif //BOMBERMAN_STARBONUS_HPP
