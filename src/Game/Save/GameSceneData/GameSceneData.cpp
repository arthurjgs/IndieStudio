/**
 * @file GameSceneData.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "GameSceneData.hpp"

std::vector<std::string> Bomberman::GameSceneData::splitFromSep(char sep, const std::string &line)
{
    std::vector<std::string> res;
    std::string current = line;
    std::replace(current.begin(), current.end(), sep, ' ');

    std::stringstream ss(current);
    std::string temp;

    while (ss >> temp) {
        res.push_back(temp);
    }
    return (res);
}

Bomberman::GameSceneData::GameSceneData(const std::string &path)
{
    this->__savePath = path;

    std::ifstream infile(this->__savePath);
    std::string line = "";
    std::string lineData = "";

    if (infile.is_open() == false) {
        throw std::runtime_error(path + " -> does not exist");
    }
    while (std::getline(infile, line)) {
        if (line.substr(0, line.find(':')) == "timer") {
            this->__timer = std::stoi(line.substr(line.find(':') + 1, line.length()));
        }
        if (line.substr(0, line.find(':')) == "player") {
            lineData = line.substr(line.find(':') + 1, line.length());
            std::vector<std::string> res = this->splitFromSep(',', lineData);
            this->__dllContainer.push_back(res[1]);
            this->__playerIa.push_back(std::stoi(res[2]));
            this->__playerInputIds.push_back(std::stoi(res[3]));
        }
    }
}