/**
 * @file UserConfig.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "UserConfig.hpp"

Bomberman::UserConfig::UserConfig()
{
    std::ifstream t(CONFIG_PATH);

    if (t.is_open() == false) {
        std::ofstream outfile(CONFIG_PATH);
        outfile << "";
        outfile.close();
        return;
    }
    t.close();
}

std::string Bomberman::UserConfig::__typeToKey(const ValueType &type) const
{
    for (int i = 0; i < TAB_SIZE; i++) {
        if (keyTab[i].first == type) {
            return (keyTab[i].second);
        }
    }
    return ("");
}

bool Bomberman::UserConfig::__keyExist(const ValueType &value) const
{
    std::ifstream t(CONFIG_PATH);
    std::string line;
    bool res = false;

    if (t.is_open()) {
        while (std::getline(t, line)) {
            line = line.substr(0, line.find(":"));
            if (line == this->__typeToKey(value)) {
                res = true;
            }
        }
        t.close();
    }
    return (res);
}

std::string Bomberman::UserConfig::__fetchDefaultValue(const ValueType &type) const
{
    for (int i = 0; i < TAB_SIZE; i++) {
        if (defaultTab[i].first == type) {
            return (defaultTab[i].second);
        }
    }
    return ("");
}

int Bomberman::UserConfig::getValue(const ValueType &type) const
{
    std::ifstream t(CONFIG_PATH);
    std::string line;
    std::string res;

    if (t.is_open()) {
        while (std::getline(t, line)) {
            std::string key = line.substr(0, line.find(":"));
            if (key == this->__typeToKey(type)) {
                res = line.substr(line.find(":") + 1);
            }
        }
    }
    if (res.length() == 0) {
        res = this->__fetchDefaultValue(type);
    }
    return (std::stoi(res));
}

std::map<Bomberman::UserConfig::ValueType, int> Bomberman::UserConfig::getGeneralValue() const
{
    std::map<Bomberman::UserConfig::ValueType, int> res;

    res[ValueType::MASTER_VOL] = this->getValue(ValueType::MASTER_VOL);
    res[ValueType::MUSIC_VOL] = this->getValue(ValueType::MUSIC_VOL);
    res[ValueType::FPS] = this->getValue(ValueType::FPS);
    return (res);
}

void Bomberman::UserConfig::__refreshExistingValue(const ValueType &type, int value) const
{
    std::vector<std::string> fileLine;
    std::ifstream t(CONFIG_PATH);
    std::string line;

    if (t.is_open()) {
        while (std::getline(t, line)) {
            std::string key = line.substr(0, line.find(":"));
            if (key != this->__typeToKey(type)) {
                fileLine.push_back(line);
            }
        }
        t.close();
        fileLine.push_back(this->__typeToKey(type) + ":" + std::to_string(value));
        std::ofstream outfile(CONFIG_PATH);
        if (outfile.is_open()) {
            for (std::string const &val : fileLine) {
                outfile << val << std::endl;
            }
            outfile.close();
        }
    }

}

void Bomberman::UserConfig::setValue(const ValueType &type, int value) const
{
    if (this->__keyExist(type) == true) {
        this->__refreshExistingValue(type, value);
    } else {
        std::ofstream outfile(CONFIG_PATH, std::ios_base::app);
        outfile << this->__typeToKey(type) + ":" + std::to_string(value) << std::endl;
        outfile.close();
    }
}