/**
 * @file MainMenu.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "../../SceneManager/Scene/Scene.hpp"

namespace Bomberman {
    namespace MenuScenes {
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
        };
    }
}