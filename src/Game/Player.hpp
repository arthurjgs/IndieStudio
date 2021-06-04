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
        Player(const std::string &name, const Type::Vector<3> &position, const std::string &assetPath, float speed = 3.0f, int bombs = 1, int range = 3);
        ~Player() override;

        void setRange(int range);
        int getRange();
        void setBombs(int range);
        int getBombs();
        void setSpeed(float range);
        double getSpeed();
        void setScale(const Type::Vector<3> &scale);

        void Move(const Type::Vector<3> &vector);

        void render() const override;
        void update(const double &elapsed) override;

        bool checkFreeTimer();
        void launchFreeTimer(const double &elapsed);
        void checkTimer(const double &elapsed);

    private:
        int _range;
        float _speed;
        PlayerAnimation::PlayerState _state;
        std::unique_ptr<PlayerAnimation> _animation;
        std::vector<double> _bombTimers;
        double _startActionTime;
    };
}

#endif //BOMBERMAN_PLAYER_HPP
