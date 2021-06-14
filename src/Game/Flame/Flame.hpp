/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_FLAME_HPP
#define BOMBERMAN_FLAME_HPP

#include <Types/Vector/Vector.hpp>
#include <Game/GameObject.hpp>

namespace Bomberman {
    class Flame : public GameObject {
    public:
        Flame(const Type::Vector<3> &position);
        ~Flame();
        void update(const double &elapsed);
        void render() const;
    protected:
    private:
        double _lifespan;
    };
}

#endif //BOMBERMAN_FLAME_HPP
