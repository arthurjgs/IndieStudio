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
    class Girl : public AbstractPlayer {
    public:
        Girl();
        ~Girl() = default;
    protected:
    private:
    };
}

extern "C" Bomberman::AbstractPlayer *entryPoint()
{
    static Bomberman::Girl player;
    return &player;
}

#endif //BOMBERMAN_DEFAULT_HPP
