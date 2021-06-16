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
#include "../FlashingText/FlashingText.hpp"

namespace Bomberman {
    class GameScene : public Scene {
        public:
            GameScene() = delete;
            GameScene(SceneManager &manager,
                      const std::string &playerDll1, const std::string &playerDll2,
                      const std::string &playerDll3, const std::string &playerDll4, const int timer = 180);
            ~GameScene() = default;
            GameScene(const GameScene &) = delete;
            GameScene &operator = (const GameScene &) = delete;

            bool checkCollisionForMap(const Type::Vector<3> &playerPosition) const;
            bool checkCollisionForObjects(const Type::Vector<3> &playerPosition, bool isFlame = false) const;
            void update(const double &elapsed);
            void drawScene();
        protected:
        private:
            std::string convertSecondToDisplayTime(int value);
            std::string addZeroOrNot(int value);
            std::weak_ptr<FlashingText> getTextFromName(const std::string &name);

            enum UI_SCENE {
                MAIN,
            };

            std::vector<std::shared_ptr<Bomberman::GameObject>> _gameObjectList;
            std::vector<std::weak_ptr<Bomberman::Player>> _listPlayers;
            std::vector<std::pair<UI_SCENE, std::shared_ptr<GameObject>>> _2DGameObjectList;
            std::vector<std::pair<UI_SCENE, std::weak_ptr<FlashingText>>> _2DDynamicText;
            UI_SCENE _currentUIStage;
            std::vector<std::weak_ptr<Bomberman::Bomb>> _bombList;
            std::weak_ptr<Map> _gameMap;
            std::weak_ptr<Image> _background;
            Type::Camera3D _camera;
            int _timer;
            double _second;
    };
}