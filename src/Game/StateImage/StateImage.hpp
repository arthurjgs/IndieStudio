/**
 * @file StateImage.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#pragma once

#include "../../RayLib/Texture/Texture.hpp"
#include <iostream>
#include "../GameObject.hpp"
#include <array>

namespace Bomberman
{
    class StateImage : public GameObject {
        public:
            StateImage() = delete;
            StateImage(const StateImage &) = delete;
            StateImage &operator = (const StateImage &) = delete;
            ~StateImage() = default;
            StateImage(const std::string &path, const std::string &name, ObjectType type, const Type::Vector<3> &position, size_t states, bool display = true, bool animation = false);

            inline std::string getPath() const { return (this->__path); }

            inline void setActualState(int actualState) { _actualState = actualState;}

            inline int getActualState() const { return this->_actualState;}

            void update(const double &elapsed);
            void render() const;

        protected:
        private:
            size_t _states;
            float _frameWidth;
            std::string __path;
            RayLib::Texture __texture;
            size_t _actualState;
            Type::Rectangle _sourceRec;
            bool _isAnimation;
    };
}
