/**
 * @file MainLobby.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../SceneManager/Scene/Scene.hpp"

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
                std::vector<std::shared_ptr<GameObject>> __objContainer;
        };
    }
}