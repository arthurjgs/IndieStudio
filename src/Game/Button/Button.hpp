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
#include "../../RayLib/Text/Text.hpp"

namespace Bomberman
{
    class Button : public Bomberman::GameObject {
        public:
            Button() = delete;
            Button(const Bomberman::Button &) = delete;
            Button &operator=(const Bomberman::Button &) = delete;
            Button(const std::string &name, const Type::Vector<3> &position,
            const std::string &texturePath, const std::string &text = "", size_t fontSize = 12, const Type::Color &textColor = Type::Color(255, 255, 255, 255),
            const std::string &soundPath = "./assets/sounds/mute.wav", bool display = true);
            ~Button();
            bool isClick() const;
            bool isValidate() const;
            void render() const;
            void update(const double &elapsed);

            inline std::string &getText() { return (this->_text); }
            inline std::string getText() const { return (this->_text); }

            inline size_t &getFontSize() { return (this->_fontSize); }
            inline size_t getFontSize() const { return (this->_fontSize); }

            inline Type::Color &getTextColor() { return (this->_textColor); }
            inline Type::Color getTextColor() const { return (this->_textColor); }

            inline bool &getManual() { return (this->_manual); }
            inline bool getManual() const { return (this->_manual); }

            inline int &getState() { this->_manual = true; return (this->_state); }
            inline int getState() const { return (this->_state); }

        protected:
        private:
            RayLib::Texture _texture;
            RayLib::Audio::Sound _sound;
            float _frameWidth;
            RayLib::Shapes::Collision _collision;
            RayLib::InputMouse _mouse;
            Type::Rectangle _sourceRec;
            Type::Rectangle _btnBounds;
            int _state;
            bool _manual;

            std::string _text;
            size_t _fontSize;
            RayLib::Text _textDisplayer;
            Type::Color _textColor;
    };
}

#endif /* !BUTTON_HPP_ */
