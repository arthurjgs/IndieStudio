/**
 * @file MainMenu.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include "../SceneManager/Scene/Scene.hpp"
#include "./MainLobby/MainLobby.hpp"
#include "../FlashingText/FlashingText.hpp"
#include "../../RayLib/Window.hpp"
#include "../UserConfig/UserConfig.hpp"
#include <vector>
#include <memory>

namespace Bomberman {
    namespace Menu {
        class MainMenu : public Scene {
            public:
                MainMenu() = delete;
                MainMenu(SceneManager &manager);
                ~MainMenu() = default;

                MainMenu(const MainMenu &) = delete;
                MainMenu &operator = (const MainMenu &) = delete;

                void update(const double &elapsed);
                void drawScene();
            protected:
            private:
                std::vector<std::shared_ptr<GameObject>> __objContainer;
                UserConfig __config;
        };
    }
}