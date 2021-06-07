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
#include "GameException.hpp"
#include <RayLib/InputKeyboard.hpp>
#include <Game/Bomb/Bomb.hpp>
#include <memory>

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

        PlayerAnimation::PlayerState getState();

        void Move(const Type::Vector<3> &vector);

        void render() const override;
        void update(const double &elapsed) override;

        bool checkFreeTimer();
        void launchFreeTimer(const double &elapsed);
        void checkTimer(const double &elapsed);
        std::shared_ptr<Bomb> createBomb();

    private:
        int _range;
        float _speed;
        std::unique_ptr<PlayerAnimation> _animation;
        std::vector<double> _bombTimers;
        double _startActionTime;
        bool _alreadyCreatedBomb;
    };
}

#endif //BOMBERMAN_PLAYER_HPP
