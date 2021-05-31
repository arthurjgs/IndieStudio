/**
 * @file Button.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "../GameObject.hpp"
#include "../../RayLib/Audio/Sound/Sound.hpp"
#include "../../RayLib/Texture/Texture.hpp"
#include "../../RayLib/Shapes/Collision/Collision.hpp"
#include "../../RayLib/InputMouse.hpp"

namespace Bomberman
{
    class Button : public Bomberman::GameObject {
        public:
            Button() = delete;
            Button(const Bomberman::Button &) = delete;
            Button &operator=(const Bomberman::Button &) = delete;
            Button(const std::string &name, const Type::Vector<3> &position,
            const std::string &texturePath, const std::string &soundPath = "./assets/sounds/mute.wav", bool display = true);
            ~Button();
            bool isClick() const;
            void render() const;
            void update(const double &elapsed);

        protected:
        private:
            RayLib::Texture _texture;
            RayLib::Audio::Sound _sound;
            RayLib::Shapes::Collision _collision;
            RayLib::InputMouse _mouse;
            Type::Rectangle _sourceRec;
            Type::Rectangle _btnBounds;
            float _frameWidth;
            int _state;

    };
}

#endif /* !BUTTON_HPP_ */
