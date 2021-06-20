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
#include "../../GameScene/GameScene.hpp"
#include "../../../RayLib/Window.hpp"
#include <Game/Config.hpp>
#include <DynamicLibrary/DynamicLibrary.hpp>
#include <players/AbstractPlayer.hpp>
#include <RayLib/Manager3D.hpp>

Bomberman::Menu::SelectionMenu::SelectionMenu(SceneManager &manager) : Scene(manager), _camera(Type::Vector<3>(0.0f, 1.0f, 15.0f),
                                                                                               Type::Vector<3>(0.0f, 0.0f, 0.0f),
                                                                                               Type::Vector<3>(0.0f, 1.0f, 0.0f),
                                                                                               25.0f,
                                                                                               CAMERA_PERSPECTIVE),
                                                                                               _readySound("./assets/sound_effects/ready.wav")
{
    RayLib::Manager3D::getInstance().setScene(RayLib::Manager3D::PLAYER_SELECTION);
    _players = 1;
    _selectionPlayer = 0;
    _isAction = false;
    const std::string text = "MULTIPLAYER BATTLE";

    std::shared_ptr<StateImage> playerOne = std::make_shared<StateImage>("./assets/selectionmenu/selectionmenu.png", "perso1", GameObject::ObjectType::DECOR, Type::Vector<3>(85.0f, 340.0f, 0.0f), 2);
    std::shared_ptr<StateImage> playerTwo = std::make_shared<StateImage>("./assets/selectionmenu/selectionmenu.png", "perso2", GameObject::ObjectType::DECOR, Type::Vector<3>(535.0f, 340.0f, 0.0f), 2);
    std::shared_ptr<StateImage> playerThree = std::make_shared<StateImage>("./assets/selectionmenu/selectionmenu.png", "perso3", GameObject::ObjectType::DECOR, Type::Vector<3>(985.0f, 340.0f, 0.0f), 2);
    std::shared_ptr<StateImage> playerFour = std::make_shared<StateImage>("./assets/selectionmenu/selectionmenu.png", "perso4", GameObject::ObjectType::DECOR, Type::Vector<3>(1435.0f, 340.0f, 0.0f), 2);
    std::shared_ptr<StateImage> arrowLeftOne = std::make_shared<StateImage>("./assets/selectionmenu/arrow_left.png", "leftArrow1", GameObject::ObjectType::DECOR, Type::Vector<3>(85.0f, 670.0f, 0.0f), 2);
    std::shared_ptr<StateImage> arrowRightOne = std::make_shared<StateImage>("./assets/selectionmenu/arrow_right.png", "rightArrow1", GameObject::ObjectType::DECOR, Type::Vector<3>(430.0f, 670.0f, 0.0f), 2);
    std::shared_ptr<StateImage> arrowLeftTwo = std::make_shared<StateImage>("./assets/selectionmenu/arrow_left.png", "leftArrow2", GameObject::ObjectType::DECOR, Type::Vector<3>(535.0f, 670.0f, 0.0f), 2);
    std::shared_ptr<StateImage> arrowRightTwo = std::make_shared<StateImage>("./assets/selectionmenu/arrow_right.png", "rightArrow2", GameObject::ObjectType::DECOR, Type::Vector<3>(880.0f, 670.0f, 0.0f), 2);
    std::shared_ptr<StateImage> arrowLeftThree = std::make_shared<StateImage>("./assets/selectionmenu/arrow_left.png", "leftArrow3", GameObject::ObjectType::DECOR, Type::Vector<3>(985.0f, 670.0f, 0.0f), 2);
    std::shared_ptr<StateImage> arrowRightThree = std::make_shared<StateImage>("./assets/selectionmenu/arrow_right.png", "rightArrow3", GameObject::ObjectType::DECOR, Type::Vector<3>(1325.0f, 670.0f, 0.0f), 2);
    std::shared_ptr<StateImage> arrowLeftFour = std::make_shared<StateImage>("./assets/selectionmenu/arrow_left.png", "leftArrow4", GameObject::ObjectType::DECOR, Type::Vector<3>(1440.0f, 670.0f, 0.0f), 2);
    std::shared_ptr<StateImage> arrowRightFour = std::make_shared<StateImage>("./assets/selectionmenu/arrow_right.png", "rightArrow4", GameObject::ObjectType::DECOR, Type::Vector<3>(1775.0f, 670.0f, 0.0f), 2);
    std::shared_ptr<StateImage> oneP = std::make_shared<StateImage>("./assets/selectionmenu/1p.png", "1p", GameObject::ObjectType::DECOR, Type::Vector<3>(100.0f, 355.0f, 0.0f), 2);
    std::shared_ptr<StateImage> twoP = std::make_shared<StateImage>("./assets/selectionmenu/2p.png", "2p", GameObject::ObjectType::DECOR, Type::Vector<3>(550.0f, 355.0f, 0.0f), 4);
    std::shared_ptr<StateImage> threeP = std::make_shared<StateImage>("./assets/selectionmenu/3p.png", "3p", GameObject::ObjectType::DECOR, Type::Vector<3>(1000.0f, 355.0f, 0.0f), 4);
    std::shared_ptr<StateImage> fourP = std::make_shared<StateImage>("./assets/selectionmenu/4p.png", "4p", GameObject::ObjectType::DECOR, Type::Vector<3>(1450.0f, 355.0f, 0.0f), 4);
    std::shared_ptr<FlashingText> _gamepadInfoOne = std::make_shared<FlashingText>("Press start", Type::Color(0, 0, 0, 255), 40, 0, "gamepadInfo1", GameObject::ObjectType::DECOR, Type::Vector<2>(610.0f, 490.0f));
    std::shared_ptr<FlashingText> _gamepadInfoTwo = std::make_shared<FlashingText>("Press start", Type::Color(0, 0, 0, 255), 40, 0, "gamepadInfo2", GameObject::ObjectType::DECOR, Type::Vector<2>(1060.0f, 490.0f));
    std::shared_ptr<FlashingText> _gamepadInfoThree = std::make_shared<FlashingText>("Press start", Type::Color(0, 0, 0, 255), 40, 0, "gamepadInfo3", GameObject::ObjectType::DECOR, Type::Vector<2>(1510.0f, 490.0f));

    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/yellow.png", "wall", GameObject::ObjectType::DECOR, Type::Vector<3>(0.0f, 0.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/bande.png", "bande", GameObject::ObjectType::DECOR, Type::Vector<3>(0.0f, 100.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/house.png", "house", GameObject::ObjectType::DECOR, Type::Vector<3>(100.0f, 110.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<FlashingText>(text, Type::Color(255, 255, 255, 255), 80, 0, "title", GameObject::ObjectType::DECOR, Type::Vector<2>(340.0f, 160.0f)));
    this->__objContainer.push_back(playerOne);
    this->__objContainer.push_back(playerTwo);
    this->__objContainer.push_back(playerThree);
    this->__objContainer.push_back(playerFour);
    this->__objContainer.push_back(arrowLeftOne);
    this->__objContainer.push_back(arrowRightOne);
    this->__objContainer.push_back(arrowLeftTwo);
    this->__objContainer.push_back(arrowRightTwo);
    this->__objContainer.push_back(arrowLeftThree);
    this->__objContainer.push_back(arrowRightThree);
    this->__objContainer.push_back(arrowLeftFour);
    this->__objContainer.push_back(arrowRightFour);
    this->__objContainer.push_back(oneP);
    this->__objContainer.push_back(twoP);
    this->__objContainer.push_back(threeP);
    this->__objContainer.push_back(fourP);
    this->__objContainer.push_back(_gamepadInfoOne);
    this->__objContainer.push_back(_gamepadInfoTwo);
    this->__objContainer.push_back(_gamepadInfoThree);

    this->__stateImagesReferer.emplace_back(playerOne);
    this->__stateImagesReferer.emplace_back(playerTwo);
    this->__stateImagesReferer.emplace_back(playerThree);
    this->__stateImagesReferer.emplace_back(playerFour);
    this->__stateImagesReferer.emplace_back(arrowLeftOne);
    this->__stateImagesReferer.emplace_back(arrowRightOne);
    this->__stateImagesReferer.emplace_back(arrowLeftTwo);
    this->__stateImagesReferer.emplace_back(arrowRightTwo);
    this->__stateImagesReferer.emplace_back(arrowLeftThree);
    this->__stateImagesReferer.emplace_back(arrowRightThree);
    this->__stateImagesReferer.emplace_back(arrowLeftFour);
    this->__stateImagesReferer.emplace_back(arrowRightFour);
    this->__stateImagesReferer.emplace_back(oneP);
    this->__stateImagesReferer.emplace_back(twoP);
    this->__stateImagesReferer.emplace_back(threeP);
    this->__stateImagesReferer.emplace_back(fourP);
    this->__flashingTextReferer.emplace_back(_gamepadInfoOne);
    this->__flashingTextReferer.emplace_back(_gamepadInfoTwo);
    this->__flashingTextReferer.emplace_back(_gamepadInfoThree);
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/bande_bot.png", "bande_bot", GameObject::ObjectType::DECOR, Type::Vector<3>(0.0f, 930.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<FlashingText>("Please select your charactere", Type::Color(255, 255, 255, 255), 50, 150, "select", GameObject::ObjectType::DECOR, Type::Vector<2>(580.0f, 970.0f)));

    loadPlayers();
}

void Bomberman::Menu::SelectionMenu::isKeyboardOrGamepad()
{
    if (_selectionPlayer == 0)
    {
        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_K)) {
            _playerInputIds = { -1, 0, 1, 2 };
        }
        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_P)) {
            _playerInputIds = { 0, 1, 2, 3 };
        }
        if (_playerInputIds[0] == -1) {
            if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_LEFT)) {
                std::cout << this->_selectedModel[0] << std::endl;
                if (this->_selectedModel[0] != 0)
                    this->_selectedModel[0]--;
            }
            if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_RIGHT)) {
                std::cout << this->_selectedModel[0] << std::endl;

                if (this->_selectedModel[0] + 1 < this->__modelsContainer.size())
                    this->_selectedModel[0]++;
            }
        } else {
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[0], RayLib::Window::LEFT)) {
                if (this->_selectedModel[0] != 0)
                    this->_selectedModel[0]--;
            }
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[0], RayLib::Window::RIGHT)) {
                if (this->_selectedModel[0] + 1 < this->__modelsContainer.size())
                    this->_selectedModel[0]++;
            }
        }

        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[1])) {
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[1],
                                                                                        RayLib::Window::LEFT)) {
                if (this->_selectedModel[1] != 0)
                    this->_selectedModel[1]--;
            }
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[1],
                                                                                        RayLib::Window::RIGHT)) {
                if (this->_selectedModel[1] + 1 < this->__modelsContainer.size())
                    this->_selectedModel[1]++;
            }
        }
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[2])) {
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[2],
                                                                                        RayLib::Window::LEFT)) {
                if (this->_selectedModel[2] != 0)
                    this->_selectedModel[2]--;
            }
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[2],
                                                                                        RayLib::Window::RIGHT)) {
                if (this->_selectedModel[2] + 1 < this->__modelsContainer.size())
                    this->_selectedModel[2]++;
            }
        }
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[3])) {
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[3],
                                                                                        RayLib::Window::LEFT)) {
                if (this->_selectedModel[3] != 0)
                    this->_selectedModel[3]--;
            }
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[3],
                                                                                        RayLib::Window::RIGHT)) {
                if (this->_selectedModel[3] + 1 < this->__modelsContainer.size())
                    this->_selectedModel[3]++;
            }
        }

        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_ENTER))
        {
            _selectionPlayer += 1;
            for (auto const &val : this->__stateImagesReferer)
            {
                if (val.lock()->getName() == "perso1" && val.lock()->getActualState() == 0)
                {
                    val.lock()->setActualState(1);
                    _isAction = true;
                }
                if (val.lock()->getName() == "1p" && val.lock()->getActualState() == 0)
                {
                    val.lock()->setActualState(1);
                }
            }
        }
    }
}

void Bomberman::Menu::SelectionMenu::ready()
{
    if (_playerInputIds[0] == -1) {
        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_ENTER))
            readySquareState();
    } else {
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[0]))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[0], RayLib::Window::XBOX::A))
                readySquareState();
    }
    if (_selectionPlayer == 1)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[1]))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[1], RayLib::Window::XBOX::A))
                readySquareState();
    if (_selectionPlayer == 2)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[2]))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[2], RayLib::Window::XBOX::A))
                readySquareState();
    if (_selectionPlayer == 3)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[3]))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[3], RayLib::Window::XBOX::A))
                readySquareState();
}

void Bomberman::Menu::SelectionMenu::readySquareState()
{

    bool plus = false;
    _readySound.PlaySound();
    for (auto const &val : this->__stateImagesReferer)
    {
        if (!_isAction)
        {
            switch (_selectionPlayer)
            {
            case 0:
                if (val.lock()->getName() == "perso1" && val.lock()->getActualState() == 0)
                    val.lock()->setActualState(1);
                if (val.lock()->getName() == "1p" && val.lock()->getActualState() == 0)
                    val.lock()->setActualState(1);
                plus = true;
                break;
            case 1:
                if (val.lock()->getName() == "perso2" && val.lock()->getActualState() == 0)
                    val.lock()->setActualState(1);
                if (val.lock()->getName() == "2p" && val.lock()->getActualState() == 2)
                    val.lock()->setActualState(3);
                if (val.lock()->getName() == "2p" && val.lock()->getActualState() == 0)
                    val.lock()->setActualState(1);
                plus = true;
                break;
            case 2:
                if (val.lock()->getName() == "perso3" && val.lock()->getActualState() == 0)
                    val.lock()->setActualState(1);
                if (val.lock()->getName() == "3p" && val.lock()->getActualState() == 2)
                    val.lock()->setActualState(3);
                if (val.lock()->getName() == "3p" && val.lock()->getActualState() == 0)
                    val.lock()->setActualState(1);
                plus = true;
                break;
            case 3:
                if (val.lock()->getName() == "perso4" && val.lock()->getActualState() == 0)
                    val.lock()->setActualState(1);
                if (val.lock()->getName() == "4p" && val.lock()->getActualState() == 2)
                    val.lock()->setActualState(3);
                if (val.lock()->getName() == "4p" && val.lock()->getActualState() == 0)
                    val.lock()->setActualState(1);
                plus = true;
                break;
            default:
                break;
            }
        }
    }
    if (plus)
    {
        if (_selectionPlayer < 4)
            _selectionPlayer++;
        plus = false;
    }
    _isAction = false;
}

void Bomberman::Menu::SelectionMenu::cancelSquareState()
{
    bool less = false;

    for (auto const &val : this->__stateImagesReferer)
    {
        switch (_selectionPlayer)
        {
        case 1:
            if (val.lock()->getName() == "perso1" && val.lock()->getActualState() == 1)
                val.lock()->setActualState(0);
            if (val.lock()->getName() == "1p" && val.lock()->getActualState() == 1)
                val.lock()->setActualState(0);
            less = true;
            break;
        case 2:
            if (val.lock()->getName() == "perso2" && val.lock()->getActualState() == 1)
                val.lock()->setActualState(0);
            if (val.lock()->getName() == "2p" && val.lock()->getActualState() == 3)
                    val.lock()->setActualState(2);
            if (val.lock()->getName() == "2p" && val.lock()->getActualState() == 1)
                val.lock()->setActualState(0);
            less = true;
            break;
        case 3:
            if (val.lock()->getName() == "perso3" && val.lock()->getActualState() == 1)
                val.lock()->setActualState(0);
            if (val.lock()->getName() == "3p" && val.lock()->getActualState() == 3)
                    val.lock()->setActualState(2);
            if (val.lock()->getName() == "3p" && val.lock()->getActualState() == 1)
                val.lock()->setActualState(0);
            less = true;
            break;
        case 4:
            if (val.lock()->getName() == "perso4" && val.lock()->getActualState() == 1)
                val.lock()->setActualState(0);
            if (val.lock()->getName() == "4p" && val.lock()->getActualState() == 3)
                    val.lock()->setActualState(2);
            if (val.lock()->getName() == "4p" && val.lock()->getActualState() == 1)
                val.lock()->setActualState(0);
            less = true;
            break;
        default:
            break;
        }
    }
    if (less && _selectionPlayer > 0)
    {
        _selectionPlayer--;
        less = false;
    }
    _isAction = false;
}


void Bomberman::Menu::SelectionMenu::cancel()
{
    if (_playerInputIds[0] == -1) {
        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_D))
            cancelSquareState();
    } else {
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[0]))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[0], RayLib::Window::XBOX::B))
                cancelSquareState();
    }
    if (_selectionPlayer == 1)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[1]))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[1], RayLib::Window::XBOX::B))
                cancelSquareState();
    if (_selectionPlayer == 2)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[2]))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[2], RayLib::Window::XBOX::B))
                cancelSquareState();
    if (_selectionPlayer == 3)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_playerInputIds[3]))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(_playerInputIds[3], RayLib::Window::XBOX::B))
                cancelSquareState();
}

void Bomberman::Menu::SelectionMenu::changeStateSelection(int gamepad, bool available)
{
    int state = 2;

    if (_playerInputIds[0] == -1)
        gamepad++;
    if (!available)
        state = 0;
    for (auto const &val : this->__flashingTextReferer)
    {
        switch (gamepad)
        {
            case 1:
                if (val.lock()->getName() == "gamepadInfo1") {
                    val.lock()->setDisplay(!available);
                    if (!val.lock()->getDisplay())
                        _selectedModel[1] = 0;
                    else
                        _selectedModel[1] = -1;
                }
                break;
            case 2:
                if (val.lock()->getName() == "gamepadInfo2") {
                    val.lock()->setDisplay(!available);
                    if (!val.lock()->getDisplay())
                        _selectedModel[2] = 0;
                    else
                        _selectedModel[2] = -1;
                }
                break;
            case 3:
                if (val.lock()->getName() == "gamepadInfo3") {
                    val.lock()->setDisplay(!available);
                    if (!val.lock()->getDisplay())
                        _selectedModel[3] = 0;
                    else
                        _selectedModel[3] = -1;
                }
                break;
        }
    }
    for (auto const &val : this->__stateImagesReferer)
    {
        switch (gamepad)
        {
            case 1:
                if (_selectionPlayer > 1 && !available)
                    state ++;
                if (val.lock()->getName() == "2p")
                    val.lock()->setActualState(state);
                if (_selectionPlayer > 1 && !available)
                    state --;
                break;
            case 2:
                if (_selectionPlayer > 2 && !available)
                    state ++;
                if (val.lock()->getName() == "3p")
                    val.lock()->setActualState(state);
                if (_selectionPlayer > 2 && !available)
                    state --;
                break;
            case 3:
                if (_selectionPlayer > 3 && !available)
                    state ++;
                if (val.lock()->getName() == "4p")
                    val.lock()->setActualState(state);
                if (_selectionPlayer > 3 && !available)
                    state --;
                break;
        }
    }
}


void Bomberman::Menu::SelectionMenu::handleGamepads(int gamepad)
{

    if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(gamepad))
    {
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(gamepad, RayLib::Window::XBOX::START))
            changeStateSelection(gamepad, true);
    }
    else if (!RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(gamepad))
        changeStateSelection(gamepad, false);
}

void Bomberman::Menu::SelectionMenu::goToGameScene()
{
    bool end = false;
    for (auto const &val : this->__stateImagesReferer)
    {
        if (val.lock()->getName() == "perso4" && val.lock()->getActualState() == 1)
            end = true;
    }
    if (end)
        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_SPACE)) {
            std::vector<std::string> playerDlls = getPlayerDlls();
            std::vector<int> playerIds = _playerInputIds;
            std::vector<int> playerIa = _selectedModel;
            __manager.clearStack<Bomberman::GameScene>(playerIds, playerIa, playerDlls[0], playerDlls[1], playerDlls[2], playerDlls[3]);
        }
}

void Bomberman::Menu::SelectionMenu::update(const double &elapsed)
{
    for (auto &model : this->__modelsContainer) {
        model->update(elapsed);
    }

    for (auto const &val : this->__objContainer) {
        val->update(elapsed);
    }
    isKeyboardOrGamepad();
    cancel();
    ready();
    for (int i = 0; i < 4; i++)
        handleGamepads(i);
    goToGameScene();
    if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_BACKSPACE))
        __manager.unloadScene();
}

void Bomberman::Menu::SelectionMenu::drawScene()
{
    for (auto const &val : this->__objContainer) {
        val->render();
    }
    RayLib::Window::getInstance().getDrawing().beginMode3D(_camera);

    this->__modelsContainer[this->_selectedModel[0]]->render();

    if (this->_selectedModel[1] != -1)
        this->__modelsContainer1[this->_selectedModel[1]]->render();
    if (this->_selectedModel[2] != -1)
        this->__modelsContainer2[this->_selectedModel[2]]->render();
    if (this->_selectedModel[3] != -1)
        this->__modelsContainer3[this->_selectedModel[3]]->render();

    RayLib::Window::getInstance().getDrawing().endMode3D();
}

void Bomberman::Menu::SelectionMenu::loadPlayers()
{
    if (!std::filesystem::is_directory(Config::ExecutablePath + "lib"))
        throw GameException("Unable to find lib folder at executable root.");
    for (auto & file : std::filesystem::directory_iterator(Config::ExecutablePath + "lib")) {
        try {
            std::unique_ptr<LibDl::DynamicLibrary> dl = std::make_unique<LibDl::DynamicLibrary>(file.path().string());
            auto fct = dl->getSym<Bomberman::AbstractPlayer *(*)(void)>("entryPoint");
            AbstractPlayer *p1 = fct();
            if (p1 == nullptr)
                throw GameException("Symbol not found entryPoint in " + file.path().string());

            std::shared_ptr<Player> player = std::make_shared<Player>(p1->getName(), Type::Vector<3>(-4.0f, -0.5f, 0.0f), p1->getSpeed(), p1->getBombs(), p1->getRange());
            std::shared_ptr<Player> player1 = std::make_shared<Player>(p1->getName(), Type::Vector<3>(-1.0f, -0.5f, 0.0f), p1->getSpeed(), p1->getBombs(), p1->getRange());
            std::shared_ptr<Player> player2 = std::make_shared<Player>(p1->getName(), Type::Vector<3>(1.5f, -0.5f, 0.0f), p1->getSpeed(), p1->getBombs(), p1->getRange());
            std::shared_ptr<Player> player3 = std::make_shared<Player>(p1->getName(), Type::Vector<3>(4.5f, -0.5f, 0.0f), p1->getSpeed(), p1->getBombs(), p1->getRange());
            player->setScale(Type::Vector<3>(p1->getScale(), p1->getScale(), p1->getScale()));
            player1->setScale(Type::Vector<3>(p1->getScale(), p1->getScale(), p1->getScale()));
            player2->setScale(Type::Vector<3>(p1->getScale(), p1->getScale(), p1->getScale()));
            player3->setScale(Type::Vector<3>(p1->getScale(), p1->getScale(), p1->getScale()));
            __modelsContainer.emplace_back(player);
            __modelsContainer1.emplace_back(player1);
            __modelsContainer2.emplace_back(player2);
            __modelsContainer3.emplace_back(player3);

        } catch (LibDl::DynamicLibraryException &e) {
            throw e;
        }
    }
}

std::vector<std::string> Bomberman::Menu::SelectionMenu::getPlayerDlls()
{
    std::vector<std::string> dlls;

    for (auto i : this->_selectedModel) {
        if (i == -1)
            i = 0;
        for (auto &file : std::filesystem::directory_iterator(Bomberman::Config::ExecutablePath + "lib")) {
            if (file.path().string().find(__modelsContainer[i]->getName()) != std::string::npos) {
                dlls.emplace_back(std::filesystem::absolute(file.path()).string());
            }
        }
    }
    return dlls;
}
