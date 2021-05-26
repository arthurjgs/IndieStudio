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
}

void Bomberman::LoadingScreen::update(const double &elapsed)
{
    (void)elapsed;
}

void Bomberman::LoadingScreen::drawScene()
{
    std::cout << "DRAWING LOADING" << std::endl;
    this->__text.DrawText("LOADING SCREEN", 500, 500, 100, Type::Color(0, 0, 0, 255));
}
