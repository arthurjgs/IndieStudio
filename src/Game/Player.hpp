/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

#include "GameObject.hpp"
#include "RayLib/Model/Animate/Animate.hpp"
#include "PlayerAnimation.hpp"

namespace Bomberman {
    class Player : public GameObject {
    public:
        Player(const std::string &name, const Type::Vector<3> &position, const std::string &assetPath, float speed = 0.1f, int bombs = 1, int range = 3);
        ~Player() override;

        void setRange(int range);
        int getRange();
        void setBombs(int range);
        int getBombs();
        void setSpeed(int range);
        double getSpeed();
        void setScale(const Type::Vector<3> &scale);

        void Move(const Type::Vector<3> &vector);

        void render() override;
        void update(const double &elapsed) override;
        void doAction();
    private:
        int _range;
        int _bombs;
        float _speed;
        double _startAnimTime;
        PlayerAnimation::PlayerState _state;
        std::unique_ptr<PlayerAnimation> _animation;
    };
}

#endif //BOMBERMAN_PLAYER_HPP
