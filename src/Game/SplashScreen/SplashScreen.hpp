/**
 * @file SplashScreen.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../SceneManager/Scene/Scene.hpp"
#include "../UserConfig/UserConfig.hpp"
#include "../Image/Image.hpp"
#include <memory>
#include "../../RayLib/Audio/Sound/Sound.hpp"

namespace Bomberman {
    class SplashScreen : public Scene {
            public:
                SplashScreen() = delete;
                SplashScreen(SceneManager &manager);
                ~SplashScreen() = default;

                SplashScreen(const SplashScreen &) = delete;
                SplashScreen &operator = (const SplashScreen &) = delete;

                void update(const double &elapsed);
                void drawScene();
            protected:
            private:
                std::unique_ptr<Image> __image;
                double __second;
                RayLib::Audio::Sound _sound;
    };
}