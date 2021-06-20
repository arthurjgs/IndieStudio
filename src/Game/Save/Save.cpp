/**
 * @file Save.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Save.hpp"

Bomberman::SaveData::SaveData(const std::vector<std::shared_ptr<GameObject>> &list, const std::vector<std::weak_ptr<Bomberman::Player>> &players, int timer)
{
    this->__timer = timer;
    for (const auto &val : list) {
        if (val->getType() == GameObject::DESTRUCTIBLE) {
            this->__cratesVec.push_back(val);
        }
    }
    for (const auto &val : players) {
        this->__playerVec.push_back(val);
    }
}


Bomberman::SaveData::SaveData(SaveData &&cpy)
{
    this->__timer = cpy.__timer;
    cpy.__timer = 0;
    for (auto &val : cpy.__cratesVec) {
        this->__cratesVec.push_back(std::move(val));
    }
    for (auto &val : cpy.__playerVec) {
        this->__playerVec.push_back(std::move(val));
    }
    cpy.__cratesVec.clear();
    cpy.__playerVec.clear();
}

Bomberman::SaveData &Bomberman::SaveData::operator = (SaveData &&cpy)
{
    this->__timer = cpy.__timer;
    cpy.__timer = 0;
    for (auto &val : cpy.__cratesVec) {
        this->__cratesVec.push_back(std::move(val));
    }
    for (auto &val : cpy.__playerVec) {
        this->__playerVec.push_back(std::move(val));
    }
    cpy.__cratesVec.clear();
    cpy.__playerVec.clear();
    return (*this);
}

void Bomberman::Save::__writePlayer(const std::weak_ptr<Bomberman::Player> &val, std::ofstream &file) const
{
    file << "player:" << val.lock()->getName() << ",";
    file << val.lock()->getPath() << ",";
    file << val.lock()->getIsAi() << ",";
    file << val.lock()->getController() << ",";
    file << val.lock()->getBombs() << ",";
    file << val.lock()->getDisplay() << ",";
    file << "{" << val.lock()->getPosition().getX() << "|" << val.lock()->getPosition().getY() << "|" << val.lock()->getPosition().getZ() << "}" << ",";
    file << val.lock()->getSpeed() << ",";
    file << val.lock()->getRange() << ",";
    file << val.lock()->getAlive();
    file << std::endl;
}

void Bomberman::Save::__writeCrate(const std::weak_ptr<GameObject> &val, std::ofstream &file) const
{
    file << "crate:" << val.lock()->getName() << ",";
    file << val.lock()->getDisplay() << ",";
    file << "{" << val.lock()->getPosition().getX() << "|" << val.lock()->getPosition().getY() << "|" << val.lock()->getPosition().getZ() << "}";
    file << std::endl;
}


void Bomberman::Save::__writeDataInFile() const
{
    std::ofstream myfile(this->__filepath);

    if (!myfile.is_open()) {
        throw std::runtime_error("creation of : " + this->__filepath + " failed");
    }
    myfile << "timer:" << this->__data.getTimer() << std::endl;
    for (auto const &val : this->__data.getPlayers()) {
        this->__writePlayer(val, myfile);
    }
    for (auto const &val : this->__data.getCrates()) {
        this->__writeCrate(val, myfile);
    }
}

Bomberman::Save::Save(SaveData &&data, const std::string &filepath) :
__data(std::move(data))
{
    this->__filepath = SAVE_FOLDER + filepath + ".yml";
    this->__writeDataInFile();
}

Bomberman::SaveData &&Bomberman::Save::__loadDataFromPath()
{
    std::vector<std::weak_ptr<Player>> v1;
    return SaveData(std::vector<std::shared_ptr<GameObject>>(), v1, 0);
    // load data from file
}

Bomberman::Save::Save(const std::string &filepath) :
__data(std::move(__loadDataFromPath())),
__filepath(SAVE_FOLDER + filepath + ".yml")
{
}