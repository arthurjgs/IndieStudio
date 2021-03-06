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
#include "../GameObject.hpp"
#include <vector>
#include "../SpriteSheetPlayer/SpriteSheetPlayer.hpp"
#include "../Image/Image.hpp"
#include <memory>

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
            std::vector<std::unique_ptr<GameObject>> __objectContainer;
    };

    template<typename scene, typename ...Args>
    void changeScene(SceneManager &manager, Args &&...args)
    {
        SceneManager &threadManager = manager;

        manager.newScene<LoadingScreen>();
        std::cout << "LOADING SCREEN LOADED" << std::endl;
        std::thread([&threadManager, &args...]() {
            threadManager.replaceTop<scene>(std::forward<Args>(args)...);
            std::cout << "MAIN SCENE LOADED" << std::endl;
        }).detach();
        std::cout << "PASS" << std::endl;
    }
}