/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_DEFAULT_HPP
#define BOMBERMAN_DEFAULT_HPP

#include <players/AbstractPlayer.hpp>

namespace Bomberman {
    class Bomberman : public AbstractPlayer {
    public:
        Bomberman();
        ~Bomberman() = default;
    protected:
    private:
    };
}

extern "C" Bomberman::AbstractPlayer *entryPoint()
{
    static Bomberman::Bomberman player;
    return &player;
}

#endif //BOMBERMAN_DEFAULT_HPP
