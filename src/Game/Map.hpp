/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_MAP_HPP
#define BOMBERMAN_MAP_HPP

#include <RayLib/Model/Map/Map.hpp>
#include "GameObject.hpp"
#include <vector>
#include <Game/Crate/Crates.hpp>

namespace Bomberman {
    class Map : public GameObject{
    public:
        Map(const std::string &filepath, const Type::Vector<3> &position);
        virtual ~Map();
        Type::Vector<2> getCubicMap();
        std::vector<Type::Color> getMapPixels();
        std::vector<std::shared_ptr<Bomberman::Crate>> createCrates(const double &percentage);
        void render() const override;
        void update(const double &elapsed) override;
    protected:
    private:
        std::unique_ptr<RayLib::Models::Map> _map;
    };
}

#endif //BOMBERMAN_MAP_HPP
