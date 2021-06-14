/**
 * @file Image.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../RayLib/Texture/Texture.hpp"
#include <iostream>
#include "../GameObject.hpp"

namespace Bomberman {
    class Image : public GameObject {
        public:
            Image() = delete;
            Image(const std::string &path, const std::string &name, ObjectType type, const Type::Vector<3> &position, bool display = true);
            ~Image() = default;

            Image(const Image &) = delete;
            Image &operator = (const Image &) = delete;

            inline std::string getPath() const { return (this->__path); }
        
            void update(const double &elapsed);
            void render() const;

            inline Type::Color &getColor() { return (this->__color); }
            inline Type::Color getColor() const { return (this->__color); }
        protected:
        private:
            std::string __path;
            RayLib::Texture __texture;
            Type::Color __color;
    };
}