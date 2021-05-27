/**
 * @file SpriteSheetPlayer.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include "../GameObject.hpp"
#include "../../Types/Vector/Vector.hpp"
#include "../../Types/Rectangle/Rectangle.hpp"
#include "../../RayLib/Texture/Texture.hpp"
#include "../../Types/Color/Color.hpp"
#include "../../RayLib/Window.hpp"

namespace Bomberman {
    class SpriteSheetPlayer : public GameObject {
        public:
            SpriteSheetPlayer() = delete;
            ~SpriteSheetPlayer() = default;
            SpriteSheetPlayer(const std::string &pathToSheet, size_t spriteIPS, const Type::Rectangle &rect, const Type::Vector<2> &pos, const std::string &name, size_t frameNb, bool display);
        
            SpriteSheetPlayer(const SpriteSheetPlayer &) = delete;
            SpriteSheetPlayer &operator = (const SpriteSheetPlayer &) = delete;
        
            inline std::string getPathToSheet() const { return (this->__pathToSheet); }
            inline size_t getSpriteIPS() const { return (this->__spriteIPS); }
            inline size_t getFrameNb() const { return (this->__frameNumber); }
            inline Type::Rectangle getRect() const { return (this->__rect); }

            inline std::string &getPathToSheet() { return (this->__pathToSheet); }
            inline size_t &getSpriteIPS() { return (this->__spriteIPS); }
            inline Type::Rectangle &getRect() { return (this->__rect); }

            void render() const;
            void update(const double &elapsed);
        protected:
        private:
            std::string __pathToSheet;
            size_t __spriteIPS;
            Type::Rectangle __rect;
            size_t __frameCounter;
            RayLib::Texture __texture;
            size_t __frameNumber;
            size_t __currentFrame;
    };
}