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

#include "../SceneManager/Scene/Scene.hpp"
#include "../../RayLib/Text/Text.hpp"

namespace Bomberman {
    class TestScene : public Scene {
        public:
            TestScene() = delete;
            TestScene(SceneManager &manager);
            ~TestScene() = default;
            TestScene(const TestScene &) = delete;
            TestScene &operator = (const TestScene &) = delete;

            void update(const double &elapsed);
            void drawScene();
        protected:
        private:
            RayLib::Text __text;
    };
}