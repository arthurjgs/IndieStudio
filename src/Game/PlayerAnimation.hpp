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

        explicit PlayerAnimation(const std::string &path, const Type::Vector<3> &position);
        void setScale(const Type::Vector<3> &scale);
        void render(Bomberman::PlayerAnimation::PlayerState state, const Type::Vector<3> &position);
        void resetAnimations();
    private:
        std::unique_ptr<RayLib::Models::Animate> _idleAnimation;
        std::unique_ptr<RayLib::Models::Animate> _walkingAnimation;
        std::unique_ptr<RayLib::Models::Animate> _actionAnimation;
        std::unique_ptr<RayLib::Models::Animate> _deathAnimation;
        std::vector<std::filesystem::path> _texturesList;
    };
}

#endif //BOMBERMAN_PLAYERANIMATION_HPP
