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

Bomberman::Map::~Map() = default;

void Bomberman::Map::render() const
{
    this->_map->drawMap(1.0f, Type::Color(255, 255, 255, 255));
}

void Bomberman::Map::update(const double &elapsed)
{
    (void) elapsed;
}

std::vector<std::shared_ptr<Bomberman::Crate>> Bomberman::Map::createCratesSaves(const std::string &path)
{
    std::vector<std::shared_ptr<Bomberman::Crate>> vec;
    std::ifstream infile(path);
    std::string line = "";
    std::string lineData = "";

    if (infile.is_open() == false) {
        throw std::runtime_error(path + " -> does not exist");
    }
    while (std::getline(infile, line)) {
        if (line.substr(0, line.find(':')) == "crate") {
            lineData = line.substr(line.find(':') + 1, line.length());
            std::vector<std::string> res = GameSceneData::splitFromSep(',', lineData);
            std::vector<std::string> posRes = GameSceneData::splitFromSep('|', res[2]);
            posRes[0].erase(std::remove(posRes[0].begin(), posRes[0].end(), '{'), posRes[0].end());
            posRes[2].erase(std::remove(posRes[2].begin(), posRes[2].end(), '}'), posRes[2].end());
            vec.emplace_back(std::make_shared<Crate>(Type::Vector<3>(std::stof(posRes[0]), std::stof(posRes[1]), std::stof(posRes[2]))));
        }
    }
    return (vec);
}

std::vector<std::shared_ptr<Bomberman::Crate>> Bomberman::Map::createCrates(const double &percentage)
{
    std::vector<std::shared_ptr<Bomberman::Crate>> crates;
    int width = _map->getWidth() - 1;
    int height = _map->getHeight() - 1;

    srand(time(nullptr));
    for (int z = 1; z < height; z++) {
        for (int x = 1; x < width; x++) {
            // TOP LEFT CORNER
            if (x == 1 && z == 1 ||
                x == 2 && z == 1 ||
                x == 1 && z == 2) {
                continue;
            }
            // TOP RIGHT CORNER
            if (x == width - 1 && z == 1 ||
                x == width - 2 && z == 1 ||
                x == width - 1 && z == 2) {
                continue;
            }
            // BOTTOM LEFT CORNER
            if (x == 1 && z == height - 1 ||
                x == 2 && z == height - 1 ||
                x == 1 && z == height - 2) {
                continue;
            }
            // BOTTOM RIGHT CORNER
            if (x == width - 1 && z == height - 1 ||
                x == width - 2 && z == height - 1 ||
                x == width - 1 && z == height - 2) {
                continue;
            }
            if (rand() % (100 + 1) <= percentage) {
                Type::Vector<3> pos(this->getPosition().getX() + static_cast<float>(x),
                                    this->getPosition().getY(),
                                    this->getPosition().getZ() + static_cast<float>(z));
                crates.emplace_back(std::make_shared<Crate>(pos));
            }
        }
    }
    return crates;
}

Type::Vector<2> Bomberman::Map::getCubicMap()
{
    return _map->getCubicMap();
}

std::vector<Type::Color> Bomberman::Map::getMapPixels()
{
    return _map->getMapPixels();
}
