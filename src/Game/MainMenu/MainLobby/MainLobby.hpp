/**
 * @file MainLobby.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../SceneManager/Scene/Scene.hpp"

#include "../../Parralax/Parralax.hpp"
#include "../../Image/Image.hpp"
#include "../../Button/Button.hpp"
#include "../../UserConfig/UserConfig.hpp"
#include "../../FlashingText/FlashingText.hpp"
#include <map>
#include <functional>
#include <filesystem>
#include "../SelectionMenu/SelectionMenu.hpp"

namespace Bomberman {
    namespace Menu {
        class MainLobby : public Scene {
            public:
                MainLobby() = delete;
                MainLobby(SceneManager &manager);
                ~MainLobby() = default;

                MainLobby(const MainLobby &) = delete;
                MainLobby &operator = (const MainLobby &) = delete;

                void update(const double &elapsed);
                void drawScene();
            protected:
            private:
                enum MENU_UI {
                    MAIN,
                    MAIN_PANEL,
                    OPTION_PANEL,
                    HELP,
                    AUDIO,
                    VIDEO,
                    GAMEPLAY,
                    LOAD_PANEL
                };

                void __deleteSaveButtons(const std::vector<std::string> &container);
                void __fetchSave();

                void createSavePanel();
                void createAudioPanel();
                void createHelpPanel();
                void createVideoPanel();
                void createGameplayPanel();

                void playButtonCallback();
                void loadButtonCallback();
                void quitButtonCallback();
                void settingsButtonCallback();

                //settings Panel
                void helpButtonCallback();
                void audioButtonCallback();
                void videoButtonCallback();
                void gameplayButtonCallback();
                void creditsButtonCallback();

                // load panel
                void closeButtonCallback();
                void backButtonCallback();
                void forwardButtonCallback();

                // audio panel
                void closeAudioCallback();
                void confirmAudioCallback();
                void leftMasterAudioCallback();
                void rightMasterAudioCallback();
                void leftMusicAudioCallback();
                void rightMusicAudioCallback();
                void setAudioChanges();

                // help panel
                void closeHelpCallback();

                // video panel
                void closeVideoPanel();
                void confirmVideo();
                void leftRefreshVideo();
                void rightRefreshVideo();
                void checkedSyncVideo();
                void uncheckedSyncVideo();
                
                // gameplay panel
                void closeGameplayPanel();

                std::weak_ptr<GameObject> findElemByName(const std::string &name);
                std::weak_ptr<FlashingText> findTextByName(const std::string &name);
                std::weak_ptr<Bomberman::Button> findButtonByName(const std::string &name);

                std::vector<std::pair<MENU_UI, std::shared_ptr<GameObject>>> __objContainer;
                std::vector<std::pair<MENU_UI, std::weak_ptr<Button>>> __buttonsReferer;
                std::vector<std::pair<MENU_UI, std::weak_ptr<FlashingText>>> __dynamicTextReferer;
                std::map<std::string, std::function<void(MainLobby &)>> __buttonCallback;

                std::map<int, std::string> __controllerMapMain;
                int __currentBtnMain;
                std::map<int, std::string> __controllerMapSettings;
                int __currentBtnSettings;

                std::map<int, std::string> __controllerMapHelp;
                int __currentBtnHelp;

                std::map<int, std::string> __controllerMapAudio;
                int __currentBtnAudio;

                std::map<int, std::string> __controllerMapVideo;
                int __currentBtnVideo;

                std::map<int, std::string> __controllerMapGameplay;
                int __currentBtnGameplay;

                std::map<int, std::string> __controllerMapLoad;
                int __currentBtnLoad;

                std::string getFileName(const std::string &val);
                std::vector<std::weak_ptr<Button>> __saveButtons;                

                bool settingsFocus;
                bool mainPanelFocus;
                bool helpPanelFocus;
                bool audioPanelFocus;
                bool videoPanelFocus;
                bool gameplayPanelFocus;
                bool loadPanelFocus;
                void manageControllerInput();
                void manageSpecificController(int &index, std::map<int, std::string> &map);

                std::string findFocusedPanelButton();
                
                bool &getActivePanel();

                bool __settings;
                bool __save;
                bool __audio;
                bool __help;
                bool __video;
                bool __gameplay;
                

                int __ignore;
                int __saveIndex;

                bool controllerActive;

                UserConfig __configHandler;
        };
    }
}