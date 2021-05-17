/*
** EPITECH PROJECT, 2021
** RayLibCore
** File description:
** RayLibCore
*/

#ifndef RAYLIBCORE_HPP_
#define RAYLIBCORE_HPP_

#include "../../shared/Modules/ICore.hpp"
#include <iostream>

namespace rl
{
    class RayLibCore : public module::ICore {
        public:
            RayLibCore(float width, float height, const std::string &title);
            ~RayLibCore();

        protected:
        private:
        float _width;
        float _height;
        std::string _title;
    };
}

#endif /* !RAYLIBCORE_HPP_ */
