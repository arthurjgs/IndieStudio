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
#include "../../QuitGame/QuitGame.hpp"

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
    this->__objContainer.push_back(std::make_shared<Image>("./assets/MainMenu/PNG/Window04.png", "MainPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(520.0f, 400.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/MainMenu/lobby.png", "title", GameObject::ObjectType::DECOR, Type::Vector<3>(675.0f, 40.0f, 0.0f)));
    
    // button
    std::shared_ptr<Button> playButton = std::make_shared<Button>("playButton", Type::Vector<3>(775.0f, 500.0f, 0.0f), "./assets/MainMenu/button_sheet.png", "PLAY", 60);
    std::shared_ptr<Button> loadButton = std::make_shared<Button>("loadButton", Type::Vector<3>(775.0f, 650.0f, 0.0f), "./assets/MainMenu/button_sheet.png", "LOAD", 60);
    std::shared_ptr<Button> quitButton = std::make_shared<Button>("quitButton", Type::Vector<3>(775.0f, 800.0f, 0.0f), "./assets/MainMenu/button_sheet.png", "QUIT", 60);
    std::shared_ptr<Button> settingsButton = std::make_shared<Button>("settingsButton", Type::Vector<3>(75.0f, 75.0f, 0.0f), "./assets/MainMenu/settings_button.png");

    this->__objContainer.push_back(playButton);
    this->__buttonsReferer.emplace_back(MAIN, playButton);
    this->__objContainer.push_back(loadButton);
    this->__buttonsReferer.emplace_back(MAIN, loadButton);
    this->__objContainer.push_back(quitButton);
    this->__buttonsReferer.emplace_back(MAIN, quitButton);
    this->__objContainer.push_back(settingsButton);
    this->__buttonsReferer.emplace_back(MAIN, settingsButton);

    this->__buttonCallback["playButton"] = &MainLobby::playButtonCallback;
    this->__buttonCallback["loadButton"] = &MainLobby::loadButtonCallback;
    this->__buttonCallback["quitButton"] = &MainLobby::quitButtonCallback;
    this->__buttonCallback["settingsButton"] = &MainLobby::loadButtonCallback;
}

void Bomberman::Menu::MainLobby::playButtonCallback()
{
    std::cout << "play click" << std::endl;
    this->__manager.newScene<SelectionMenu>();
}

void Bomberman::Menu::MainLobby::loadButtonCallback()
{
    std::cout << "load click" << std::endl;
    //TODO: LOAD SAVE
}

void Bomberman::Menu::MainLobby::quitButtonCallback()
{
    std::cout << "quit click" << std::endl;
    throw QuitGame();
}

void Bomberman::Menu::MainLobby::settingsButtonCallback()
{
    std::cout << "settings clicked" << std::endl;
    // TODO: Manage settings
}

void Bomberman::Menu::MainLobby::update(const double &elapsed)
{
    for (auto const &val : this->__buttonsReferer) {
        if (val.second.lock()->isClick() == true && val.second.lock()->getDisplay()) {
            if (this->__buttonCallback.count(val.second.lock()->getName()) > 0) {
                this->__buttonCallback[val.second.lock()->getName()](*this);
            }
        }
    }
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