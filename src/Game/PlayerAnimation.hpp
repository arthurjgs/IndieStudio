/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_PLAYERANIMATION_HPP
#define BOMBERMAN_PLAYERANIMATION_HPP

#include <string>
#include <filesystem>
#include "RayLib/Model/Animate/Animate.hpp"
#include "GameException.hpp"
#include "GameObject.hpp"

namespace Bomberman
{
    class PlayerAnimation {
    public:
        enum PlayerState {
            IDLE,
            WALKING,
            ACTION,
            DEAD
        };

        explicit PlayerAnimation(const std::string &path, const Type::Vector<3> &position, PlayerAnimation::PlayerState state = IDLE);
        void setScale(const Type::Vector<3> &scale);
        void setState(PlayerAnimation::PlayerState state);
        PlayerAnimation::PlayerState getState();
        void setPosition(const Type::Vector<3> &position);
        void setRotationAngle(const float &angle);
        void update(const double &elapsed);
        void render();
        void resetAnimations();
    private:
        std::unique_ptr<RayLib::Models::Animate> _idleAnimation;
        std::unique_ptr<RayLib::Models::Animate> _walkingAnimation;
        std::unique_ptr<RayLib::Models::Animate> _actionAnimation;
        std::unique_ptr<RayLib::Models::Animate> _deathAnimation;
        std::vector<std::filesystem::path> _texturesList;
        PlayerAnimation::PlayerState _state;
    };
}

#endif //BOMBERMAN_PLAYERANIMATION_HPP
