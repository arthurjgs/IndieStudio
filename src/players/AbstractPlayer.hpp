/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_ABSTRACTPLAYER_HPP
#define BOMBERMAN_ABSTRACTPLAYER_HPP

#include <string>

namespace Bomberman {
    class AbstractPlayer {
    public:
        AbstractPlayer(const std::string &name, float speed = 3.0f, int bombs = 1, int range = 1, float scale = 1.0f);
        ~AbstractPlayer() = default;
        float getSpeed() const;
        int getBombs() const;
        int getRange() const;
        float getScale() const;
        std::string getName() const;
    private:
        std::string _name;
        float _speed;
        int _bombs;
        int _range;
        float _scale;
    };
}

#endif //BOMBERMAN_ABSTRACTPLAYER_HPP
