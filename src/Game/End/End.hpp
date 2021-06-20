/**
 * @file End.hpp
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
#include "../Button/Button.hpp"
#include "../Music/Music.hpp"
#include "../../RayLib/Audio/Sound/Sound.hpp"
#include <functional>
#include <map>

namespace Bomberman {
    class End : public Scene {
        public:
            End() = delete;
            End(SceneManager &manager);
            ~End() = default;

            End(const End &) = delete;
            End &operator = (const End &) = delete;
            void update(const double &elapsed);
            void drawScene();
        protected:
        private:
            void quit();
            void menu();

            std::vector<std::shared_ptr<GameObject>> __objContainer;
            std::vector<std::weak_ptr<Button>> _buttonRef;
            std::map<std::string, std::function<void(End &)>> _buttonCallbacks;
            UserConfig __config;
            bool _quitting;
            RayLib::Audio::Sound _sound;
    };
}