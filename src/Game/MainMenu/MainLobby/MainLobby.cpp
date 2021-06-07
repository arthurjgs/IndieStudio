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
#include "../../FlashingText/FlashingText.hpp"
#include "../Credits/Credits.hpp"

void Bomberman::Menu::MainLobby::createSavePanel()
{
    this->__objContainer.emplace_back(LOAD_PANEL, std::make_shared<Image>("./assets/MainMenu/Panel2.png", "settingsPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(750.0f, 350.0f, 0.0f), false));
    
    std::shared_ptr<Button> close = std::make_shared<Button>("closeLoad", Type::Vector<3>(1080.0f, 360.0f, 0.0f), "./assets/MainMenu/close.png");
    close->setDisplay(false);

    this->__objContainer.emplace_back(LOAD_PANEL, close);
    this->__buttonsReferer.emplace_back(LOAD_PANEL, close);

    this->__buttonCallback["closeLoad"] = &MainLobby::closeButtonCallback;
}

void Bomberman::Menu::MainLobby::createVideoPanel()
{
    this->__objContainer.emplace_back(VIDEO, std::make_shared<Image>("./assets/MainMenu/Panel2.png", "settingsPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(750.0f, 350.0f, 0.0f), false));
    
    std::shared_ptr<Button> close = std::make_shared<Button>("closeVideo", Type::Vector<3>(1080.0f, 360.0f, 0.0f), "./assets/MainMenu/close.png");
    close->setDisplay(false);

    this->__objContainer.emplace_back(VIDEO, close);
    this->__buttonsReferer.emplace_back(VIDEO, close);

    this->__buttonCallback["closeVideo"] = &MainLobby::closeVideoPanel;
}

void Bomberman::Menu::MainLobby::createGameplayPanel()
{
    this->__objContainer.emplace_back(GAMEPLAY, std::make_shared<Image>("./assets/MainMenu/Panel2.png", "settingsPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(750.0f, 350.0f, 0.0f), false));
    
    std::shared_ptr<Button> close = std::make_shared<Button>("closeGameplay", Type::Vector<3>(1080.0f, 360.0f, 0.0f), "./assets/MainMenu/close.png");
    close->setDisplay(false);

    this->__objContainer.emplace_back(GAMEPLAY, close);
    this->__buttonsReferer.emplace_back(GAMEPLAY, close);

    this->__buttonCallback["closeGameplay"] = &MainLobby::closeGameplayPanel;
}

void Bomberman::Menu::MainLobby::createAudioPanel()
{
    this->__objContainer.emplace_back(AUDIO, std::make_shared<Image>("./assets/MainMenu/Panel2.png", "audioPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(750.0f, 350.0f, 0.0f), false));
    this->__objContainer.emplace_back(AUDIO, std::make_shared<FlashingText>("Master volume", Type::Color(255, 255, 255, 255), 35, 0.0, "masterVolumeTxt", GameObject::ObjectType::DECOR, Type::Vector<2>(780.0f, 430.0f), false));

    std::shared_ptr<Button> close = std::make_shared<Button>("closeAudio", Type::Vector<3>(1080.0f, 360.0f, 0.0f), "./assets/MainMenu/close.png");
    std::shared_ptr<Button> leftMaster = std::make_shared<Button>("leftMaster", Type::Vector<3>(850.0f, 500.0f, 0.0f), "./assets/MainMenu/leftArrow.png");
    std::shared_ptr<Button> rightMaster = std::make_shared<Button>("rightMaster", Type::Vector<3>(1000.0f, 500.0f, 0.0f), "./assets/MainMenu/rightArrow.png");
    close->setDisplay(false);
    leftMaster->setDisplay(false);
    rightMaster->setDisplay(false);

    this->__objContainer.emplace_back(AUDIO, close);
    this->__buttonsReferer.emplace_back(AUDIO, close);
    this->__objContainer.emplace_back(AUDIO, leftMaster);
    this->__buttonsReferer.emplace_back(AUDIO, leftMaster);
    this->__objContainer.emplace_back(AUDIO, rightMaster);
    this->__buttonsReferer.emplace_back(AUDIO, rightMaster);

    this->__buttonCallback["closeAudio"] = &MainLobby::closeAudioCallback;
}

void Bomberman::Menu::MainLobby::createHelpPanel()
{
    this->__objContainer.emplace_back(HELP, std::make_shared<Image>("./assets/MainMenu/PNG/Window04.png", "MainPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(520.0f, 400.0f, 0.0f), false));   


    std::shared_ptr<Button> close = std::make_shared<Button>("closeHelp", Type::Vector<3>(1300.0f, 460.0f, 0.0f), "./assets/MainMenu/close.png");
    close->setDisplay(false);

    this->__objContainer.emplace_back(HELP, close);
    this->__buttonsReferer.emplace_back(HELP, close);

    this->__buttonCallback["closeHelp"] = &MainLobby::closeHelpCallback;
}

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

    this->__objContainer.emplace_back(MAIN, std::make_shared<Parralax>(arr, 6, "menuParralax", Type::Vector<2>(0.0f, 0.0f)));
    this->__objContainer.emplace_back(MAIN_PANEL, std::make_shared<Image>("./assets/MainMenu/PNG/Window04.png", "MainPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(520.0f, 400.0f, 0.0f)));
    this->__objContainer.emplace_back(MAIN, std::make_shared<Image>("./assets/MainMenu/lobby.png", "title", GameObject::ObjectType::DECOR, Type::Vector<3>(650.0f, 40.0f, 0.0f)));
    
    this->__objContainer.emplace_back(OPTION_PANEL, std::make_shared<Image>("./assets/MainMenu/Panel1.png", "settingsPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(65.0f, 85.0f, 0.0f), false));
    
    // button
    std::shared_ptr<Button> playButton = std::make_shared<Button>("playButton", Type::Vector<3>(775.0f, 500.0f, 0.0f), "./assets/MainMenu/button_sheet.png", "PLAY", 60);
    std::shared_ptr<Button> loadButton = std::make_shared<Button>("loadButton", Type::Vector<3>(775.0f, 650.0f, 0.0f), "./assets/MainMenu/button_sheet.png", "LOAD", 60);
    std::shared_ptr<Button> quitButton = std::make_shared<Button>("quitButton", Type::Vector<3>(775.0f, 800.0f, 0.0f), "./assets/MainMenu/button_sheet.png", "QUIT", 60);
    std::shared_ptr<Button> settingsButton = std::make_shared<Button>("settingsButton", Type::Vector<3>(40.0f, 57.0f, 0.0f), "./assets/MainMenu/settings_button.png");

    this->__objContainer.emplace_back(MAIN_PANEL, playButton);
    this->__buttonsReferer.emplace_back(MAIN_PANEL, playButton);
    this->__objContainer.emplace_back(MAIN_PANEL, loadButton);
    this->__buttonsReferer.emplace_back(MAIN_PANEL, loadButton);
    this->__objContainer.emplace_back(MAIN_PANEL, quitButton);
    this->__buttonsReferer.emplace_back(MAIN_PANEL, quitButton);
    this->__objContainer.emplace_back(MAIN, settingsButton);
    this->__buttonsReferer.emplace_back(MAIN, settingsButton);

    std::shared_ptr<Button> helpButton = std::make_shared<Button>("helpButton", Type::Vector<3>(80.0f, 200.0f, 0.0f), "./assets/MainMenu/button_sheet_2.png", "Help", 50);
    std::shared_ptr<Button> audioButton = std::make_shared<Button>("audioButton", Type::Vector<3>(80.0f, 300.0f, 0.0f), "./assets/MainMenu/button_sheet_2.png", "Audio", 50);
    std::shared_ptr<Button> videoButton = std::make_shared<Button>("videoButton", Type::Vector<3>(80.0f, 400.0f, 0.0f), "./assets/MainMenu/button_sheet_2.png", "Video", 50);
    std::shared_ptr<Button> gameplayButton = std::make_shared<Button>("gameplayButton", Type::Vector<3>(80.0f, 500.0f, 0.0f), "./assets/MainMenu/button_sheet_2.png", "Gameplay", 50);
    std::shared_ptr<Button> creditsButton = std::make_shared<Button>("creditsButton", Type::Vector<3>(80.0f, 600.0f, 0.0f), "./assets/MainMenu/button_sheet_2.png", "Credits", 50);
    helpButton->setDisplay(false);
    audioButton->setDisplay(false);
    videoButton->setDisplay(false);
    gameplayButton->setDisplay(false);
    creditsButton->setDisplay(false);

    this->__objContainer.emplace_back(OPTION_PANEL, helpButton);
    this->__buttonsReferer.emplace_back(OPTION_PANEL, helpButton);
    this->__objContainer.emplace_back(OPTION_PANEL, audioButton);
    this->__buttonsReferer.emplace_back(OPTION_PANEL, audioButton);
    this->__objContainer.emplace_back(OPTION_PANEL, videoButton);
    this->__buttonsReferer.emplace_back(OPTION_PANEL, videoButton);
    this->__objContainer.emplace_back(OPTION_PANEL, gameplayButton);
    this->__buttonsReferer.emplace_back(OPTION_PANEL, gameplayButton);
    this->__objContainer.emplace_back(OPTION_PANEL, creditsButton);
    this->__buttonsReferer.emplace_back(OPTION_PANEL, creditsButton);

    this->createSavePanel();
    this->createAudioPanel();
    this->createHelpPanel();
    this->createVideoPanel();
    this->createGameplayPanel();

    this->__buttonCallback["playButton"] = &MainLobby::playButtonCallback;
    this->__buttonCallback["loadButton"] = &MainLobby::loadButtonCallback;
    this->__buttonCallback["quitButton"] = &MainLobby::quitButtonCallback;
    this->__buttonCallback["settingsButton"] = &MainLobby::settingsButtonCallback;

    this->__buttonCallback["helpButton"] = &MainLobby::helpButtonCallback;
    this->__buttonCallback["audioButton"] = &MainLobby::audioButtonCallback;
    this->__buttonCallback["videoButton"] = &MainLobby::videoButtonCallback;
    this->__buttonCallback["gameplayButton"] = &MainLobby::gameplayButtonCallback;
    this->__buttonCallback["creditsButton"] = &MainLobby::creditsButtonCallback;

    this->__settings = false;
    this->__save = false;
    this->__audio = false;
    this->__help = false;
    this->__video = false;
    this->__gameplay = false;
}

void Bomberman::Menu::MainLobby::closeHelpCallback()
{
    this->__help = false;
    for (auto const &val : this->__objContainer) {
        if (val.first == HELP) {
            val.second->setDisplay(this->__help);
        }
        if (val.first == MAIN_PANEL) {
            val.second->setDisplay(!this->__help);
        }
    }
}

void Bomberman::Menu::MainLobby::closeAudioCallback()
{
    this->__audio = false;
    for (auto const &val : this->__objContainer) {
        if (val.first == AUDIO) {
            val.second->setDisplay(this->__audio);
        }
        if (val.first == MAIN_PANEL) {
            val.second->setDisplay(!this->__audio);
        }
    }
}

void Bomberman::Menu::MainLobby::closeButtonCallback()
{
    this->__save = false;
    for (auto const &val : this->__objContainer) {
        if (val.first == LOAD_PANEL) {
            val.second->setDisplay(this->__save);
        }
        if (val.first == MAIN_PANEL) {
            val.second->setDisplay(!this->__save);
        }
    }
}

void Bomberman::Menu::MainLobby::closeGameplayPanel()
{
    this->__gameplay = false;
    for (auto const &val : this->__objContainer) {
        if (val.first == GAMEPLAY) {
            val.second->setDisplay(this->__gameplay);
        }
        if (val.first == MAIN_PANEL) {
            val.second->setDisplay(!this->__gameplay);
        }
    }
}

void Bomberman::Menu::MainLobby::closeVideoPanel()
{
    this->__video = false;
    for (auto const &val : this->__objContainer) {
        if (val.first == VIDEO) {
            val.second->setDisplay(this->__video);
        }
        if (val.first == MAIN_PANEL) {
            val.second->setDisplay(!this->__video);
        }
    }
}

void Bomberman::Menu::MainLobby::playButtonCallback()
{
    std::cout << "play click" << std::endl;
    //TODO: LOAD PLAYER SELECTION
}

void Bomberman::Menu::MainLobby::loadButtonCallback()
{
    std::cout << "load click" << std::endl;
    this->__settings = false;
    this->__audio = false;
    this->__help = false;
    this->__gameplay = false;
    this->__video = false;
    if (this->__save == false) {
        this->__save = true;
    } else {
        this->__save = false;
    }
    for (auto const &val : this->__objContainer) {
        if (val.first == LOAD_PANEL) {
            val.second->setDisplay(this->__save);
        }
        if (val.first != MAIN && val.first != LOAD_PANEL) {
            val.second->setDisplay(!this->__save);
        }
    }
}

void Bomberman::Menu::MainLobby::quitButtonCallback()
{
    std::cout << "quit click" << std::endl;
    throw QuitGame();
}

void Bomberman::Menu::MainLobby::settingsButtonCallback()
{
    std::cout << "settings clicked" << std::endl;
    if (this->__settings == false) {
        this->__settings = true;
    } else {
        this->__settings = false;
    }
    for (auto const &val : this->__objContainer) {
        if (val.first == OPTION_PANEL) {
            val.second->setDisplay(this->__settings);
        }
    }
}

void Bomberman::Menu::MainLobby::helpButtonCallback()
{
    this->__settings = false;
    this->__save = false;
    this->__audio = false;
    this->__gameplay = false;
    this->__video = false;
    if (this->__help == false) {
        this->__help = true;
    } else {
        this->__help = false;
    }
    std::cout << this->__help << std::endl;
    for (auto const &val : this->__objContainer) {
        if (val.first == HELP) {
            val.second->setDisplay(this->__help);
        }
        if (val.first != MAIN && val.first != HELP) {
            val.second->setDisplay(!this->__help);
        }
    }
}

void Bomberman::Menu::MainLobby::audioButtonCallback()
{
    this->__settings = false;
    this->__save = false;
    this->__help = false;
    this->__gameplay = false;
    this->__video = false;
    if (this->__audio == false) {
        this->__audio = true;
    } else {
        this->__audio = false;
    }
    for (auto const &val : this->__objContainer) {
        if (val.first == AUDIO) {
            val.second->setDisplay(this->__audio);
        }
        if (val.first != MAIN && val.first != AUDIO) {
            val.second->setDisplay(!this->__audio);
        }
    }
}

void Bomberman::Menu::MainLobby::videoButtonCallback()
{
    this->__settings = false;
    this->__save = false;
    this->__help = false;
    this->__audio = false;
    this->__gameplay = false;
    if (this->__video == false) {
        this->__video = true;
    } else {
        this->__video = false;
    }
    for (auto const &val : this->__objContainer) {
        if (val.first == VIDEO) {
            val.second->setDisplay(this->__video);
        }
        if (val.first != MAIN && val.first != VIDEO) {
            val.second->setDisplay(!this->__video);
        }
    }
}

void Bomberman::Menu::MainLobby::gameplayButtonCallback()
{
    this->__settings = false;
    this->__save = false;
    this->__help = false;
    this->__video = false;
    this->__audio = false;
    if (this->__gameplay == false) {
        this->__gameplay = true;
    } else {
        this->__gameplay = false;
    }
    for (auto const &val : this->__objContainer) {
        if (val.first == GAMEPLAY) {
            val.second->setDisplay(this->__gameplay);
        }
        if (val.first != MAIN && val.first != GAMEPLAY) {
            val.second->setDisplay(!this->__gameplay);
        }
    }
}

void Bomberman::Menu::MainLobby::creditsButtonCallback()
{
    this->__manager.newScene<Credits>();    
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
        val.second->update(elapsed);
    }
}

void Bomberman::Menu::MainLobby::drawScene()
{
    for (auto const &val : this->__objContainer) {
        if (val.second->getDisplay()) {
            val.second->render();
        }
    }
}