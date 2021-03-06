/**
 * @file End.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "End.hpp"
#include "../QuitGame/QuitGame.hpp"
#include "../MainMenu/MainLobby/MainLobby.hpp"
#include "../Config.hpp"

void Bomberman::End::quit()
{
    throw QuitGame();
}

void Bomberman::End::menu()
{
    RayLib::Window::loadingScreen();
    this->__manager.clearStack<Menu::MainLobby>();
}

Bomberman::End::End(SceneManager &manager) :
Scene(manager),
_sound(Bomberman::Config::ExecutablePath + "./assets/sound_effects/applause.wav")
{
    this->_quitting = false;
    this->__objContainer.emplace_back(std::make_shared<Image>(Bomberman::Config::ExecutablePath + "./assets/MainMenu/end.png", "back", GameObject::ObjectType::DECOR, Type::Vector<3>(0.0f, 0.0f, 0.0f)));

    std::shared_ptr<Button> quitGame = std::make_shared<Button>("quit", Type::Vector<3>(500.0f, 800.0f, 0.0f), Bomberman::Config::ExecutablePath + "./assets/MainMenu/button_sheet.png", "QUIT GAME", 40);
    std::shared_ptr<Button> mainMenu = std::make_shared<Button>("menu", Type::Vector<3>(1100.0f, 800.0f, 0.0f), Bomberman::Config::ExecutablePath + "./assets/MainMenu/button_sheet.png", "MAIN MENU", 40);
    std::shared_ptr<Music> theme = std::make_unique<Music>("theme", Bomberman::Config::ExecutablePath + "./assets/sounds/victory.mp3", this->__config.getValue(UserConfig::ValueType::MUSIC_VOL));
    this->_sound.PlayRaySound();

    this->__objContainer.emplace_back(theme);

    this->__objContainer.emplace_back(quitGame);
    this->_buttonRef.emplace_back(quitGame);
    this->__objContainer.emplace_back(mainMenu);
    this->_buttonRef.emplace_back(mainMenu);
    this->_buttonCallbacks["quit"] = &Bomberman::End::quit;
    this->_buttonCallbacks["menu"] = &Bomberman::End::menu;
}

void Bomberman::End::update(const double &elapsed)
{   
    for (auto const &val : this->_buttonRef) {
        if (val.lock()->getDisplay() && val.lock()->isClick()) {
            if (this->_buttonCallbacks.count(val.lock()->getName()) > 0) {
                this->_buttonCallbacks[val.lock()->getName()](*this);
                return;
            }
        }
    }
    for (auto const &val : this->__objContainer) {
        val->update(elapsed);
    }
}

void Bomberman::End::drawScene()
{
    for (auto const &val : this->__objContainer) {
        if (val->getDisplay()) {
            val->render();
        }
    }
}
