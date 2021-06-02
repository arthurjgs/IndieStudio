/**
 * @file MainLobby.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MainLobby.hpp"

Bomberman::Menu::MainLobby::MainLobby(SceneManager &manager) :
Scene(manager)
{
    const std::pair<const std::string, const double> arr[] = {
        std::pair<const std::string, const double>("./assets/MainMenu/layers/1.png", 10.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/2.png", 20.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/3.png", 30.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/4.png", 40.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/5.png", 50.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/6.png", 60.0),
    };

    this->__objContainer.push_back(std::make_shared<Parralax>(arr, 6, "menuParralax", Type::Vector<2>(0.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/MainMenu/lobby.png", "title", GameObject::ObjectType::DECOR, Type::Vector<3>(525.0f, 50.0f, 0.0f)));

}

void Bomberman::Menu::MainLobby::update(const double &elapsed)
{
    for (auto const &val : this->__objContainer) {
        val->update(elapsed);
    }
}

void Bomberman::Menu::MainLobby::drawScene()
{
    for (auto const &val : this->__objContainer) {
        val->render();
    }
}