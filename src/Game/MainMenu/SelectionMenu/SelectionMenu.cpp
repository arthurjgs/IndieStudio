/**
 * @file SelectionMenu.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "SelectionMenu.hpp"
#include "../../../RayLib/Window.hpp"

Bomberman::Menu::SelectionMenu::SelectionMenu(SceneManager &manager) : Scene(manager)
{
    _players = 1;
    _firstPlayerGamepad = false;
    const std::string text = "MULTIPLAYER BATTLE";
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/yellow.png", "wall", GameObject::ObjectType::DECOR, Type::Vector<3>(0.0f, 0.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/bande.png", "bande", GameObject::ObjectType::DECOR, Type::Vector<3>(0.0f, 100.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/house.png", "house", GameObject::ObjectType::DECOR, Type::Vector<3>(100.0f, 110.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<FlashingText>(text, Type::Color(255, 255, 255, 255), 80, 0, "title", GameObject::ObjectType::DECOR, Type::Vector<2>(340.0f, 160.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/grey_square.png", "perso1", GameObject::ObjectType::DECOR, Type::Vector<3>(85.0f, 340.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/grey_square.png", "perso2", GameObject::ObjectType::DECOR, Type::Vector<3>(535.0f, 340.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/grey_square.png", "perso3", GameObject::ObjectType::DECOR, Type::Vector<3>(985.0f, 340.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/grey_square.png", "perso4", GameObject::ObjectType::DECOR, Type::Vector<3>(1435.0f, 340.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/bande_bot.png", "bande_bot", GameObject::ObjectType::DECOR, Type::Vector<3>(0.0f, 930.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<FlashingText>("Please select your charactere", Type::Color(255, 255, 255, 255), 50, 150, "select", GameObject::ObjectType::DECOR, Type::Vector<2>(580.0f, 970.0f)));
}

void Bomberman::Menu::SelectionMenu::update(const double &elapsed)
{
    for (auto const &val : this->__objContainer) {
        val->update(elapsed);
    }
    if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(0))
        _players = 2;
    if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(1))
        _players = 3;
    if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(2))
        _players = 4;
    if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(3))
        _players = 4;
}

void Bomberman::Menu::SelectionMenu::drawScene()
{
    for (auto const &val : this->__objContainer) {
        val->render();
    }
}
