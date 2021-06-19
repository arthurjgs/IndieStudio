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
    class Steve : public AbstractPlayer {
    public:
        Steve();
        ~Steve() = default;
    protected:
    private:
    };
}

extern "C" Bomberman::AbstractPlayer *entryPoint()
{
    static Bomberman::Steve player;
    return &player;
}

#endif //BOMBERMAN_DEFAULT_HPP
