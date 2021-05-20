/**
 *  @file   RayLib.cpp
 *  @brief  RayLib Encapsulation Header
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/


#ifndef BOMBERMAN_RAYLIB_HPP
#define BOMBERMAN_RAYLIB_HPP

#include <raylib.h>
#include <iostream>

namespace RayLib
{
    class Window {
        public:
            static Window &getInstance();
            float getElapsedTime();
            bool isOpen() const;
        private:
            Window() = delete;
            Window(float width, float height, const std::string &title);
            Window(const Window &) = delete;
            Window &operator = (const Window &) = delete;
            ~Window();
            float _clock;
        protected:
    };
}

#endif //BOMBERMAN_RAYLIB_HPP
