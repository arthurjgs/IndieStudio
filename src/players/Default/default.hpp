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
    class Default : public AbstractPlayer {
    public:
        Default();
        ~Default() = default;
    protected:
    private:
    };
}

extern "C" Bomberman::AbstractPlayer *entryPoint()
{
    static Bomberman::Default player;
    return &player;
}

#endif //BOMBERMAN_DEFAULT_HPP
