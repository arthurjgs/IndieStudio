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
    std::shared_ptr<FlashingText> _gamepadInfoOne = std::make_shared<FlashingText>("Press any button", Type::Color(0, 0, 0, 255), 40, 0, "gamepadInfo1", GameObject::ObjectType::DECOR, Type::Vector<2>(550.0f, 470.0f));
    std::shared_ptr<FlashingText> _gamepadInfoTwo = std::make_shared<FlashingText>("Press any button", Type::Color(0, 0, 0, 255), 40, 0, "gamepadInfo2", GameObject::ObjectType::DECOR, Type::Vector<2>(1000.0f, 470.0f));
    std::shared_ptr<FlashingText> _gamepadInfoThree = std::make_shared<FlashingText>("Press any button", Type::Color(0, 0, 0, 255), 40, 0, "gamepadInfo3", GameObject::ObjectType::DECOR, Type::Vector<2>(1450.0f, 470.0f));

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
}

void Bomberman::Menu::SelectionMenu::isKeyboardOrGamepad()
{
    if (_selectionPlayer == 0)
    {
        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_K))
            _firstPlayerGamepad = false;
        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_P))
            _firstPlayerGamepad = true;
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
    if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_ENTER))
        readySquareState();
    if (_firstPlayerGamepad)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(0))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
                readySquareState();
    if (_selectionPlayer == 1)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(1))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
                readySquareState();
    if (_selectionPlayer == 2)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(2))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(2, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
                readySquareState();
    if (_selectionPlayer == 3)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(3))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(3, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
                readySquareState();
}

void Bomberman::Menu::SelectionMenu::readySquareState()
{
    bool plus = false;
    for (auto const &val : this->__stateImagesReferer)
    {
        if (!_isAction)
        {
            switch (_selectionPlayer)
            {
            case 0:
                if (val.lock()->getName() == "perso1" && val.lock()->getActualState() == 0)
                {
                    val.lock()->setActualState(1);
                }
                if (val.lock()->getName() == "1p" && val.lock()->getActualState() == 0)
                {
                    val.lock()->setActualState(1);
                }
                plus = true;
                // if (_selectionPlayer < 0)
                    //TODO Revenir à la scène d'avant;
                break;
            case 1:
                if (val.lock()->getName() == "perso2" && val.lock()->getActualState() == 0)
                {
                    val.lock()->setActualState(1);
                }
                plus = true;
                break;
            case 2:
                if (val.lock()->getName() == "perso3" && val.lock()->getActualState() == 0)
                {
                    val.lock()->setActualState(1);
                }
                plus = true;
                break;
            case 3:
                if (val.lock()->getName() == "perso4" && val.lock()->getActualState() == 0)
                {
                    val.lock()->setActualState(1);
                }
                plus = true;
                break;
            default:
                break;
            }
        }
    }
    if (plus)
    {
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
            {
                val.lock()->setActualState(0);
                less = true;
            }
            if (val.lock()->getName() == "1p" && val.lock()->getActualState() == 1)
            {
                val.lock()->setActualState(0);
                less = true;
            }
            // if (_selectionPlayer == 0)
                //TODO Revenir à la scène d'avant;
            break;
        case 2:
            if (val.lock()->getName() == "perso2" && val.lock()->getActualState() == 1)
            {
                val.lock()->setActualState(0);
                less = true;
            }
            break;
        case 3:
            if (val.lock()->getName() == "perso3" && val.lock()->getActualState() == 1)
            {
                val.lock()->setActualState(0);
                less = true;
            }
            break;
        case 4:
            std::cout << "LA CEST BIZARRE" << std::endl;
            if (val.lock()->getName() == "perso4" && val.lock()->getActualState() == 1)
            {
                val.lock()->setActualState(0);
                less = true;
            }
            break;
        default:
            break;
        }
    }
    if (less)
    {
        _selectionPlayer--;
        less = false;
    }
    _isAction = false;
}


void Bomberman::Menu::SelectionMenu::cancel()
{
    if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_D))
    {
        cancelSquareState();
        std::cout << "LA CEST BON" << std::endl;
    }
    if (_firstPlayerGamepad)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(0))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT))
                cancelSquareState();
    if (_selectionPlayer == 1)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(1))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(1, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT))
                cancelSquareState();
    if (_selectionPlayer == 2)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(2))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(2, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT))
                cancelSquareState();
    if (_selectionPlayer == 3)
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(3))
            if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonReleased(3, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT))
                cancelSquareState();       
}

void Bomberman::Menu::SelectionMenu::update(const double &elapsed)
{
    for (auto const &val : this->__objContainer) {
        val->update(elapsed);
    }
    isKeyboardOrGamepad();
    cancel();
    ready();
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
