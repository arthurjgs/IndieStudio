/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_DEFAULT_HPP
#define BOMBERMAN_DEFAULT_HPP

#include <players/Player.hpp>
#include <Types/Vector/Vector.hpp>

namespace Bomberman {
    class Bomberman : public Player {
    public:
        Bomberman();
        ~Bomberman() = default;
    protected:
    private:
    };
}

extern "C" Bomberman::Player *entryPointPlayer()
{
    static Bomberman::Bomberman *player;
    return player;
}

#endif //BOMBERMAN_DEFAULT_HPP
