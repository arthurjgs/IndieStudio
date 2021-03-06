/**
 * @file FlashingText.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../GameObject.hpp"
#include "../../RayLib/Text/Text.hpp"

namespace Bomberman {
    class FlashingText : public GameObject {
        public:
            FlashingText() = delete;
            FlashingText(const std::string &text, const Type::Color &col, const size_t &size, const double &speed, const std::string &name, const GameObject::ObjectType &type, const Type::Vector<2> &position, bool display = true);
            FlashingText(const std::string &text, const Type::Color &col, const size_t &size, const double &speed, const std::string &name, const GameObject::ObjectType &type, const Type::Vector<2> &position, const std::string &font, bool display = true);

            ~FlashingText() = default;

            FlashingText(const FlashingText &) = delete;
            FlashingText &operator = (const FlashingText &) = delete;

            void render() const;
            void update(const double &elapsed);

            inline std::string &getText() { return (this->__text); }
            inline std::string getText() const { return (this->__text); }

            inline Type::Color &getColor() { return (this->__color); }
            inline Type::Color getColor() const { return (this->__color); }
                       
        protected:
        private:
            std::string __text;
            std::string __font;
            Type::Color __color;
            RayLib::Text __RayText;
            size_t __size;
            size_t __speed;

            double __dummy;
    };
}