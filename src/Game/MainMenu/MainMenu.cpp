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

Bomberman::Menu::MainMenu::MainMenu(SceneManager &manager) :
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
    this->__objContainer.push_back(std::make_shared<Image>("./assets/MainMenu/title.png", "tile", GameObject::ObjectType::DECOR, Type::Vector<3>(550.0f, -40.0f, 0.0f)));
    
    const std::string text = "Press any key to start...";
    
    this->__objContainer.push_back(std::make_shared<FlashingText>(text, Type::Color(255, 255, 255, 255), 75, 200, "instruction", GameObject::ObjectType::DECOR, Type::Vector<2>(500.0f, 800.0f)));
    
    RayLib::Window::getInstance().setMasterVolume(this->__config.getValue(UserConfig::ValueType::MASTER_VOL));
    if (this->__config.getValue(UserConfig::VERTICAL_SYNC) == 0) {
        RayLib::Window::getInstance().setRefreshRate(this->__config.getValue(UserConfig::ValueType::FPS));
    } else {
        RayLib::Window::getInstance().setRefreshRate(RayLib::Window::getInstance().getMonitorRefreshRate());
    }
    // TODO: set music volume via config file for each musics created
}

void Bomberman::Menu::MainMenu::update(const double &elapsed)
{
    if (RayLib::Window::getInstance().getInputKeyboard().getKeyPressed() > 0
        || RayLib::Window::getInstance().getInputGamepad().getGamepadButtonPressed() > 0) {
        this->__manager.replaceTop<MainLobby>();
        return;
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
