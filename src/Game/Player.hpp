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
#include "GameException.hpp"
#include <RayLib/InputKeyboard.hpp>
#include <Game/Bomb/Bomb.hpp>
#include <memory>
#include <RayLib/Manager3D.hpp>

namespace Bomberman {
    class Player : public GameObject {
    public:
        enum PlayerState {
            IDLE,
            WALKING,
            ACTION,
            DEAD
        };

        Player(const std::string &name, const Type::Vector<3> &position, float speed = 3.0f, int bombs = 1, int range = 2);
        ~Player() override;

        void setRange(int range);
        int getRange();
        void setSpeed(float range);
        double getSpeed();
        void setScale(const Type::Vector<3> &scale);
        PlayerState getState();
        void setState(const PlayerState &state);
        void setRotationAngle(const double &rotationAngle);


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
        std::vector<double> _bombTimers;
        Type::Vector<3> _scale;
        PlayerState _state;
        double _startActionTime;
        bool _alreadyCreatedBomb;
        double _rotationAngle;
    };
}

#endif //BOMBERMAN_PLAYER_HPP
