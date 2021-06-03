/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <filesystem>
#include "Map.hpp"
#include "GameException.hpp"

Bomberman::Map::Map(const std::string &filepath, const Type::Vector<3> &position) : GameObject("Map", DECOR, position, true)
{
    if (std::filesystem::is_directory(filepath)) {
        for (auto &dir : std::filesystem::directory_iterator(filepath)) {
            std::string path = dir.path().string();
            if (path.find("map.png") != std::string::npos) {
                this->_map = std::make_unique<RayLib::Models::Map>(path, position);
            }
        }
        for (auto &dir : std::filesystem::directory_iterator(filepath)) {
            std::string path = dir.path().string();
            if (path.find("texture") != std::string::npos) {
                this->_map->LoadMaterial(path);
            }
        }
    } else {
        throw GameException("Unable to load the map from path : " + filepath);
    }
}

Bomberman::Map::~Map()
{
    this->_map.reset();
}

void Bomberman::Map::render() const
{
    this->_map->drawMap(1.0f, Type::Color(255, 255, 255, 255));
}

void Bomberman::Map::update(const double &elapsed)
{
    (void) elapsed;
}

Type::Vector<2> Bomberman::Map::getCubicMap()
{
    return _map->getCubicMap();
}

std::vector<Type::Color> Bomberman::Map::getMapPixels()
{
    return _map->getMapPixels();
}
