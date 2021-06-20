/**
 * @file UserConfig.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#define CONFIG_PATH "./config.yml"

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <map>
#include <vector>
#include "../../RayLib/Window.hpp"

namespace Bomberman {
    class UserConfig {
        public:
            UserConfig();
            ~UserConfig() = default;

            UserConfig(const UserConfig &) = delete;
            UserConfig &operator = (const UserConfig &) = delete;

            enum ValueType {
                MASTER_VOL,
                MUSIC_VOL,
                FPS,
                VERTICAL_SYNC,
                CRATE_DROP,
                BONUS_DROP,
            };

            int getValue(const ValueType &type) const;
            std::map<ValueType, int> getGeneralValue() const;
            void setValue(const ValueType &type, int value) const;
        protected:
        private:
            bool __keyExist(const ValueType &value) const;
            std::string __typeToKey(const ValueType &type) const;
            void __refreshExistingValue(const ValueType &type, int value) const;
            std::string __fetchDefaultValue(const ValueType &type) const;
    };
}

#define TAB_SIZE 6

static const std::pair<Bomberman::UserConfig::ValueType, const std::string> keyTab[] = {
    std::make_pair(Bomberman::UserConfig::ValueType::MASTER_VOL, "masterVolume"),
    std::make_pair(Bomberman::UserConfig::ValueType::MUSIC_VOL, "musicVolume"),
    std::make_pair(Bomberman::UserConfig::ValueType::FPS, "fps"),
    std::make_pair(Bomberman::UserConfig::ValueType::VERTICAL_SYNC, "vsync"),
    std::make_pair(Bomberman::UserConfig::ValueType::CRATE_DROP, "crate"),
    std::make_pair(Bomberman::UserConfig::ValueType::BONUS_DROP, "bonus"),
};

static const std::pair<Bomberman::UserConfig::ValueType, const std::string> defaultTab[] = {
    std::make_pair(Bomberman::UserConfig::ValueType::MASTER_VOL, "100"),
    std::make_pair(Bomberman::UserConfig::ValueType::MUSIC_VOL, "100"),
    std::make_pair(Bomberman::UserConfig::ValueType::FPS, std::to_string(RayLib::Window::getInstance().getMonitorRefreshRate())),
    std::make_pair(Bomberman::UserConfig::ValueType::VERTICAL_SYNC, "1"),
    std::make_pair(Bomberman::UserConfig::ValueType::CRATE_DROP, "75"),
    std::make_pair(Bomberman::UserConfig::ValueType::BONUS_DROP, "10"),
};