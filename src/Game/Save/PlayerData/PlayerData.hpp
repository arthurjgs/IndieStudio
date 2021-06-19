/**
 * @file PlayerData.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include "../../../Types/Vector/Vector.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "../GameSceneData/GameSceneData.hpp"
#include <regex>

namespace Bomberman {
    class PlayerData {
        public:
            PlayerData() = delete;
            PlayerData(const std::string &name, const std::string &path, bool ai, int controller, int bombs, bool display, const Type::Vector<3> &positions, double speed, int range);
            PlayerData(const PlayerData &cpy);
            PlayerData &operator = (const PlayerData &cpy);
        
            ~PlayerData() = default;

            inline std::string getName() const { return (this->__name); }
            inline std::string getPath() const { return (this->__path); }
            inline bool getAi() const { return (this->__ai); }
            inline int getController() const { return (this->__controller); }
            inline int getBombs() const { return (this->__bombs); }
            inline bool getDisplay() const { return (this->__display); }
            inline Type::Vector<3> getPositions() const { return (this->__positions); }
            inline double getSpeed() const { return (this->__speed); }
            inline int getRange() const { return (this->__range); }
        protected:
        private:
            std::string __name;
            std::string __path;
            bool __ai;
            int __controller;
            int __bombs;
            bool __display;
            Type::Vector<3> __positions;
            double __speed;
            int __range;
    };

    class PlayerParse {
        public:
            PlayerParse() = delete;
            PlayerParse(const PlayerParse &) = delete;
            PlayerParse(const std::string &savePath);
            PlayerParse &operator = (const PlayerParse &) = delete;

            ~PlayerParse() = default;

            inline PlayerData &getPlayerOne() { return (this->__container[0]); }
            inline PlayerData &getPlayerTwo() { return (this->__container[1]); }
            inline PlayerData &getPlayerThree() { return (this->__container[2]); }
            inline PlayerData &getPlayerFour() { return (this->__container[3]); }

        protected:
        private:
            std::vector<PlayerData> __container;
    };
}