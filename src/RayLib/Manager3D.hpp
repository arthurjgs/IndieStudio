/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_MANAGER3D_HPP
#define BOMBERMAN_MANAGER3D_HPP

#include <map>
#include <memory>
#include <RayLib/Model/Animate/Animate.hpp>
#include <Game/GameException.hpp>

namespace RayLib {
    class Manager3D {
    public:
        enum Scene {
            NONE,
            GAME,
            PLAYER_SELECTION,
            MAP_SELECTION
        };
        static Manager3D &getInstance();
        void setScene(Scene nextScene);
        std::shared_ptr<RayLib::Models::Animate> getModel(const std::string &object);
    private:
        Manager3D() = delete;
        Manager3D(Scene scene);
        Manager3D(const Manager3D &) = delete;
        Manager3D &operator=(const Manager3D &)=delete;
        ~Manager3D();
        Scene _currentScene;
        void load3DModels();
        void loadPlayers();
        void loadObjects();
        std::map<std::string, std::shared_ptr<RayLib::Models::Animate>> _models;
    };
}

#endif //BOMBERMAN_MANAGER3D_HPP
