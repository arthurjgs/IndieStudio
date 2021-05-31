/**
 * @file TitleScreen.hpp
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
        class TitleScreen : public Scene {
            public:
                TitleScreen() = delete;
                TitleScreen(SceneManager &manager);
                ~TitleScreen() = default;

                TitleScreen(const TitleScreen &) = delete;
                TitleScreen &operator = (const TitleScreen &) = delete;

                void update(const double &elapsed);
                void drawScene();
            protected:
            private:
        };
    }
}