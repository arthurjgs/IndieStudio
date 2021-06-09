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
#include "InputKeyboard.hpp"
#include "InputMouse.hpp"
#include "InputGamepad.hpp"
#include "Cursor.hpp"
#include "Drawing.hpp"
#include "Camera.hpp"
#include <memory>
#include "../Game/SceneManager/SceneManager.hpp"

namespace RayLib
{
    class Window {
        public:
            enum XBOX {
                    NOTHING,
                    UP,
                    RIGHT,
                    DOWN,
                    LEFT,
                    Y,
                    B,
                    A,
                    X,
                    LB,
                    LT,
                    RB,
                    RT,
                    SELECT,
                    XBOX,
                    START,
                    JOYLEFT,
                    JOYRIGHT
                };
            static Window &getInstance();
            float getElapsedTime();
            bool isOpen() const;
            void draw(Bomberman::SceneManager &manager) const;
            RayLib::InputMouse getInputMouse() const;
            RayLib::InputKeyboard getInputKeyboard() const;
            RayLib::InputGamepad getInputGamepad() const;
            RayLib::Cursor getCursor() const;
            RayLib::Drawing getDrawing() const;
            RayLib::Camera getCamera() const;

            inline size_t getRefreshRate() const
            {
                return (this->__fps);
            }
        private:
            Window() = delete;
            Window(float width, float height, const std::string &title);
            Window(const Window &) = delete;
            Window &operator = (const Window &) = delete;
            ~Window();
            float _clock;
            RayLib::InputMouse _inputMouse;
            RayLib::InputKeyboard _inputKeyboard;
            RayLib::InputGamepad _inputGamepad;
            RayLib::Cursor _cursor;
            RayLib::Drawing _drawing;
            RayLib::Camera _camera;
            int __fps;

        protected:
    };
}

#endif //BOMBERMAN_RAYLIB_HPP
