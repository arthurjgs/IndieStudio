/**
 * @file TestScene.cpp
 * @brief
 * @version 0.1
 * @date 2021-05-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "GameScene.hpp"
#include <cmath>
#include <RayLib/Window.hpp>
#include <RayLib/Model/Collision/Collision.hpp>
#include <Game/Bomb/Bomb.hpp>
#include <players/AbstractPlayer.hpp>
#include <DynamicLibrary/DynamicLibrary.hpp>
#include <Game/StarBonus/StarBonus.hpp>
#include <Game/BombBonus/BombBonus.hpp>
#include <Game/SpeedBonus/SpeedBonus.hpp>
#include <Game/RangeBonus/RangeBonus.hpp>
#include "../QuitGame/QuitGame.hpp"
#include "../MainMenu/MainLobby/MainLobby.hpp"
#include "../End/End.hpp"

std::string Bomberman::GameScene::addZeroOrNot(int value) const
{
    if (std::to_string(value).length() == 1) {
        return ("0");
    }
    return ("");
}

std::string Bomberman::GameScene::convertSecondToDisplayTime(int value) const
{
    std::string res;
    int min = 0;

    while (value > 60) {
        value -= 60;
        min++;
    }
    if (value == 60) {
        res = std::to_string(min + 1) + ":00";
    } else {
        res = std::to_string(min) + ":" + this->addZeroOrNot(value) + std::to_string(value);
    }
    return (res);
}

void Bomberman::GameScene::continueCallback()
{
    this->_pause = false;
    this->_currentUIStage = UI_SCENE::MAIN;
    for (auto const &val : this->_2DGameObjectList) {
        if (val.first == PAUSE) {
            val.second->setDisplay(false);
        }
        if (val.first == MAIN) {
            val.second->setDisplay(true);
        }
    }
}

void Bomberman::GameScene::saveCallback()
{
    std::weak_ptr<FlashingText> text = this->getTextFromName("inputField");

    std::string &val = text.lock()->getText();
    val = "";
    this->_saveName = "";
    this->isInput = true;
    this->getObjectFromName("backSave").lock()->setDisplay(true);
    this->getObjectFromName("confirmSave").lock()->setDisplay(true);
    this->getObjectFromName("cancelSave").lock()->setDisplay(true);
    this->getObjectFromName("titleSave").lock()->setDisplay(true);
    this->getObjectFromName("inputField").lock()->setDisplay(true);
    for (auto const &val : this->_2DGameObjectList) {
        if (val.first == PAUSE) {
            val.second->setDisplay(false);
        }
    }
}

void Bomberman::GameScene::quitCallback()
{
    RayLib::Window::loadingScreen();
    this->__manager.replaceTop<Menu::MainLobby>();
    this->quitting = true;
}

void Bomberman::GameScene::confirmSaveCallback()
{
    this->isInput = false;
    this->getObjectFromName("backSave").lock()->setDisplay(false);
    this->getObjectFromName("confirmSave").lock()->setDisplay(false);
    this->getObjectFromName("cancelSave").lock()->setDisplay(false);
    this->getObjectFromName("titleSave").lock()->setDisplay(false);
    this->getObjectFromName("inputField").lock()->setDisplay(false);
    for (auto const &val : this->_2DGameObjectList) {
        if (val.first == PAUSE) {
            val.second->setDisplay(true);
        }
    }
    SaveData resData(this->_gameObjectList, this->_listPlayers, this->_timer);
    Save res(std::move(resData), this->_saveName);
}

void Bomberman::GameScene::cancelSaveCallback()
{
    this->isInput = false;
    this->getObjectFromName("backSave").lock()->setDisplay(false);
    this->getObjectFromName("confirmSave").lock()->setDisplay(false);
    this->getObjectFromName("cancelSave").lock()->setDisplay(false);
    this->getObjectFromName("titleSave").lock()->setDisplay(false);
    this->getObjectFromName("inputField").lock()->setDisplay(false);
    for (auto const &val : this->_2DGameObjectList) {
        if (val.first == PAUSE) {
            val.second->setDisplay(true);
        }
    }
}

void Bomberman::GameScene::createPause()
{
    this->_2DGameObjectList.emplace_back(PAUSE, std::make_shared<Image>("./assets/MainMenu/Panel1.png", "pauseBack", GameObject::ObjectType::DECOR, Type::Vector<3>(770.0f, 200.0f, 0.0f), false));
    this->_2DGameObjectList.emplace_back(PAUSE, std::make_shared<FlashingText>("GAME PAUSED", Type::Color(255, 255, 255, 255), 50, 0.0, "titlePause", GameObject::DECOR, Type::Vector<2>(785.0f, 275.0f), false));

    std::shared_ptr<Button> continueGame = std::make_shared<Button>("continueGame", Type::Vector<3>(790.0f, 400.0f, 0.0f), "./assets/MainMenu/button_sheet_2.png", "CONTINUE", 40);
    continueGame->setDisplay(false);
    this->_2DGameObjectList.emplace_back(PAUSE, continueGame);
    this->_2DButtonList.emplace_back(PAUSE, continueGame);

    std::shared_ptr<Button> saveGame = std::make_shared<Button>("saveGame", Type::Vector<3>(790.0f, 550.0f, 0.0f), "./assets/MainMenu/button_sheet_2.png", "SAVE GAME", 40);
    saveGame->setDisplay(false);
    this->_2DGameObjectList.emplace_back(PAUSE, saveGame);
    this->_2DButtonList.emplace_back(PAUSE, saveGame);

    std::shared_ptr<Button> quitGame = std::make_shared<Button>("quitGame", Type::Vector<3>(790.0f, 700.0f, 0.0f), "./assets/MainMenu/button_sheet_2.png", "QUIT GAME", 40);
    quitGame->setDisplay(false);
    this->_2DGameObjectList.emplace_back(PAUSE, quitGame);
    this->_2DButtonList.emplace_back(PAUSE, quitGame);

    this->_2DGameObjectList.emplace_back(NONE, std::make_shared<Image>("./assets/MainMenu/PanelWindow.png", "backSave", GameObject::ObjectType::DECOR, Type::Vector<3>(675.0f, 400.0f, 0.0f), false));
    this->_2DGameObjectList.emplace_back(NONE, std::make_shared<FlashingText>("SAVE NAME", Type::Color(255, 255, 255, 255), 50, 0.0, "titleSave", GameObject::DECOR, Type::Vector<2>(800.0f, 500.0f), false));

    std::shared_ptr<Button> cancelSave = std::make_shared<Button>("cancelSave", Type::Vector<3>(700.0f, 700.0f, 0.0f), "./assets/MainMenu/close.png");
    cancelSave->setDisplay(false);
    std::shared_ptr<Button> confirmSave = std::make_shared<Button>("confirmSave", Type::Vector<3>(1150.0f, 700.0f, 0.0f), "./assets/MainMenu/confirm.png");
    confirmSave->setDisplay(false);

    this->_2DGameObjectList.emplace_back(NONE, cancelSave);
    this->_2DGameObjectList.emplace_back(NONE, confirmSave);
    this->_2DButtonList.emplace_back(NONE, cancelSave);
    this->_2DButtonList.emplace_back(NONE, confirmSave);

    std::shared_ptr<FlashingText> inputField = std::make_shared<FlashingText>("", Type::Color(255, 255, 255, 255), 60, 0.0, "inputField", GameObject::ObjectType::DECOR, Type::Vector<2>(762.0f, 600.0f));

    this->_2DGameObjectList.emplace_back(NONE, inputField);
    this->_2DDynamicText.emplace_back(NONE, inputField);

    this->_buttonCallback["continueGame"] = &GameScene::continueCallback;
    this->_buttonCallback["saveGame"] = &GameScene::saveCallback;
    this->_buttonCallback["quitGame"] = &GameScene::quitCallback;
    this->_buttonCallback["cancelSave"] = &GameScene::cancelSaveCallback;
    this->_buttonCallback["confirmSave"] = &GameScene::confirmSaveCallback;
}

std::shared_ptr<Bomberman::Player> Bomberman::GameScene::loadPlayerFromSave(const PlayerData &data)
{
    std::shared_ptr<Player> player = std::make_shared<Player>(data.getName(), data.getPositions(),
            data.getAi(), data.getController(), data.getPath(), data.getSpeed(),
            data.getBombs(), data.getRange());

    player->setDisplay(data.getDisplay());
    player->setAlive(data.getAlive());

    try {
        std::unique_ptr<LibDl::DynamicLibrary> dl = std::make_unique<LibDl::DynamicLibrary>(data.getPath());
        auto fct = dl->getSym<Bomberman::AbstractPlayer *(*)(void)>("entryPoint");
        AbstractPlayer *p1 = fct();
        if (p1 == nullptr)
            throw GameException("Symbol not found entryPoint in " + data.getPath());
        player->setScale(Type::Vector<3>(p1->getScale(), p1->getScale(), p1->getScale()));
    } catch (LibDl::DynamicLibraryException &e) {
        throw e;
    }
    return (player);
}

void Bomberman::GameScene::__createCratesFromSaves(const std::string &path)
{
    for (auto & obj : this->_gameMap.lock()->createCratesSaves(path))
    {
        for (auto &val : this->_listPlayers)
            val.lock()->updateCollisions(obj->getPosition(), 1);
        this->_gameObjectList.emplace_back(obj);
        this->_CrateList.emplace_back(obj);
    }
}


Bomberman::GameScene::GameScene(SceneManager &manager, const std::vector<int> &playerInputIds, const std::vector<int> &playerIa,
                                const std::string &playerDll1, const std::string &playerDll2,
                                const std::string &playerDll3, const std::string &playerDll4,
                                const std::string &savePath, const int timer) : Scene(manager),
                                _camera(Type::Vector<3>(0.0f, 40.0f, 20.0f),
                                        Type::Vector<3>(0.0f, 0.0f, 0.0f),
                                        Type::Vector<3>(0.0f, 1.0f, 0.0f),
                                        20.0f,
                                        CAMERA_PERSPECTIVE),
                                        _soundExplosion("./assets/sound_effects/explosion_bombe.wav"),
                                        _soundFlame("./assets/sound_effects/flame_effects.wav"),
                                        _soundDeath("./assets/sound_effects/death_sound.wav"),
                                        _soundBombFuse("./assets/sound_effects/fuse_bomb.wav")
{
    RayLib::Manager3D::getInstance().setScene(RayLib::Manager3D::GAME);
    this->_cratesPct = this->__confingHandler.getValue(UserConfig::ValueType::CRATE_DROP);
    this->_bonusPct = this->__confingHandler.getValue(UserConfig::ValueType::BONUS_DROP);
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Player> player3;
    std::shared_ptr<Player> player4;
    if (savePath != "") {
        PlayerParse parser(savePath);

        player1 = loadPlayerFromSave(parser.getPlayerOne());
        player2 = loadPlayerFromSave(parser.getPlayerTwo());
        player3 = loadPlayerFromSave(parser.getPlayerThree());
        player4 = loadPlayerFromSave(parser.getPlayerFour());
    } else {
        player1 = loadPlayerDll(playerDll1, playerInputIds[0], playerIa[0], Type::Vector<3>(-6.0f, 0.0f, -6.0f));
        player2 = loadPlayerDll(playerDll2, playerInputIds[1], playerIa[1], Type::Vector<3>(6.0f, 0.0f, -6.0f));
        player3 = loadPlayerDll(playerDll3, playerInputIds[2], playerIa[2], Type::Vector<3>(-6.0f, 0.0f, 6.0f));
        player4 = loadPlayerDll(playerDll4, playerInputIds[3], playerIa[3], Type::Vector<3>(6.0f, 0.0f, 6.0f));
    }
    this->_timer = timer;
    std::shared_ptr<Map> gameMap = std::make_shared<Map>("assets/map/default", Type::Vector<3>(-7.0f, 0.0f, -7.0f));
    this->_background = std::make_shared<Image>("assets/map/default/bg.png", "Background", GameObject::DECOR, Type::Vector<3>(0.0f, 0.0f, 0.0f));

    this->_gameObjectList.emplace_back(std::make_shared<Music>("MainMusic", "assets/sounds/music.mp3", this->__confingHandler.getValue(UserConfig::ValueType::MUSIC_VOL)));
    this->_gameObjectList.emplace_back(gameMap);
    this->_gameObjectList.emplace_back(player1);
    this->_gameObjectList.emplace_back(player2);
    this->_gameObjectList.emplace_back(player3);
    this->_gameObjectList.emplace_back(player4);

    std::shared_ptr<Image> timer_back = std::make_shared<Image>("./assets/game_scenes/timer.png", "backgroud_timer", GameObject::ObjectType::DECOR, Type::Vector<3>(810.0f, 50.0f, 0.0f));
    this->_2DGameObjectList.emplace_back(MAIN, timer_back);
    Type::Color &color = timer_back->getColor();
    uChar &transparency = color.getA();
    transparency = 200;

    std::shared_ptr<FlashingText> text = std::make_shared<FlashingText>(this->convertSecondToDisplayTime(this->_timer), Type::Color(255, 255, 255, 255), 60, 0.0, "timer", GameObject::ObjectType::DECOR, Type::Vector<2>(900.0f, 90.0f));
    this->_2DGameObjectList.emplace_back(MAIN, text);
    this->_2DDynamicText.emplace_back(MAIN, text);
    this->_listPlayers.emplace_back(player1);
    this->_listPlayers.emplace_back(player2);
    this->_listPlayers.emplace_back(player3);
    this->_listPlayers.emplace_back(player4);

    this->createPause();

    this->_gameMap = gameMap;
    if (savePath != "") {
        this->__createCratesFromSaves(savePath);
    } else {
        for (auto & obj : this->_gameMap.lock()->createCrates(this->_cratesPct))
        {
            for (auto &val : this->_listPlayers)
                val.lock()->updateCollisions(obj->getPosition(), 1);
            this->_gameObjectList.emplace_back(obj);
            this->_CrateList.emplace_back(obj);
        }
    }

    //this->_listPlayers.emplace_back(player2);
    this->_currentUIStage = MAIN;
    this->_second = 0.0;
    this->quitting = false;
    this->_pause = false;
    this->isInput = false;
    this->_everySecond = 0.0;
    _checkCamera = false;
    _timerCamera = 0.0f;
    _cameraOriginX = _camera.getPosition().getX();
    _cameraOriginZ = _camera.getPosition().getZ();
}

bool Bomberman::GameScene::checkCollisionForMap(const Type::Vector<3> &playerPosition) const
{
    Type::Vector<2> playerPos = { playerPosition.getX(), playerPosition.getZ() };
    Type::Vector<2> cubicMap = this->_gameMap.lock()->getCubicMap();
    int cubicMapX = static_cast<int>(cubicMap.getX());
    int cubicMapY = static_cast<int>(cubicMap.getY());
    float playerRadius = 0.3f;
    std::vector<Type::Color> mapPixels = _gameMap.lock()->getMapPixels();

    int playerCellX = static_cast<int>(round(playerPos.getX() - _gameMap.lock()->getPosition().getX() + 0.5f));
    int playerCellY = static_cast<int>(round(playerPos.getY() - _gameMap.lock()->getPosition().getZ() + 0.5f));

    if (playerCellX < 0) playerCellX = 0;
    else if (playerCellX >= cubicMapX) playerCellX = cubicMapX - 1;

    if (playerCellY < 0) playerCellY = 0;
    else if (playerCellY >= cubicMapY) playerCellY = cubicMapY - 1;

    for (int y = 0; y < cubicMapY; y++)
    {
        for (int x = 0; x < cubicMapX; x++)
        {
            if ((mapPixels[y * cubicMapX + x].getR() == 255) &&
                (RayLib::Models::Collision::CheckCollisionCircleRec(playerPos, playerRadius,
                                         Type::Rectangle { _gameMap.lock()->getPosition().getX() - 0.5f + x * 1.0f,
                                                           _gameMap.lock()->getPosition().getZ() - 0.5f + y * 1.0f,
                                                           1.0f,
                                                           1.0f })))
            {
                return true;
            }
        }
    }

    return false;
}

std::weak_ptr<Bomberman::GameObject> Bomberman::GameScene::getObjectFromName(const std::string &name)
{
    for (auto const &val : this->_2DGameObjectList) {
        if (val.second->getName() == name) {
            return (val.second);
        }
    }
    throw std::runtime_error(name + " does not exist in dynamic text");
}

std::weak_ptr<Bomberman::FlashingText> Bomberman::GameScene::getTextFromName(const std::string &name)
{
    for (auto const &val : this->_2DDynamicText) {
        if (val.second.lock()->getName() == name) {
            return (val.second);
        }
    }
    throw std::runtime_error(name + " does not exist in dynamic text");
}

Bomberman::GameScene::COLLIDE_EVENT Bomberman::GameScene::checkCollisionForObjects(const Type::Vector<3> &playerPosition, bool isFlame, bool isBomb)
{
    for (auto & obj : _gameObjectList) {
        if (obj->getType() == GameObject::PLAYER)
            continue;
        Type::Vector<3> enemyPosition = obj->getPosition();
        Type::Vector<3> playerRoundedPosition(static_cast<float>(round(playerPosition.getX())),
                                              static_cast<float>(round(playerPosition.getY())),
                                              static_cast<float>(round(playerPosition.getZ())));
        if (RayLib::Models::Collision::CheckCollisionBoxes(Type::BoundingBox(Type::Vector<3>(playerRoundedPosition.getX() - 1.0f / 2,
                                                                                             playerRoundedPosition.getY() - 1.0f / 2,
                                                                                             playerRoundedPosition.getZ() - 1.0f / 2),
                                                                             Type::Vector<3>(playerRoundedPosition.getX() - 1.0f / 2,
                                                                                             playerRoundedPosition.getY() - 1.0f / 2,
                                                                                             playerRoundedPosition.getZ() - 1.0f / 2)),
                                                           Type::BoundingBox(Type::Vector<3>(enemyPosition.getX() - 1.0f / 2,
                                                                                             enemyPosition.getY() - 1.0f / 2,
                                                                                             enemyPosition.getZ() - 1.0f / 2),
                                                                             Type::Vector<3>(enemyPosition.getX() - 1.0f / 2,
                                                                                             enemyPosition.getY() - 1.0f / 2,
                                                                                             enemyPosition.getZ() - 1.0f / 2)))) {
            if (isFlame) {
                if (obj == nullptr)
                    return BASIC;
                for (auto &val : this->_listPlayers)
                    val.lock()->updateCollisions(obj->getPosition(), 0);
                if (obj->getName() ==  "Crate")
                    createBonus(obj->getPosition());
                if (obj->getType() != GameObject::BONUS)
                    obj->destroy();
                return BASIC;
            }
            if (obj->getType() == Bomb::BOMB && isBomb)
                continue;
            if (obj->getType() == Bomb::FLAME)
            {
                _soundDeath.PlaySound();
                return DEATH;
            }
            return BASIC;
        }
    }
    return COLLIDE_EVENT::NOTHING;
}

Bomberman::GameScene::COLLIDE_EVENT Bomberman::GameScene::checkCollisionForObjects(const std::weak_ptr<Player> &player, bool isFlame, bool isBomb)
{
    Type::Vector<3> playerPosition = player.lock()->getPosition();

    for (auto & obj : _gameObjectList) {
        if (obj->getType() == GameObject::PLAYER)
            continue;
        Type::Vector<3> enemyPosition = obj->getPosition();
        Type::Vector<3> playerRoundedPosition(static_cast<float>(round(playerPosition.getX())),
                                              static_cast<float>(round(playerPosition.getY())),
                                              static_cast<float>(round(playerPosition.getZ())));
        if (RayLib::Models::Collision::CheckCollisionBoxes(Type::BoundingBox(Type::Vector<3>(playerRoundedPosition.getX() - 1.0f / 2,
                                                                                             playerRoundedPosition.getY() - 1.0f / 2,
                                                                                             playerRoundedPosition.getZ() - 1.0f / 2),
                                                                             Type::Vector<3>(playerRoundedPosition.getX() - 1.0f / 2,
                                                                                             playerRoundedPosition.getY() - 1.0f / 2,
                                                                                             playerRoundedPosition.getZ() - 1.0f / 2)),
                                                           Type::BoundingBox(Type::Vector<3>(enemyPosition.getX() - 1.0f / 2,
                                                                                             enemyPosition.getY() - 1.0f / 2,
                                                                                             enemyPosition.getZ() - 1.0f / 2),
                                                                             Type::Vector<3>(enemyPosition.getX() - 1.0f / 2,
                                                                                             enemyPosition.getY() - 1.0f / 2,
                                                                                             enemyPosition.getZ() - 1.0f / 2)))) {
            if (isFlame) {
                for (auto &val : this->_listPlayers)
                    val.lock()->updateCollisions(obj->getPosition(), 0);
                if (obj->getName() ==  "Crate")
                    createBonus(obj->getPosition());
                if (obj->getType() != GameObject::BONUS)
                    obj->destroy();
                return BASIC;
            }

            if (obj->getType() == Bomb::BOMB && isBomb)
                continue;

            if (obj->getType() == Bomb::FLAME)
            {
                _soundDeath.PlaySound();
                return DEATH;
            }

            if (obj->getType() == GameObject::BONUS) {
                std::string name = obj->getName();
                if (name == "BombBonus") {
                    player.lock()->addBomb();
                }
                if (name == "SpeedBonus") {
                    player.lock()->setSpeed(static_cast<float>(player.lock()->getSpeed()) + 0.5f);
                }
                if (name == "RangeBonus") {
                    player.lock()->setRange(player.lock()->getRange() + 1);
                }
                if (name == "StarBonus") {
                    player.lock()->addBomb();
                    player.lock()->setRange(player.lock()->getRange() + 1);
                    player.lock()->setSpeed(static_cast<float>(player.lock()->getSpeed()) + 0.5f);
                }
                obj->destroy();
            }
            return BASIC;
        }
    }
    return COLLIDE_EVENT::NOTHING;
}

void Bomberman::GameScene::handleSaveNaming()
{
    std::weak_ptr<FlashingText> text = this->getTextFromName("inputField");

    char value = RayLib::Window::getInstance().getInputKeyboard().getCharPressed();
    if (this->_saveName.length() > 0 && RayLib::Window::getInstance().getInputKeyboard().isKeyPressed(KEY_BACKSPACE)) {
        this->_saveName = this->_saveName.substr(0, this->_saveName.length() - 1);
        std::string &current = text.lock()->getText();
        current = this->_saveName;
        return;
    }
    if (value > 0 && this->_saveName.length() <= 10) {
        std::cout << (int)value << std::endl;
        this->_saveName += value;
        std::string &current = text.lock()->getText();
        current = this->_saveName;
    }
}

void Bomberman::GameScene::updatePause(const double &elapsed)
{
    if (RayLib::Window::getInstance().getInputKeyboard().isKeyPressed(KEY_P) && !this->isInput) {
        this->_pause = !this->_pause;
        if (this->_pause == true) {
            this->_currentUIStage = UI_SCENE::PAUSE;
            for (auto const &val : this->_2DGameObjectList) {
                if (val.first == PAUSE) {
                    val.second->setDisplay(true);
                }
                if (val.first == MAIN) {
                    val.second->setDisplay(false);
                }
            }
        } else {
            this->_currentUIStage = UI_SCENE::MAIN;
            for (auto const &val : this->_2DGameObjectList) {
                if (val.first == PAUSE) {
                    val.second->setDisplay(false);
                }
                if (val.first == MAIN) {
                    val.second->setDisplay(true);
                }
            }
        }
    }
    if (this->_pause == true) {
        if (this->getObjectFromName("backSave").lock()->getDisplay())  {
            this->handleSaveNaming();
        }
        for (auto const &val : this->_2DButtonList) {
            if (!val.second.lock()->getDisplay())
                continue;
            if (val.second.lock()->isClick() && (val.first == UI_SCENE::PAUSE || val.first == UI_SCENE::NONE)) {
                if (this->_buttonCallback.count(val.second.lock()->getName()) > 0) {
                    this->_buttonCallback[val.second.lock()->getName()](*this);
                    if (this->quitting) {
                        return;
                    }
                }
            }
        }
        for (auto const &val : this->_2DGameObjectList) {
            if (val.first == UI_SCENE::PAUSE || val.first == NONE) {
                val.second->update(elapsed);
            }
        }
    }
}

bool Bomberman::GameScene::__lastAlive() const
{
    int count = 0;

    for (auto const &val : this->_listPlayers) {
        if (val.lock()->getAlive()) {
            count++;
        }
    }
    if (count == 1) {
        return (true);
    }
    return (false);
}

void Bomberman::GameScene::update(const double &elapsed)
{
    if (this->__lastAlive()) {
        RayLib::Window::loadingScreen();
        this->__manager.clearStack<End>();
        return;
    }
    std::vector<int> sideList;
    this->_everySecond += elapsed;
    this->_timerCamera += elapsed;
    float &x = _camera.getPosition().getX();
    float &z = _camera.getPosition().getZ();

    if (_checkCamera)
    {
        int random = rand() % 2;
        int randomSign = rand() % 2;
        int randomNumber = rand() % 3 + 1;
        if (random == 1)
        {
            if (randomSign == 0)
                x += randomNumber;
            else
                x -= randomNumber;
        }
        else if (random == 0)
        {
            if (randomSign == 0)
                z += randomNumber;
            else
                z -= randomNumber;
        }
    }
    if (_timerCamera > 1)
    {
        _checkCamera = false;
        _timerCamera = 0.0;
        x = _cameraOriginX;
        z = _cameraOriginZ;
    }
    
    // CHECK IF PAUSE HIS ON GOING
    this->updatePause(elapsed);
    if (this->_pause == true || this->quitting) {
        return;
    }

    // CHECK IF BOMB HAS EXPLODED
    for (auto & b : _bombList) {
        if (b.expired())
            continue;
        if (b.lock()->getState() == GameObject::DESTROYED) {
            _soundExplosion.PlaySound();
            auto flames = b.lock()->explode();
            for (auto & flame : flames) {
                if (std::find(sideList.begin(), sideList.end(), flame->getSide()) != sideList.end())
                    continue;
                if (checkCollisionForObjects(flame->getPosition(), true) == BASIC ||
                    checkCollisionForMap(flame->getPosition()))
                    sideList.emplace_back(flame->getSide());
                _gameObjectList.emplace_back(flame);
                _soundFlame.PlaySound();
            }
            for (auto &val : this->_listPlayers)
            {
                val.lock()->updateCollisions(b.lock()->getPosition(), 0);
                val.lock()->updateDangers(b.lock()->getPosition(), b.lock()->getRange(), 0);
            }
        }
    }


    // CHECK IF OBJECTS SHOULD BE DESTROYED
    _gameObjectList.erase(std::remove_if(
            _gameObjectList.begin(), _gameObjectList.end(),
            [] (std::shared_ptr<Bomberman::GameObject> &b) {
                return b->getState() == GameObject::DESTROYED;
            }), _gameObjectList.end());

    for (auto & object : _gameObjectList) {
        if (object->getType() != GameObject::PLAYER)
            object->update(elapsed);
    }

    for (auto & player : _listPlayers) {
        if (!player.lock()->getAlive()) {
            if (this->_everySecond > 1.0) {
                player.lock()->setDisplay(false);
            }
            continue;
        }
        if (player.lock()->getState() == Player::PlayerState::ACTION) {
            double angle = player.lock()->getRotationAngle();
            auto position = player.lock()->getPosition();
            auto bombPos = Type::Vector<3>();

            if (angle == 0)
                bombPos = Type::Vector<3>(static_cast<float>(round(position.getX())),
                                                  static_cast<float>(round(position.getY())),
                                                  static_cast<float>(round(position.getZ() + 1)));
            else if (angle == 180)
                bombPos = Type::Vector<3>(static_cast<float>(round(position.getX())),
                                                  static_cast<float>(round(position.getY())),
                                                  static_cast<float>(round(position.getZ() - 1)));
            else if (angle == 90)
                bombPos = Type::Vector<3>(static_cast<float>(round(position.getX() + 1)),
                                                  static_cast<float>(round(position.getY())),
                                                  static_cast<float>(round(position.getZ())));
            else if (angle == -90)
                bombPos = Type::Vector<3>(static_cast<float>(round(position.getX()) - 1),
                                                  static_cast<float>(round(position.getY())),
                                                  static_cast<float>(round(position.getZ())));
            if (checkCollisionForMap(bombPos) || checkCollisionForObjects(bombPos, false, true) == BASIC) {
                player.lock()->setState(Player::PlayerState::IDLE);
                continue;
            }
            std::shared_ptr<Bomb> bomb = player.lock()->createBomb();
            _soundBombFuse.PlaySound();
            if (bomb != nullptr) {

                for (auto &val : this->_listPlayers)
                {
                    val.lock()->updateCollisions(bomb->getPosition(), 1);
                    val.lock()->updateDangers(bomb->getPosition(), bomb->getRange(), 1);
                }
                _gameObjectList.emplace_back(bomb);
                _bombList.emplace_back(bomb);
            }
        }
        auto oldPosition = player.lock()->getPosition();
        player.lock()->update(elapsed);
        if (checkCollisionForMap(player.lock()->getPosition()))
            player.lock()->setPosition(oldPosition);
        COLLIDE_EVENT ret = checkCollisionForObjects(player);
        if (ret == BASIC)
            player.lock()->setPosition(oldPosition);
        if (ret == DEATH) {
            _checkCamera = true;
            // A PLAYER DEATH START HERE
            player.lock()->setAlive(false);
            player.lock()->setState(Player::PlayerState::DEAD);
            player.lock()->setPosition(oldPosition);
            this->_everySecond = 0.0;
        }
    }
    this->_second += elapsed;
    if (this->_second >= 1) {
        this->_timer--;
        std::string &text = this->getTextFromName("timer").lock()->getText();
        text = this->convertSecondToDisplayTime(this->_timer);
        if (this->_timer == 0) {
            // TODO: HANDLE PROPERLY TIMER TO ZERO
            throw QuitGame();
        }
        this->_second = 0.0;
    }
    for (auto const &val : this->_2DGameObjectList) {
        val.second->update(elapsed);
    }
    for (auto const &val : this->_2DButtonList) {
        if (val.second.lock()->isClick() && val.second.lock()->getDisplay()) {
            if (this->_buttonCallback.count(val.second.lock()->getName()) > 0) {
                this->_buttonCallback[val.second.lock()->getName()](*this);
            }
        }
    }
}

void Bomberman::GameScene::drawScene()
{
    _background->render();
    RayLib::Window::getInstance().getDrawing().beginMode3D(_camera);
    for (auto & object : _gameObjectList) {
        if (object->getDisplay())
            object->render();
    }
    RayLib::Window::getInstance().getDrawing().endMode3D();
    for (auto const &val : this->_2DGameObjectList) {
        if ((this->_currentUIStage == val.first || val.first == NONE) && val.second->getDisplay())
            val.second->render();
    }
}

std::shared_ptr<Bomberman::Player> Bomberman::GameScene::loadPlayerDll(const std::string &dllPath, int inputId, int isIa, const Type::Vector<3> &position)
{
    std::shared_ptr<Player> player;

    try {
        std::unique_ptr<LibDl::DynamicLibrary> dl = std::make_unique<LibDl::DynamicLibrary>(dllPath);
        auto fct = dl->getSym<Bomberman::AbstractPlayer *(*)(void)>("entryPoint");
        AbstractPlayer *p1 = fct();
        if (p1 == nullptr)
            throw GameException("Symbol not found entryPoint in " + dllPath);
        if (isIa == -1) {
            player = std::make_shared<Player>(p1->getName(), position,
                                              true, inputId, dllPath, p1->getSpeed(), p1->getBombs(), p1->getRange());
        } else {
            player = std::make_shared<Player>(p1->getName(), position,
                                              false, inputId, dllPath, p1->getSpeed(), p1->getBombs(), p1->getRange());
        }
        player->setScale(Type::Vector<3>(p1->getScale(), p1->getScale(), p1->getScale()));
    } catch (LibDl::DynamicLibraryException &e) {
        throw e;
    }

    return player;
}

void Bomberman::GameScene::createBonus(const Type::Vector<3> &pos)
{
    if (rand() % (100 + 1) <= this->_bonusPct) {
        int which = rand() % (3 + 1);
        switch (which) {
            case 0:
                _gameObjectList.emplace_back(std::make_shared<StarBonus>(pos));
                break;
            case 1:
                _gameObjectList.emplace_back(std::make_shared<BombBonus>(pos));
                break;
            case 2:
                _gameObjectList.emplace_back(std::make_shared<SpeedBonus>(pos));
                break;
            case 3:
                _gameObjectList.emplace_back(std::make_shared<RangeBonus>(pos));
                break;
        }

    }
}
