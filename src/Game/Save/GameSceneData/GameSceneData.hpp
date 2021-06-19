/**
 * @file GameSceneData.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

namespace Bomberman {
    class GameSceneData {
        public:
            GameSceneData() = delete;
            GameSceneData(const std::string &path);
            GameSceneData(const GameSceneData &) = delete;
            GameSceneData &operator = (const GameSceneData &) = delete;

            ~GameSceneData() = default;

            static std::vector<std::string> splitFromSep(char sep, const std::string &line);

            inline std::vector<int> getPlayerInputIds() const { return (this->__playerInputIds); }
            inline std::vector<int> getPlayerIa() const { return (this->__playerIa); }
            inline std::string getDll1() const { return (this->__dllContainer[0]); }
            inline std::string getDll2() const { return (this->__dllContainer[1]); }
            inline std::string getDll3() const { return (this->__dllContainer[2]); }
            inline std::string getDll4() const { return (this->__dllContainer[3]); }
            inline std::string getSavePath() const { return (this->__savePath); }
            inline int getTimer() const { return (this->__timer); }
        protected:
        private:
            std::vector<int> __playerInputIds;
            std::vector<int> __playerIa;
            std::vector<std::string> __dllContainer;
            std::string __savePath;
            int __timer;
    };
}