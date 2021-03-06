/**
 * @file SelectionMenu.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../SceneManager/Scene/Scene.hpp"
#include "../../FlashingText/FlashingText.hpp"
#include "../../../RayLib/Window.hpp"
#include "../../Image/Image.hpp"
#include "../../StateImage/StateImage.hpp"
#include "../../../RayLib/Audio/Sound/Sound.hpp"
#include <vector>
#include <memory>
#include <players/Player.hpp>
#include "../../UserConfig/UserConfig.hpp"

namespace Bomberman
{
    namespace Menu
    {
        class SelectionMenu : public Scene {
            public:
                SelectionMenu() = delete;
                SelectionMenu(SceneManager &manager);
                ~SelectionMenu() = default;
                SelectionMenu(const SelectionMenu &) = delete;
                SelectionMenu &operator = (const SelectionMenu &) = delete;

                void update(const double &elapsed);
                void drawScene();

            protected:
            private:
                void loadPlayers();
                void cancel();
                void cancelSquareState();
                void ready();
                void readySquareState();
                void isKeyboardOrGamepad();
                void handleGamepads(int gamepad);
                void changeStateSelection(int gamepad, bool available);
                void checkPlayers();
                void goToGameScene();
                std::vector<std::shared_ptr<GameObject>> __objContainer;
                std::vector<std::shared_ptr<Player>> __modelsContainer;
                std::vector<std::shared_ptr<Player>> __modelsContainer1;
                std::vector<std::shared_ptr<Player>> __modelsContainer2;
                std::vector<std::shared_ptr<Player>> __modelsContainer3;
                std::vector<std::string> getPlayerDlls();
                int _players;
                Type::Camera3D _camera;
                std::vector<std::weak_ptr<StateImage>>__stateImagesReferer;
                std::vector<std::weak_ptr<FlashingText>> __flashingTextReferer;
                int _selectionPlayer;
                bool _isAction;
                std::vector<int> _selectedModel {0, -1, -1, -1};
                std::vector<int> _playerInputIds {-1, 0, 1, 2};
                RayLib::Audio::Sound _readySound;
                UserConfig __config;

        };
    }
}
