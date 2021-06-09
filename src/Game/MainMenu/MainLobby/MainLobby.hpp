/**
 * @file MainLobby.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../SceneManager/Scene/Scene.hpp"

#include "../../Parralax/Parralax.hpp"
#include "../../Image/Image.hpp"
#include "../../Button/Button.hpp"
#include <map>
#include <functional>
#include "../SelectionMenu/SelectionMenu.hpp"

namespace Bomberman {
    namespace Menu {
        class MainLobby : public Scene {
            public:
                MainLobby() = delete;
                MainLobby(SceneManager &manager);
                ~MainLobby() = default;

                MainLobby(const MainLobby &) = delete;
                MainLobby &operator = (const MainLobby &) = delete;

                void update(const double &elapsed);
                void drawScene();
            protected:
            private:
                enum MENU_UI {
                    MAIN,

                };

                void playButtonCallback();
                void loadButtonCallback();
                void quitButtonCallback();
                void settingsButtonCallback();

                std::vector<std::shared_ptr<GameObject>> __objContainer;
                std::vector<std::pair<MENU_UI, std::weak_ptr<Button>>>__buttonsReferer;
                std::map<std::string, std::function<void(MainLobby &)>> __buttonCallback;
        };
    }
}