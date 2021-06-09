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
#include <Game/Music/Music.hpp>
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

            bool checkCollision(int playerIndex) const;
            void update(const double &elapsed);
            void drawScene();
        protected:
        private:
            std::vector<std::shared_ptr<Bomberman::GameObject>> _gameObjectList;
            std::vector<std::weak_ptr<Bomberman::Player>> _listPlayers;
            std::weak_ptr<Map> _gameMap;
            std::weak_ptr<Image> _background;
            Type::Camera3D _camera;
    };
}