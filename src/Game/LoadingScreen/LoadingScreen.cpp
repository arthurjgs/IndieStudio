/**
 * @file LoadingScreen.cpp
 * @brief LOADING SCREEN SCENE
 * @version 0.1
 * @date 2021-05-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "LoadingScreen.hpp"

Bomberman::LoadingScreen::LoadingScreen(SceneManager &manager) :
Scene(manager)
{
    this->__objectContainer.push_back(std::make_unique<SpriteSheetPlayer>("./assets/LoadingScreen/loading.png", 8, Type::Rectangle(0, 0, 270, 350), Type::Vector<2>(500.0f, 500.0f), "loading_wheel", 91, true));
}

void Bomberman::LoadingScreen::update(const double &elapsed)
{
    for (std::unique_ptr<Bomberman::GameObject> &val : this->__objectContainer) {
        val->update(elapsed);
    }
}

void Bomberman::LoadingScreen::drawScene()
{
    for (const std::unique_ptr<Bomberman::GameObject> &val : this->__objectContainer) {
        val->render();
    }
}
