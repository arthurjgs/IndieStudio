/**
 * @file Save.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../GameObject.hpp"
#include "../Crate/Crates.hpp"
#include "../Player.hpp"
#include <vector>
#include <memory>
#include <fstream>

#define SAVE_FOLDER "./save/"

namespace Bomberman {
    class SaveData {
        public:
            SaveData() = delete;
            SaveData(const std::vector<std::shared_ptr<GameObject>> &list, const std::vector<std::weak_ptr<Bomberman::Player>> &players, int timer);
            ~SaveData() = default;

            SaveData(SaveData &&cpy);
            SaveData &operator = (SaveData &&cpy);

            SaveData(const SaveData &cpy) = delete;
            SaveData &operator = (const SaveData &cpy) = delete;

            inline int getTimer() const { return (this->__timer); }
            inline std::vector<std::weak_ptr<GameObject>> getCrates() const { return (this->__cratesVec); }
            inline std::vector<std::weak_ptr<Player>> getPlayers() const { return (this->__playerVec); }
        protected:
        private:
            std::vector<std::weak_ptr<GameObject>> __cratesVec;
            std::vector<std::weak_ptr<Player>> __playerVec;
            int __timer;
    };
    class Save {
        public:
            Save() = delete;
            Save(SaveData &&data, const std::string &filepath); // use this constructor when writing save
            Save(const std::string &filepath); // use this constructor when reading save
            ~Save() = default;

            Save(const Save &) = delete;
            Save &operator = (const Save &) = delete;

            inline SaveData &&getData() { return (std::move(this->__data)); }
            inline std::string getFilepath() const { return (this->__filepath); }
        protected:
        private:
            SaveData &&__loadDataFromPath();
            void __writeDataInFile() const;

            void __writePlayer(const std::weak_ptr<Player> &val, std::ofstream &file) const;
            void __writeCrate(const std::weak_ptr<GameObject> &val, std::ofstream &file) const;
            
            SaveData __data;
            std::string __filepath;
    };
}