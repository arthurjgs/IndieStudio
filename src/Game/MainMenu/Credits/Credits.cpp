/**
 * @file Credits.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Credits.hpp"
#include "../../../RayLib/Window.hpp"

Bomberman::Menu::Credits::Credits(SceneManager &manager) : Scene(manager)
{

}

void Bomberman::Menu::Credits::update(const double &elapsed)
{
    RayLib::Window &win = RayLib::Window::getInstance();

    // TODO: HANDLE RETURN WITH CONTROLLER
    if (win.getInputKeyboard().isKeyPressed(::KEY_BACKSPACE)) {
        this->__manager.unloadScene();
        return;
    }
    for (auto const &val : this->__objContainer) {
        val->update(elapsed);
    }
}

void Bomberman::Menu::Credits::drawScene()
{
    for (auto const &val : this->__objContainer) {
        if (val->getDisplay()) {
            val->render();
        }
    }
}