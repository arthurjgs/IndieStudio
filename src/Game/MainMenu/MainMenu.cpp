/**
 * @file MainMenu.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MainMenu.hpp"
#include "./MainLobby/MainLobby.hpp"

Bomberman::Menu::MainMenu::MainMenu(SceneManager &manager) :
Scene(manager)
{
    const std::pair<const std::string, const double> arr[] = {
        std::pair<const std::string, const double>("./assets/MainMenu/layers/sky.png", 10.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/clouds_1.png", 20.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/clouds_2.png", 30.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/rocks_1.png", 40.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/clouds_3.png", 50.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/clouds_4.png", 60.0),
        std::pair<const std::string, const double>("./assets/MainMenu/layers/rocks_2.png", 70.0)
    };

    this->__objContainer.push_back(std::make_shared<Parralax>(arr, 7, "menuParralax", Type::Vector<2>(0.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/MainMenu/title.png", "tile", GameObject::ObjectType::DECOR, Type::Vector<3>(550.0f, -40.0f, 0.0f)));
    
    const std::string text = "Press any key to start...";
    
    this->__objContainer.push_back(std::make_shared<FlashingText>(text, Type::Color(255, 255, 255, 255), 75, 200, "instruction", GameObject::ObjectType::DECOR, Type::Vector<2>(500.0f, 800.0f)));
}

void Bomberman::Menu::MainMenu::update(const double &elapsed)
{
    if (RayLib::Window::getInstance().getInputKeyboard().getKeyPressed() > 0
        || RayLib::Window::getInstance().getInputGamepad().getGamepadButtonPressed() > 0) {
        this->__manager.newScene<MainLobby>();
    }
    for (auto const &val : this->__objContainer) {
        val->update(elapsed);
    }
}

void Bomberman::Menu::MainMenu::drawScene()
{
    for (auto const &val : this->__objContainer) {
        val->render();
    }
}
