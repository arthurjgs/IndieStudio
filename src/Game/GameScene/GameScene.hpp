/**
 * @file TestScene.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <Game/Player.hpp>
#include <Game/Map.hpp>
#include <Types/Camera/Camera3D.hpp>
#include <Game/Image/Image.hpp>
#include "../SceneManager/Scene/Scene.hpp"
#include "../../RayLib/Text/Text.hpp"
#include "../Button/Button.hpp"

namespace Bomberman {
    class GameScene : public Scene {
        public:
            GameScene() = delete;
            GameScene(SceneManager &manager,
                      const std::string &playerDll1, const std::string &playerDll2,
                      const std::string &playerDll3, const std::string &playerDll4);
            ~GameScene() = default;
            GameScene(const GameScene &) = delete;
            GameScene &operator = (const GameScene &) = delete;

            bool checkColision(int playerIndex) const;
            void update(const double &elapsed);
            void drawScene();
        protected:
        private:
            Bomberman::Image _background;
            Type::Camera3D _camera;
            std::unique_ptr<Bomberman::Map> _gameMap;
            std::array<std::unique_ptr<Bomberman::Player>, 4> _listPlayers;
    };
}