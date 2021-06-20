/**
 * @file Texture.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <raylib.h>
#include <iostream>

namespace Type
{
    class Texture {
        public:
            Texture() = delete;
            ~Texture() = default;
            Texture(uint id, int width, int height, int mipmaps, int format);
            Texture(const Texture &cpy);
            Texture operator =(const Texture &cpy);
            inline uint &getId()
            {
                return _id;
            }
            inline uint getId() const
            {
                return _id;
            }
            inline int &getWidth()
            {
                return _width;
            }
            inline int getWidth() const
            {
                return _width;
            }
            inline int &getHeight()
            {
                return _height;
            }
            inline int getHeight() const
            {
                return _height;
            }
            inline int &getMipmaps()
            {
                return _mipmaps;
            }
            inline int getMipmaps() const
            {
                return _mipmaps;
            }
            inline int &getFormat()
            {
                return _format;
            }
            inline int getFormat() const
            {
                return _format;
            }


        protected:
        private:
            uint _id;
            int _width;
            int _height;
            int _mipmaps;
            int _format;
    };
}
