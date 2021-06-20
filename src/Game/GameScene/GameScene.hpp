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

#include "../Save/Save.hpp"
#include <players/Player.hpp>
#include <Game/Map.hpp>
#include <Types/Camera/Camera3D.hpp>
#include <Game/Image/Image.hpp>
#include <Game/Music/Music.hpp>
#include "../SceneManager/Scene/Scene.hpp"
#include "../../RayLib/Text/Text.hpp"
#include "../Button/Button.hpp"
#include "../FlashingText/FlashingText.hpp"
#include "../Save/PlayerData/PlayerData.hpp"
#include "../UserConfig/UserConfig.hpp"
#include <map>
#include <functional>
#include "../../RayLib/Audio/Sound/Sound.hpp"

namespace Bomberman {
    class GameScene : public Scene {
        public:
            GameScene() = delete;
            GameScene(SceneManager &manager, const std::vector<int> &playerInputIds, const std::vector<int> &playerIa,
                      const std::string &playerDll1, const std::string &playerDll2,
                      const std::string &playerDll3, const std::string &playerDll4, const std::string &savePath = "", const int timer = 180);
            ~GameScene() = default;
            GameScene(const GameScene &) = delete;
            GameScene &operator = (const GameScene &) = delete;

            bool checkCollisionForMap(const Type::Vector<3> &playerPosition) const;
            
            enum COLLIDE_EVENT {
                NOTHING,
                BASIC,
                DEATH
            };
            
            COLLIDE_EVENT checkCollisionForObjects(const Type::Vector<3> &playerPosition, bool isFlame = false, bool isBomb = false) const;
            void update(const double &elapsed);
            void drawScene();
        protected:
        private:
            void continueCallback();
            void saveCallback();
            void quitCallback();
            void confirmSaveCallback();
            void cancelSaveCallback();

            void handleSaveNaming();
            std::string convertSecondToDisplayTime(int value) const;
            std::string addZeroOrNot(int value) const;
            std::weak_ptr<FlashingText> getTextFromName(const std::string &name);
            std::weak_ptr<GameObject> getObjectFromName(const std::string &name);
            std::shared_ptr<Player> loadPlayerDll(const std::string &dllPath, int inputId, int isIa, const Type::Vector<3> &position);
            std::shared_ptr<Player> loadPlayerFromSave(const PlayerData &data);
        
            
            void __createCratesFromSaves(const std::string &path);

            void createPause();
            void updatePause(const double &elasped);

            enum UI_SCENE {
                MAIN,
                PAUSE,
                NONE,
            };

            std::vector<std::shared_ptr<Bomberman::GameObject>> _gameObjectList;
            std::vector<std::weak_ptr<Bomberman::Player>> _listPlayers;
            std::vector<std::pair<UI_SCENE, std::shared_ptr<GameObject>>> _2DGameObjectList;
            std::vector<std::pair<UI_SCENE, std::weak_ptr<FlashingText>>> _2DDynamicText;
            std::vector<std::pair<UI_SCENE, std::weak_ptr<Button>>> _2DButtonList;
            std::vector<std::weak_ptr<Bomberman::Crate>> _CrateList;
            std::map<std::string, std::function<void(GameScene &)>>  _buttonCallback; 

            UI_SCENE _currentUIStage;
            std::vector<std::weak_ptr<Bomberman::Bomb>> _bombList;
            std::weak_ptr<Map> _gameMap;
            std::shared_ptr<Image> _background;
            Type::Camera3D _camera;
            int _timer;
            double _second;
            bool _pause;
            bool quitting;
            bool isInput;
            std::string _saveName;
            double _everySecond;
            RayLib::Audio::Sound _soundExplosion;
            RayLib::Audio::Sound _soundFlame;
            RayLib::Audio::Sound _soundDeath;
            RayLib::Audio::Sound _soundBombFuse;

            bool _checkCamera;
            double _timerCamera;
            float _cameraOriginX;
            float _cameraOriginZ;

            int _cratesPct;
            int _bonusPct;
            UserConfig __confingHandler;

            bool __lastAlive() const;
    };
}