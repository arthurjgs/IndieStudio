/**
 * @file SplashScreen.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "SplashScreen.hpp"
#include "Game/MainMenu/MainMenu.hpp"

Bomberman::SplashScreen::SplashScreen(SceneManager &manager) :
Scene(manager)
{
    this->__second = 0.0;
    this->__image = std::make_unique<Image>("./assets/MainMenu/ea.png", "ea", GameObject::ObjectType::DECOR, Type::Vector<3>(685.0f, 300.0f, 0.0f));
    Type::Color &col = this->__image->getColor();

    uChar &a = col.getA();
    a = 0;
}

void Bomberman::SplashScreen::update(const double &elapsed)
{
    this->__second += elapsed;

    if (this->__second > 0.009) {
        Type::Color &col = this->__image->getColor();

        uChar &a = col.getA();
        a++;
        if (a == 255) {
            this->__manager.clearStack<Menu::MainMenu>();
        }
        this->__second = 0.0;
    }
}

void Bomberman::SplashScreen::drawScene()
{
    this->__image->render();
}