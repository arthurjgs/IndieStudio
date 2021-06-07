/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

#include <RayLib/Model/Animate/Animate.hpp>
#include "Game/GameObject.hpp"
#include <vector>
#include <filesystem>
#include "Game/GameException.hpp"

namespace Bomberman {
    class Bomb : public GameObject {
    public:
        Bomb(const std::string &assetPath, const Type::Vector<3> &position, double startTimer, int range);
        ~Bomb();
        void update(const double &elapsed);
        void render() const;
    protected:
    private:
        std::vector<std::filesystem::path> _texturesList;
        double _startTimer;
        int _range;
        std::unique_ptr<RayLib::Models::Animate> _model;
    };
}

#endif //BOMBERMAN_BOMB_HPP
