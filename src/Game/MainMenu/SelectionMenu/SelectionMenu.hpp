/**
 * @file SelectionMenu.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../SceneManager/Scene/Scene.hpp"
#include "../../FlashingText/FlashingText.hpp"
#include "../../../RayLib/Window.hpp"
#include "../../Image/Image.hpp"
#include <vector>
#include <memory>

namespace Bomberman
{
    namespace Menu
    {
        class SelectionMenu : public Scene {
            public:
                SelectionMenu() = delete;
                SelectionMenu(SceneManager &manager);
                ~SelectionMenu() = default;
                SelectionMenu(const SelectionMenu &) = delete;
                SelectionMenu &operator = (const SelectionMenu &) = delete;

                void update(const double &elapsed);
                void drawScene();

            protected:
            private:
                std::vector<std::shared_ptr<GameObject>> __objContainer;
                int _players;
                bool _firstPlayerGamepad;
        };
    }
}
