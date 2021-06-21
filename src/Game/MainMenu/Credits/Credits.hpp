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
#include "../../Image/Image.hpp"
#include "../../FlashingText/FlashingText.hpp"
#include "../../UserConfig/UserConfig.hpp"
#include <vector>
#include <memory>

#define SPEED 35

namespace Bomberman {
    namespace Menu {
        class CreditsComponent {
            public:
                CreditsComponent() = delete;
                CreditsComponent(const std::string &imgPath, const std::vector<std::string> &textVec);
                CreditsComponent(const CreditsComponent &) = delete;
                CreditsComponent &operator = (const CreditsComponent &) = delete;
                ~CreditsComponent() = default;

                bool updateTextVec(double speed);
                void draw() const;

            protected:
            private:
                Image __img;
                std::vector<std::unique_ptr<FlashingText>> __textVec;
                float __speedContainer;
        };

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
                std::vector<std::shared_ptr<GameObject>> __objContainer;
                int __textIndex;
                std::vector<std::pair<int, std::unique_ptr<CreditsComponent>>> __textVector;
                UserConfig __configHandler;
        };
    }
}