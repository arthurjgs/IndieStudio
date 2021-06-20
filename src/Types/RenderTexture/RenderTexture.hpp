/**
 * @file RenderTexture.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "Texture.hpp"

namespace Type
{
    class RenderTexture {
        public:
            RenderTexture() = delete;
            ~RenderTexture() = default;
            RenderTexture(uint id, Type::Texture texture, Type::Texture depth);
            RenderTexture(const RenderTexture &cpy);
            RenderTexture operator =(const RenderTexture &cpy);
            inline uint &getId()
            {
                return _id;
            }
            inline uint getId() const
            {
                return _id;
            }
            inline Type::Texture &getTexture()
            {
                return _texture;
            }
            inline Type::Texture getTexture() const
            {
                return _texture;
            }
            inline Type::Texture &getDepth()
            {
                return _depth;
            }
            inline Type::Texture getDepth() const
            {
                return _depth;
            }

        protected:
        private:
            uint _id;
            Type::Texture _texture;
            Type::Texture _depth;
    };
}
