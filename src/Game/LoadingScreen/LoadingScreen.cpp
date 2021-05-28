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
    this->__objectContainer.push_back(std::make_unique<SpriteSheetPlayer>("./assets/LoadingScreen/loading_word.png", 5, Type::Rectangle(0, 0, 400, 300), Type::Vector<2>(1500.0f, 800.0f), "loading_word", 32, true));
    this->__objectContainer.push_back(std::make_unique<SpriteSheetPlayer>("./assets/LoadingScreen/loading_wheel.png", 5, Type::Rectangle(0, 0, 400, 300), Type::Vector<2>(1200.0f, 795.0f), "loading_wheel", 120, true));
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
        if (val->getDisplay()) {    
            val->render();
        }
    }
}
