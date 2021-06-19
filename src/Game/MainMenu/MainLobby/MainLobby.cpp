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
#include "../Credits/Credits.hpp"
#include "../../Music/Music.hpp"
#include "../../Save/GameSceneData/GameSceneData.hpp"
#include "../../GameScene/GameScene.hpp"

void Bomberman::Menu::MainLobby::backButtonCallback()
{
    int old = 0;

    if (this->__saveIndex <= 3) {
        return;
    }
    for (int i = this->__saveIndex - 1; (size_t) i < this->__saveButtons.size(); i++) {
        this->__saveButtons[i].lock()->setDisplay(false);
    }
    old = this->__saveIndex;
    this->__saveIndex -= 3;
    if (this->__saveIndex < 0) {
        this->__saveIndex = 0;
    }
    for (int i = this->__saveIndex - 1; i < old - 1; i++) {
        this->__saveButtons[i].lock()->setDisplay(true);
    }
    this->__saveIndex = old - 1;
}

void Bomberman::Menu::MainLobby::forwardButtonCallback()
{
    int old = 0;

    if ((size_t)this->__saveIndex >= this->__saveButtons.size()) {
        return;
    }
    for (int i = 0; i < this->__saveIndex; i++) {
        this->__saveButtons[i].lock()->setDisplay(false);
    }
    old = this->__saveIndex;
    this->__saveIndex += 3;
    if ((size_t) this->__saveIndex + 3 > this->__saveButtons.size()) {
        this->__saveIndex = this->__saveButtons.size();
    }
    for (int i = old; i < this->__saveIndex; i++) {
        this->__saveButtons[i].lock()->setDisplay(true);
    } 
}

void Bomberman::Menu::MainLobby::createSavePanel()
{
    this->__objContainer.emplace_back(LOAD_PANEL, std::make_shared<Image>("./assets/MainMenu/Panel2.png", "settingsPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(750.0f, 350.0f, 0.0f), false));
    
    std::shared_ptr<Button> close = std::make_shared<Button>("closeLoad", Type::Vector<3>(1080.0f, 360.0f, 0.0f), "./assets/MainMenu/close.png");
    close->setDisplay(false);

    std::shared_ptr<Button> back = std::make_shared<Button>("back", Type::Vector<3>(775.0f, 900.0f, 0.0f), "./assets/MainMenu/leftArrow.png");
    std::shared_ptr<Button> forward = std::make_shared<Button>("forward", Type::Vector<3>(1075.0f, 900.0f, 0.0f), "./assets/MainMenu/rightArrow.png");
    back->setDisplay(false);
    forward->setDisplay(false);

    this->__objContainer.emplace_back(LOAD_PANEL, close);
    this->__buttonsReferer.emplace_back(LOAD_PANEL, close);

    this->__objContainer.emplace_back(LOAD_PANEL, back);
    this->__buttonsReferer.emplace_back(LOAD_PANEL, back);

    this->__objContainer.emplace_back(LOAD_PANEL, forward);
    this->__buttonsReferer.emplace_back(LOAD_PANEL, forward);

    this->__buttonCallback["closeLoad"] = &MainLobby::closeButtonCallback;
    this->__buttonCallback["back"] = &MainLobby::backButtonCallback;
    this->__buttonCallback["forward"] = &MainLobby::forwardButtonCallback;
    this->__controllerMapLoad[0] = "closeLoad";
}

void Bomberman::Menu::MainLobby::createVideoPanel()
{
    this->__objContainer.emplace_back(VIDEO, std::make_shared<Image>("./assets/MainMenu/Panel2.png", "settingsPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(750.0f, 350.0f, 0.0f), false));
    this->__objContainer.emplace_back(VIDEO, std::make_shared<FlashingText>("Refresh Rate", Type::Color(255, 255, 255, 255), 35, 0.0, "refreshRateTxt", GameObject::ObjectType::DECOR, Type::Vector<2>(780.0f, 430.0f), false));
    this->__objContainer.emplace_back(VIDEO, std::make_shared<FlashingText>("Vertical Sync", Type::Color(255, 255, 255, 255), 35, 0.0, "VerticalSyncTxt", GameObject::ObjectType::DECOR, Type::Vector<2>(780.0f, 730.0f), false));

    std::shared_ptr<Button> close = std::make_shared<Button>("closeVideo", Type::Vector<3>(1080.0f, 360.0f, 0.0f), "./assets/MainMenu/close.png");
    std::shared_ptr<Button> confirm = std::make_shared<Button>("confirmVideo", Type::Vector<3>(1080.0f, 930.0f, 0.0f), "./assets/MainMenu/confirm.png");
    std::shared_ptr<Button> leftRefresh = std::make_shared<Button>("leftRefresh", Type::Vector<3>(800.0f, 500.0f, 0.0f), "./assets/MainMenu/leftArrow.png");
    std::shared_ptr<Button> rightRefresh = std::make_shared<Button>("rightRefresh", Type::Vector<3>(950.0f, 500.0f, 0.0f), "./assets/MainMenu/rightArrow.png");
    std::shared_ptr<Button> checkedSync = std::make_shared<Button>("checkedSync", Type::Vector<3>(1050.0f, 722.0f, 0.0f), "./assets/MainMenu/checked_box.png");
    std::shared_ptr<Button> uncheckedSync = std::make_shared<Button>("uncheckedSync", Type::Vector<3>(1050.0f, 722.0f, 0.0f), "./assets/MainMenu/unchecked_box.png");
    close->setDisplay(false);
    confirm->setDisplay(false);
    leftRefresh->setDisplay(false);
    rightRefresh->setDisplay(false);
    checkedSync->setDisplay(false);
    uncheckedSync->setDisplay(false);

    this->__objContainer.emplace_back(VIDEO, close);
    this->__buttonsReferer.emplace_back(VIDEO, close);
    this->__objContainer.emplace_back(VIDEO, confirm);
    this->__buttonsReferer.emplace_back(VIDEO, confirm);
    this->__objContainer.emplace_back(VIDEO, leftRefresh);
    this->__buttonsReferer.emplace_back(VIDEO, leftRefresh);
    this->__objContainer.emplace_back(VIDEO, rightRefresh);
    this->__buttonsReferer.emplace_back(VIDEO, rightRefresh);
    this->__objContainer.emplace_back(VIDEO, checkedSync);
    this->__buttonsReferer.emplace_back(VIDEO, checkedSync);
    this->__objContainer.emplace_back(VIDEO, uncheckedSync);
    this->__buttonsReferer.emplace_back(VIDEO, uncheckedSync);

    this->__buttonCallback["closeVideo"] = &MainLobby::closeVideoPanel;
    this->__buttonCallback["confirmVideo"] = &MainLobby::confirmVideo;
    this->__buttonCallback["leftRefresh"] = &MainLobby::leftRefreshVideo;
    this->__buttonCallback["rightRefresh"] = &MainLobby::rightRefreshVideo;
    this->__buttonCallback["checkedSync"] = &MainLobby::checkedSyncVideo;
    this->__buttonCallback["uncheckedSync"] = &MainLobby::uncheckedSyncVideo;

    std::string text;
    if (this->__configHandler.getValue(UserConfig::VERTICAL_SYNC) == 0) {
        text = std::to_string(this->__configHandler.getValue(UserConfig::ValueType::FPS));
    } else {
        text = std::to_string(RayLib::Window::getInstance().getMonitorRefreshRate());
    }
    std::shared_ptr<FlashingText> refreshRate = std::make_shared<FlashingText>(text, Type::Color(255, 255, 255, 255), 35, 0.0, "refreshRateNb", GameObject::ObjectType::DECOR, Type::Vector<2>(875.0f, 525.0f), false);

    this->__objContainer.emplace_back(VIDEO, refreshRate);
    this->__dynamicTextReferer.emplace_back(VIDEO, refreshRate);

    this->__controllerMapVideo[0] = "closeVideo";
    this->__controllerMapVideo[1] = "confirmVideo";
    this->__controllerMapVideo[2] = "leftRefresh";
    this->__controllerMapVideo[3] = "rightRefresh";
    this->__controllerMapVideo[4] = "checkedSync";
    this->__controllerMapAudio[5] = "uncheckedSync";
}

void Bomberman::Menu::MainLobby::createGameplayPanel()
{
    this->__objContainer.emplace_back(GAMEPLAY, std::make_shared<Image>("./assets/MainMenu/Panel2.png", "settingsPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(750.0f, 350.0f, 0.0f), false));
    
    std::shared_ptr<Button> close = std::make_shared<Button>("closeGameplay", Type::Vector<3>(1080.0f, 360.0f, 0.0f), "./assets/MainMenu/close.png");
    close->setDisplay(false);

    this->__objContainer.emplace_back(GAMEPLAY, close);
    this->__buttonsReferer.emplace_back(GAMEPLAY, close);

    this->__buttonCallback["closeGameplay"] = &MainLobby::closeGameplayPanel;

    this->__controllerMapGameplay[0] = "closeGameplay";
}

void Bomberman::Menu::MainLobby::createAudioPanel()
{
    this->__objContainer.emplace_back(AUDIO, std::make_shared<Image>("./assets/MainMenu/Panel2.png", "audioPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(750.0f, 350.0f, 0.0f), false));
    this->__objContainer.emplace_back(AUDIO, std::make_shared<FlashingText>("Master volume", Type::Color(255, 255, 255, 255), 35, 0.0, "masterVolumeTxt", GameObject::ObjectType::DECOR, Type::Vector<2>(780.0f, 430.0f), false));
    this->__objContainer.emplace_back(AUDIO, std::make_shared<FlashingText>("Music volume", Type::Color(255, 255, 255, 255), 35, 0.0, "musicVolumeTxt", GameObject::ObjectType::DECOR, Type::Vector<2>(780.0f, 630.0f), false));

    std::shared_ptr<Button> close = std::make_shared<Button>("closeAudio", Type::Vector<3>(1080.0f, 360.0f, 0.0f), "./assets/MainMenu/close.png");
    std::shared_ptr<Button> confirm = std::make_shared<Button>("confirmAudio", Type::Vector<3>(1080.0f, 930.0f, 0.0f), "./assets/MainMenu/confirm.png");
    std::shared_ptr<Button> leftMaster = std::make_shared<Button>("leftMaster", Type::Vector<3>(800.0f, 500.0f, 0.0f), "./assets/MainMenu/leftArrow.png");
    std::shared_ptr<Button> rightMaster = std::make_shared<Button>("rightMaster", Type::Vector<3>(950.0f, 500.0f, 0.0f), "./assets/MainMenu/rightArrow.png");
    std::shared_ptr<Button> leftMusic = std::make_shared<Button>("leftMusic", Type::Vector<3>(800.0f, 700.0f, 0.0f), "./assets/MainMenu/leftArrow.png");
    std::shared_ptr<Button> rightMusic = std::make_shared<Button>("rightMusic", Type::Vector<3>(950.0f, 700.0f, 0.0f), "./assets/MainMenu/rightArrow.png");
    close->setDisplay(false);
    leftMaster->setDisplay(false);
    rightMaster->setDisplay(false);
    leftMusic->setDisplay(false);
    rightMusic->setDisplay(false);
    confirm->setDisplay(false);

    this->__objContainer.emplace_back(AUDIO, close);
    this->__buttonsReferer.emplace_back(AUDIO, close);
    this->__objContainer.emplace_back(AUDIO, leftMaster);
    this->__buttonsReferer.emplace_back(AUDIO, leftMaster);
    this->__objContainer.emplace_back(AUDIO, rightMaster);
    this->__buttonsReferer.emplace_back(AUDIO, rightMaster);
    this->__objContainer.emplace_back(AUDIO, leftMusic);
    this->__buttonsReferer.emplace_back(AUDIO, leftMusic);
    this->__objContainer.emplace_back(AUDIO, rightMusic);
    this->__buttonsReferer.emplace_back(AUDIO, rightMusic);
    this->__objContainer.emplace_back(AUDIO, confirm);
    this->__buttonsReferer.emplace_back(AUDIO, confirm);

    this->__buttonCallback["closeAudio"] = &MainLobby::closeAudioCallback;
    this->__buttonCallback["confirmAudio"] = &MainLobby::confirmAudioCallback;
    this->__buttonCallback["leftMaster"] = &MainLobby::leftMasterAudioCallback;
    this->__buttonCallback["rightMaster"] = &MainLobby::rightMasterAudioCallback;
    this->__buttonCallback["leftMusic"] = &MainLobby::leftMusicAudioCallback;
    this->__buttonCallback["rightMusic"] = &MainLobby::rightMusicAudioCallback;

    this->__controllerMapAudio[0] = "closeAudio";
    this->__controllerMapAudio[1] = "leftMaster";
    this->__controllerMapAudio[2] = "rightMaster";
    this->__controllerMapAudio[3] = "leftMusic";
    this->__controllerMapAudio[4] = "rightMusic";
    this->__controllerMapAudio[5] = "confirmAudio";

    std::shared_ptr<FlashingText> masterVolumeNb = std::make_shared<FlashingText>(std::to_string(this->__configHandler.getValue(UserConfig::ValueType::MASTER_VOL)), Type::Color(255, 255, 255, 255), 35, 0.0, "masterVolumeNb", GameObject::ObjectType::DECOR, Type::Vector<2>(875.0f, 525.0f), false);
    std::shared_ptr<FlashingText> masterMusicNb = std::make_shared<FlashingText>(std::to_string(this->__configHandler.getValue(UserConfig::ValueType::MUSIC_VOL)), Type::Color(255, 255, 255, 255), 35, 0.0, "musicVolumeNb", GameObject::ObjectType::DECOR, Type::Vector<2>(875.0f, 725.0f), false);

    this->__objContainer.emplace_back(AUDIO, masterVolumeNb);
    this->__dynamicTextReferer.emplace_back(AUDIO, masterVolumeNb);
    this->__objContainer.emplace_back(AUDIO, masterMusicNb);
    this->__dynamicTextReferer.emplace_back(AUDIO, masterMusicNb);
}

void Bomberman::Menu::MainLobby::createHelpPanel()
{
    this->__objContainer.emplace_back(HELP, std::make_shared<Image>("./assets/MainMenu/PNG/Window04.png", "MainPanel", GameObject::ObjectType::DECOR, Type::Vector<3>(520.0f, 400.0f, 0.0f), false));   


    std::shared_ptr<Button> close = std::make_shared<Button>("closeHelp", Type::Vector<3>(1300.0f, 460.0f, 0.0f), "./assets/MainMenu/close.png");
    close->setDisplay(false);

    this->__objContainer.emplace_back(HELP, close);
    this->__buttonsReferer.emplace_back(HELP, close);

    this->__buttonCallback["closeHelp"] = &MainLobby::closeHelpCallback;

    this->__controllerMapHelp[0] = "closeHelp";
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
    this->__objContainer.emplace_back(MAIN, std::make_shared<Music>("MainMusic", "./assets/sounds/lobbymusic.mp3", 0.5f));
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

    this->__currentBtnMain = 0;
    this->__controllerMapMain[0] = "playButton";
    this->__controllerMapMain[1] = "loadButton";
    this->__controllerMapMain[2] = "quitButton";

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

    this->__currentBtnSettings = 0;
    this->__controllerMapSettings[0] = "helpButton";
    this->__controllerMapSettings[1] = "audioButton";
    this->__controllerMapSettings[2] = "videoButton";
    this->__controllerMapSettings[3] = "gameplayButton";
    this->__controllerMapSettings[4] = "creditsButton";

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
    this->__ignore = -1;
    
    this->mainPanelFocus = true;
    this->settingsFocus = false;
    this->controllerActive = false;
    this->helpPanelFocus = false;
    this->audioPanelFocus = false;
    this->videoPanelFocus = false;
    this->gameplayPanelFocus = false;
    this->loadPanelFocus = false;
    this->__currentBtnAudio = 0;
    this->__currentBtnHelp = 0;
    this->__currentBtnGameplay = 0;
    this->__currentBtnVideo = 0;
    this->__currentBtnLoad = 0;
    // TODO: set music volume via config file for each musics created
}

void Bomberman::Menu::MainLobby::confirmVideo()
{
    std::weak_ptr<FlashingText> text = this->findTextByName("refreshRateNb");
    int vsync = 0;
    int fps = std::stoi(text.lock()->getText());
    std::weak_ptr<Button> unchecked = this->findButtonByName("uncheckedSync");

    if (unchecked.lock()->getDisplay()) {
        vsync = 0;
    } else {
        vsync = 1;
    }
    this->__configHandler.setValue(UserConfig::ValueType::FPS, fps);
    this->__configHandler.setValue(UserConfig::ValueType::VERTICAL_SYNC, vsync);
    if (vsync == 1) {
        RayLib::Window::getInstance().setRefreshRate(RayLib::Window::getInstance().getMonitorRefreshRate());
    } else {
        RayLib::Window::getInstance().setRefreshRate(fps);
    }
    this->closeVideoPanel();
}

void Bomberman::Menu::MainLobby::leftRefreshVideo()
{
    std::weak_ptr<FlashingText> text = this->findTextByName("refreshRateNb");
    int value = std::stoi(text.lock()->getText());

    if (value > 1) {
        value--;
        std::string &res = text.lock()->getText();
        res = std::to_string(value);
    }
}

void Bomberman::Menu::MainLobby::rightRefreshVideo()
{
    std::weak_ptr<FlashingText> text = this->findTextByName("refreshRateNb");
    int value = std::stoi(text.lock()->getText());

    if (value < 260) {
        value++;
        std::string &res = text.lock()->getText();
        res = std::to_string(value);
    }
}

void Bomberman::Menu::MainLobby::checkedSyncVideo()
{
    std::weak_ptr<Button> unchecked = this->findButtonByName("uncheckedSync");
    std::weak_ptr<Button> checked = this->findButtonByName("checkedSync");
    std::weak_ptr<FlashingText> text = this->findTextByName("refreshRateNb");
    
    checked.lock()->setDisplay(false);
    unchecked.lock()->setDisplay(true);
    std::string &res = text.lock()->getText();
    res = std::to_string(this->__configHandler.getValue(UserConfig::ValueType::FPS));
    this->__ignore = 0;
}

void Bomberman::Menu::MainLobby::uncheckedSyncVideo()
{
    std::weak_ptr<Button> unchecked = this->findButtonByName("uncheckedSync");
    std::weak_ptr<Button> checked = this->findButtonByName("checkedSync");
    std::weak_ptr<FlashingText> text = this->findTextByName("refreshRateNb");

    if (this->__ignore == 0) {
        this->__ignore = 1;
        return;
    }
    checked.lock()->setDisplay(true);
    unchecked.lock()->setDisplay(false);
    std::string &res = text.lock()->getText();
    res = std::to_string(RayLib::Window::getInstance().getMonitorRefreshRate());
    this->__ignore = 1;
}

std::weak_ptr<Bomberman::GameObject> Bomberman::Menu::MainLobby::findElemByName(const std::string &name)
{
    for (auto const &val : this->__objContainer) {
        if (val.second->getName() == name) {
            return (val.second);
        }
    }
    throw std::runtime_error("Requested name does not exist");
}

std::weak_ptr<Bomberman::FlashingText> Bomberman::Menu::MainLobby::findTextByName(const std::string &name)
{
    for (auto const &val : this->__dynamicTextReferer) {
        if (val.second.lock()->getName() == name) {
            return (val.second);
        }
    }
    throw std::runtime_error("Requested name does not exist");
}

std::weak_ptr<Bomberman::Button> Bomberman::Menu::MainLobby::findButtonByName(const std::string &name)
{
    for (auto const &val : this->__buttonsReferer) {
        if (val.second.lock()->getName() == name) {
            return (val.second);
        }
    }
    throw std::runtime_error("Requested name does not exist: " + name);
}

void Bomberman::Menu::MainLobby::setAudioChanges()
{
    // TODO: Loop threw all music and set volume of each one
    RayLib::Window::getInstance().setMasterVolume(this->__configHandler.getValue(UserConfig::ValueType::MASTER_VOL));
}

void Bomberman::Menu::MainLobby::confirmAudioCallback()
{
    std::weak_ptr<FlashingText> text = this->findTextByName("masterVolumeNb");
    int value = std::stoi(text.lock()->getText());

    this->__configHandler.setValue(UserConfig::ValueType::MASTER_VOL, value);

    text.reset();
    text = this->findTextByName("musicVolumeNb");
    value = std::stoi(text.lock()->getText());

    this->__configHandler.setValue(UserConfig::ValueType::MUSIC_VOL, value);

    this->setAudioChanges();
    this->closeAudioCallback();
}

void Bomberman::Menu::MainLobby::leftMasterAudioCallback()
{
    std::weak_ptr<FlashingText> text = this->findTextByName("masterVolumeNb");
    int value = std::stoi(text.lock()->getText());
    
    if (value > 0) {
        value--;
        std::string &holder = text.lock()->getText();
        holder = std::to_string(value);
    } 
}

void Bomberman::Menu::MainLobby::rightMasterAudioCallback()
{
    std::weak_ptr<FlashingText> text = this->findTextByName("masterVolumeNb");
    int value = std::stoi(text.lock()->getText());
    
    if (value < 100) {
        value++;
        std::string &holder = text.lock()->getText();
        holder = std::to_string(value);
    } 
}

void Bomberman::Menu::MainLobby::leftMusicAudioCallback()
{
    std::weak_ptr<FlashingText> text = this->findTextByName("musicVolumeNb");
    int value = std::stoi(text.lock()->getText());
    
    if (value > 0) {
        value--;
        std::string &holder = text.lock()->getText();
        holder = std::to_string(value);
    } 
}

void Bomberman::Menu::MainLobby::rightMusicAudioCallback()
{
    std::weak_ptr<FlashingText> text = this->findTextByName("musicVolumeNb");
    int value = std::stoi(text.lock()->getText());
    
    if (value < 100) {
        value++;
        std::string &holder = text.lock()->getText();
        holder = std::to_string(value);
    } 
}

void Bomberman::Menu::MainLobby::closeHelpCallback()
{
    this->__help = false;
    this->mainPanelFocus = true;
    for (auto const &val : this->__objContainer) {
        if (val.first == HELP) {
            val.second->setDisplay(this->__help);
        }
        if (val.first == MAIN_PANEL) {
            val.second->setDisplay(!this->__help);
        }
    }
    this->helpPanelFocus = false;
}

void Bomberman::Menu::MainLobby::closeAudioCallback()
{
    this->__audio = false;
    this->mainPanelFocus = true;
    for (auto const &val : this->__objContainer) {
        if (val.first == AUDIO) {
            val.second->setDisplay(this->__audio);
        }
        if (val.first == MAIN_PANEL) {
            val.second->setDisplay(!this->__audio);
        }
    }
    this->audioPanelFocus = false;
}

void Bomberman::Menu::MainLobby::__deleteSaveButtons(const std::vector<std::string> &container)
{
    size_t i = 0;
    bool find = false;

    while (i < this->__objContainer.size()) {
        find = false;
        for (auto const &val : container) {
            if (val == this->__objContainer[i].second->getName()) {
                this->__objContainer[i].second.reset();
                this->__objContainer.erase(this->__objContainer.begin() + i);
                find = true;
            }
        }
        if (find == false) {
            i++;
        }
    }
    this->__saveButtons.clear();
}

void Bomberman::Menu::MainLobby::closeButtonCallback()
{
    this->__save = false;
    std::vector<std::string> saveName;
    for (auto const &val : this->__saveButtons) {
        saveName.push_back(val.lock()->getName());
    }
    this->__deleteSaveButtons(saveName);
    this->loadPanelFocus = false;
    this->mainPanelFocus = true;
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
    this->mainPanelFocus = true;
    for (auto const &val : this->__objContainer) {
        if (val.first == GAMEPLAY) {
            val.second->setDisplay(this->__gameplay);
        }
        if (val.first == MAIN_PANEL) {
            val.second->setDisplay(!this->__gameplay);
        }
    }
    this->gameplayPanelFocus = false;
}

void Bomberman::Menu::MainLobby::closeVideoPanel()
{
    this->__video = false;
    this->mainPanelFocus = true;
    for (auto const &val : this->__objContainer) {
        if (val.first == VIDEO) {
            val.second->setDisplay(this->__video);
        }
        if (val.first == MAIN_PANEL) {
            val.second->setDisplay(!this->__video);
        }
    }
    this->videoPanelFocus = false;
}

void Bomberman::Menu::MainLobby::playButtonCallback()
{
    std::cout << "play click" << std::endl;
    this->__manager.newScene<SelectionMenu>();
}

std::string Bomberman::Menu::MainLobby::getFileName(const std::string &path)
{
    std::string res = "";

    res = path.substr(path.find_last_of("/") + 1, path.length());
    res = res.substr(0, res.find_last_of("."));
    return (res);
}

void Bomberman::Menu::MainLobby::__fetchSave()
{
    float yOffset = 500.0f;
    int count = 0;

    for (const auto &entry : std::filesystem::directory_iterator("./save")) {
        std::shared_ptr<Button> save = std::make_shared<Button>(entry.path(), Type::Vector<3>(775.0f, yOffset, 0.0f), "./assets/MainMenu/button_sheet_2.png", this->getFileName(entry.path()), 40);
        save->setDisplay(false);
        this->__objContainer.emplace_back(LOAD_PANEL, save);
        this->__saveButtons.emplace_back(save);
        count++;
        yOffset += 150.0f;
        if (count == 3) {
            yOffset = 500.0f;
        }
    }
    count = 0;
    for (auto const &val : this->__saveButtons) {
        val.lock()->setDisplay(true);
        count++;
        if (count == 3) {
            break;
        }
    }
    this->__saveIndex = 3;
    this->__saveDisplay = true;
}

void Bomberman::Menu::MainLobby::loadButtonCallback()
{
    this->__settings = false;
    this->__audio = false;
    this->__help = false;
    this->__gameplay = false;
    this->__video = false;
    this->mainPanelFocus = false;
    this->loadPanelFocus = true;
    this->settingsFocus = false;
    if (this->__save == false) {
        this->__save = true;
    } else {
        this->__save = false;
        for (auto const &val : this->__objContainer) {
            if (val.first != MAIN && val.first != LOAD_PANEL) {
                val.second->setDisplay(false);
            }
        }
    }
    for (auto const &val : this->__objContainer) {
        if (val.first == LOAD_PANEL) {
            val.second->setDisplay(this->__save);
        }
        if (val.first != MAIN && val.first != LOAD_PANEL) {
            val.second->setDisplay(!this->__save);
        }
    }
    this->__fetchSave();
}

void Bomberman::Menu::MainLobby::quitButtonCallback()
{
    throw QuitGame();
}

void Bomberman::Menu::MainLobby::settingsButtonCallback()
{
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
    this->helpPanelFocus = true;
    this->settingsFocus = false;
    this->mainPanelFocus = false;
    if (this->__help == false) {
        this->__help = true;
    } else {
        this->__help = false;
        for (auto const &val : this->__objContainer) {
            if (val.first != MAIN && val.first != HELP) {
                val.second->setDisplay(false);
            }
        }
        return;
    }
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
    this->audioPanelFocus = true;
    this->settingsFocus = false;
    this->mainPanelFocus = false;
    if (this->__audio == false) {
        this->__audio = true;
    } else {
        this->__audio = false;
        for (auto const &val : this->__objContainer) {
            if (val.first != MAIN && val.first != AUDIO) {
                val.second->setDisplay(false);
            }
        }
        return;
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
    this->videoPanelFocus = true;
    this->settingsFocus = false;
    this->mainPanelFocus = false;
    if (this->__video == false) {
        this->__video = true;
    } else {
        this->__video = false;
        for (auto const &val : this->__objContainer) {
            if (val.first != MAIN && val.first != VIDEO) {
                val.second->setDisplay(false);
            }
        }
        return;
    }
    for (auto const &val : this->__objContainer) {
        if (val.first == VIDEO) {
            val.second->setDisplay(this->__video);
            if (val.second->getName() == "checkedSync" && this->__configHandler.getValue(UserConfig::ValueType::VERTICAL_SYNC) == 0) {
                val.second->setDisplay(false);
            } 
            if (val.second->getName() == "uncheckedSync" && this->__configHandler.getValue(UserConfig::ValueType::VERTICAL_SYNC) == 1) {
                val.second->setDisplay(false);
            } 
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
    this->gameplayPanelFocus = true;
    this->settingsFocus = false;
    this->mainPanelFocus = false;
    if (this->__gameplay == false) {
        this->__gameplay = true;
    } else {
        this->__gameplay = false;
        for (auto const &val : this->__objContainer) {
            if (val.first != MAIN && val.first != GAMEPLAY) {
                val.second->setDisplay(false);
            }
        }
        return;
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

void Bomberman::Menu::MainLobby::manageSpecificController(int &index, std::map<int, std::string> &map)
{
    if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonPressed(0, RayLib::Window::DOWN) == true && (size_t)index < map.size() - 1) {
        std::weak_ptr<Button> button = this->findButtonByName(map[index]);
        int &state = button.lock()->getState();
        state = 0;
        index++;
    }
    if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonPressed(0, RayLib::Window::UP) == true && index > 0) {
        std::weak_ptr<Button> button = this->findButtonByName(map[index]);
        int &state = button.lock()->getState();
        state = 0;
        index--;
    }
    std::weak_ptr<Button> button = this->findButtonByName(map[index]);
    int &state = button.lock()->getState();
    state = 1;
    if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonPressed(0, RayLib::Window::A) == true) {
        if (this->__buttonCallback.count(button.lock()->getName()) > 0) {
            this->__buttonCallback[button.lock()->getName()](*this);
        }
    }
}

bool &Bomberman::Menu::MainLobby::getActivePanel()
{
    for (auto const &val : this->__objContainer) {
        if (val.first != MAIN && val.second->getDisplay() == true) {
            if (val.first == MAIN_PANEL) {
                return (this->mainPanelFocus);
            }
            if (val.first == HELP) {
                return (this->helpPanelFocus);
            }
            if (val.first == AUDIO) {
                return (this->audioPanelFocus);
            }  
            if (val.first == VIDEO) {   
                return (this->videoPanelFocus);
            }
            if (val.first == GAMEPLAY) {
                return (this->gameplayPanelFocus);
            }
            if (val.first == LOAD_PANEL) {
                return (this->loadPanelFocus);
            }
        }
    }
    throw std::runtime_error("Unexpected error");
}

std::string Bomberman::Menu::MainLobby::findFocusedPanelButton()
{
    for (auto const &val : this->__objContainer) {
        if (val.first != MAIN && val.second->getDisplay() == true) {
            if (val.first == MAIN_PANEL) {
                return (this->__controllerMapMain[this->__currentBtnMain]);
            }
            if (val.first == HELP) {
                return (this->__controllerMapHelp[this->__currentBtnHelp]);
            }
            if (val.first == AUDIO) {
                return (this->__controllerMapAudio[this->__currentBtnAudio]);
            }  
            if (val.first == VIDEO) {   
                return (this->__controllerMapVideo[this->__currentBtnVideo]);
            }
            if (val.first == GAMEPLAY) {
                return (this->__controllerMapGameplay[this->__currentBtnGameplay]);
            }
            if (val.first == LOAD_PANEL) {
                return (this->__controllerMapLoad[this->__currentBtnLoad]);
            }
        }
    }
    throw std::runtime_error("Unexpected error");
}

void Bomberman::Menu::MainLobby::manageControllerInput()
{
    
    if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonPressed(0, RayLib::Window::START) == true) {
        this->settingsButtonCallback();
        this->settingsFocus = !this->settingsFocus;
        bool &focus = this->getActivePanel();
        focus = !this->settingsFocus;
        std::weak_ptr<Button> button = this->findButtonByName(this->findFocusedPanelButton());
        int &state = button.lock()->getState();
        state = 0;
    }
    if (this->settingsFocus == true) {
        this->manageSpecificController(this->__currentBtnSettings, this->__controllerMapSettings);
        return;
    }
    if (this->helpPanelFocus) {
        this->manageSpecificController(this->__currentBtnHelp, this->__controllerMapHelp);
        return;
    }
    if (this->audioPanelFocus) {
        this->manageSpecificController(this->__currentBtnAudio, this->__controllerMapAudio);
        return;
    }
    if (this->videoPanelFocus) {
        this->manageSpecificController(this->__currentBtnVideo, this->__controllerMapVideo);
        return;
    }
    if (this->gameplayPanelFocus) {
        this->manageSpecificController(this->__currentBtnGameplay, this->__controllerMapGameplay);
        return;
    }
    if (this->mainPanelFocus == true) {
        this->manageSpecificController(this->__currentBtnMain, this->__controllerMapMain);
        return;
    }
    if (this->loadPanelFocus) {
        this->manageSpecificController(this->__currentBtnLoad, this->__controllerMapLoad);
        return;
    }
}

void Bomberman::Menu::MainLobby::__handleSaveTransition(const std::string &path)
{
    GameSceneData data(path);
    this->__manager.clearStack<Bomberman::GameScene>(data.getPlayerInputIds(), data.getPlayerIa(), data.getDll1(), data.getDll2(), data.getDll3(), data.getDll4(), data.getSavePath(), data.getTimer());
}

void Bomberman::Menu::MainLobby::update(const double &elapsed)
{
    if (RayLib::Window::getInstance().getInputKeyboard().getKeyPressed() > 0) {
        this->controllerActive = false;
        for (auto const &val : this->__buttonsReferer) {
            bool &manual = val.second.lock()->getManual();
            manual = false;
        }
        RayLib::Window::getInstance().ShowCursor();
    }
    if (RayLib::Window::getInstance().getInputGamepad().getGamepadButtonPressed() > 0) {
        this->controllerActive = true;
        for (auto const &val : this->__buttonsReferer) {
            bool &manual = val.second.lock()->getManual();
            manual = true;
        }
        RayLib::Window::getInstance().HideCursor();
    }
    if (this->controllerActive) {
        this->manageControllerInput();
    }
    for (auto const &val : this->__buttonsReferer) {
        if (val.second.lock()->isClick() == true && val.second.lock()->getDisplay()) {
            if (this->__buttonCallback.count(val.second.lock()->getName()) > 0) {
                this->__buttonCallback[val.second.lock()->getName()](*this);
            }
        }
    }
    for (auto const &val : this->__saveButtons) {
        if (val.lock()->getDisplay() && val.lock()->isClick() && this->__saveDisplay == false) {
            this->__handleSaveTransition(val.lock()->getName());
            return;
        }
    }
    this->__saveDisplay = false;
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