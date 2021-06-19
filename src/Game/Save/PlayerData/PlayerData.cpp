/**
 * @file PlayerData.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "PlayerData.hpp"

Bomberman::PlayerData::PlayerData(const std::string &name, const std::string &path, bool ai, int controller, int bombs, bool display, const Type::Vector<3> &positions, double speed, int range, bool alive) :
__name(name),
__path(path),
__ai(ai),
__controller(controller),
__bombs(bombs),
__display(display),
__positions(positions),
__speed(speed),
__range(range),
__alive(alive)
{

}

Bomberman::PlayerData::PlayerData(const PlayerData &cpy) :
__name(cpy.__name),
__path(cpy.__path),
__ai(cpy.__ai),
__controller(cpy.__controller),
__bombs(cpy.__bombs),
__display(cpy.__display),
__positions(cpy.__positions),
__speed(cpy.__speed),
__range(cpy.__range),
__alive(cpy.__alive)
{

}

Bomberman::PlayerData &Bomberman::PlayerData::operator = (const PlayerData &cpy)
{
    this->__name = cpy.__name;
    this->__path = cpy.__path;
    this->__ai = cpy.__ai;
    this->__controller = cpy.__controller;
    this->__bombs = cpy.__bombs;
    this->__display = cpy.__display;
    this->__positions = cpy.__positions;
    this->__speed = cpy.__speed;
    this->__range = cpy.__range;
    this->__alive = cpy.__alive;
    return (*this);
}

Bomberman::PlayerParse::PlayerParse(const std::string &savePath)
{
    std::ifstream infile(savePath);
    std::string line = "";
    std::string lineData = "";

    if (infile.is_open() == false) {
        throw std::runtime_error(savePath + " -> does not exist");
    }
    while (std::getline(infile, line)) {
        if (line.substr(0, line.find(':')) == "player") {
            lineData = line.substr(line.find(':') + 1, line.length());
            std::vector<std::string> res = GameSceneData::splitFromSep(',', lineData);
            std::vector<std::string> posRes = GameSceneData::splitFromSep('|', res[6]);
            posRes[0].erase(std::remove(posRes[0].begin(), posRes[0].end(), '{'), posRes[0].end());
            posRes[2].erase(std::remove(posRes[2].begin(), posRes[2].end(), '}'), posRes[2].end());
            this->__container.push_back(PlayerData(res[0], res[1], std::stoi(res[2]), std::stoi(res[3]), std::stoi(res[4]), std::stoi(res[5]), Type::Vector<3>(std::stof(posRes[0]), std::stof(posRes[1]), std::stof(posRes[2])), std::stod(res[7]), std::stoi(res[8]), std::stoi(res[9])));
        }
    } 
}

