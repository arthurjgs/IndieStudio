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

namespace Bomberman {
    class Map : public GameObject{
    public:
        Map(const std::string &filepath, const Type::Vector<3> &position);
        virtual ~Map();
        void render() const override;
        void update(const double &elapsed) override;
    protected:
    private:
        std::unique_ptr<RayLib::Models::Map> _map;
    };
}

#endif //BOMBERMAN_MAP_HPP
