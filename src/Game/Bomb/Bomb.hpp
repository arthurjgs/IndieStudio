/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

#include <RayLib/Model/Animate/Animate.hpp>
#include "Game/GameObject.hpp"
#include <vector>
#include <filesystem>
#include "Game/GameException.hpp"
#include <cmath>
#include <Game/Flame/Flame.hpp>

namespace Bomberman {
    class Bomb : public GameObject {
    public:
        enum Side {
            UP = 1,
            RIGHT = 2,
            DOWN = 3,
            LEFT = 4
        };
        Bomb(const Type::Vector<3> &position, int range = 1);
        ~Bomb();
        std::vector<std::shared_ptr<Flame>> explode();
        void update(const double &elapsed);
        void render() const;
    protected:
    private:
        double _lifespan;
        int _range;
        bool _exploded;
    };
}

#endif //BOMBERMAN_BOMB_HPP
