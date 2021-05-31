/**
 * @file Texture.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include "../../Types/Color/Color.hpp"
#include "../../Types/Rectangle/Rectangle.hpp"
#include "../../Types/Vector/Vector.hpp"
#include "../../Types/RenderTexture/Texture.hpp"
#include <iostream>
#include <raylib.h>

namespace RayLib
{
    class Texture {
        public:
            Texture() = delete;
            ~Texture();
            Texture(const std::string &filename);
            void drawTexture(int posX, int posY, Type::Color tint) const;
            void drawTextureV(Type::Vector<2> position, Type::Color tint) const;
            void drawTextureEx(Type::Vector<2> position, float rotation, float scale, Type::Color tint) const;
            void drawTextureRec(Type::Rectangle source, Type::Vector<2> position, Type::Color tint) const;

            inline int getWidth() const { return (this->_texture.width); }
            inline int getHeight() const { return (this->_texture.height); }
        protected:
        private:
            ::Texture2D _texture;
            std::string _filename;
    };
}

#endif /* !TEXTURE_HPP_ */
