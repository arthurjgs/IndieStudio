/**
 * @file LoadingScreen.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../SceneManager/Scene/Scene.hpp"
#include <thread>
#include "../../RayLib/Text/Text.hpp"

namespace Bomberman {
    class LoadingScreen : public Scene {
        public:
            LoadingScreen() = delete;
            LoadingScreen(SceneManager &manager);
            ~LoadingScreen() = default;
            LoadingScreen(const LoadingScreen &) = delete;
            LoadingScreen &operator = (const LoadingScreen &) = delete;

            void update(const double &elapsed);
            void drawScene();
        protected:
        private:
            RayLib::Text __text;
    };

    template<typename scene, typename ...Args>
    void changeScene(SceneManager &manager, Args &&...args)
    {
        SceneManager &threadManager = manager;

        manager.newScene<LoadingScreen>();
        std::thread([&threadManager]() {

        }).detach();
    }
}