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
    this->__objContainer.push_back(std::make_shared<Image>("./assets/selectionmenu/bande_bot.png", "bande_bot", GameObject::ObjectType::DECOR, Type::Vector<3>(0.0f, 930.0f, 0.0f)));
    this->__objContainer.push_back(std::make_shared<FlashingText>("Please select your charactere", Type::Color(255, 255, 255, 255), 50, 150, "select", GameObject::ObjectType::DECOR, Type::Vector<2>(580.0f, 970.0f)));
}

void Bomberman::Menu::SelectionMenu::update(const double &elapsed)
{
    for (auto const &val : this->__objContainer) {
        val->update(elapsed);
    }
    if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(KEY_SPACE))
    {
        for (auto const &val : this->__stateImagesReferer)
        {
            std::cout << std::endl << val.lock()->getName() << std::endl;
            if (val.lock()->getName() == "leftArrow1" && val.lock()->getActualState() == 0)
                val.lock()->setActualState(1);
            else if(val.lock()->getName() == "leftArrow1" && val.lock()->getActualState() == 1)
                val.lock()->setActualState(0);
        }
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
