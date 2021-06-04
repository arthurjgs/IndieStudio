/**
 * @file Credits.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../SceneManager/Scene/Scene.hpp"
#include "../../GameObject.hpp"
#include <vector>
#include <memory>

namespace Bomberman {
    namespace Menu {
        class Credits : public Scene {
            public:
                Credits() = delete;
                Credits(SceneManager &manager);
                ~Credits() = default;

                Credits(const Credits &) = delete;
                Credits &operator = (const Credits &) = delete;

                void update(const double &elapsed);
                void drawScene();
            protected:
            private:
                std::vector<std::unique_ptr<GameObject>> __objContainer;
        };
    }
}