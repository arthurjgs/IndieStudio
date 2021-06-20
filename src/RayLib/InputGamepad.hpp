/**
 * @file InputGamepad.hpp
 * @author alexandre burger
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INPUTGAMEPAD_HPP_
#define INPUTGAMEPAD_HPP_

#include <raylib.h>
#include <iostream>

namespace RayLib
{
    class InputGamepad {
        public:
            InputGamepad();
            ~InputGamepad();
            bool isGamepadAvailable(int gamepad) const;
            bool isGamepadName(int gamepad, const std::string &name) const;
            const std::string getGamepadName(int gamepad) const;
            bool isGamepadButtonPressed(int gamepad, int button) const;
            bool isGamepadButtonDown(int gamepad, int button) const;
            bool isGamepadButtonReleased(int gamepad, int button) const;
            bool isGamepadButtonUp(int gamepad, int button) const;
            int getGamepadButtonPressed(void) const;
            int getGamepadAxisCount(int gamepad) const;
            float getGamepadAxisMovement(int gamepad, int axis) const;
            int setGamepadMappings(const std::string &mappings) const;

        protected:
        private:
    };
}

#endif /* !INPUTGAMEPAD_HPP_ */
