/**
 * @file Credits.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Credits.hpp"
#include "../../../RayLib/Window.hpp"
#include <string>
#include <memory>
#include <Game/Config.hpp>

Bomberman::Menu::CreditsComponent::CreditsComponent(const std::string &imgPath, const std::vector<std::string> &textVec) :
__img(imgPath, "image", GameObject::ObjectType::DECOR, Type::Vector<3>(650.0f, 200.0f, 0.0f))
{
    float yOffset = 600.0f;
    int index = 0;

    for (auto const &val : textVec) {
        this->__textVec.push_back(std::make_unique<FlashingText>(val, Type::Color(255, 255, 255, 255), 65, 0, std::to_string(index), GameObject::ObjectType::DECOR, Type::Vector<2>(350.0f, yOffset)));
        index++;
    }
    this->__speedContainer = 0.0f;
}

bool Bomberman::Menu::CreditsComponent::updateTextVec(double speed)
{
    this->__speedContainer += speed;

    Type::Color &col = this->__img.getColor();
    uChar &a = col.getA();

    if (this->__speedContainer >= 1.0f) {
        a -=  this->__speedContainer;
    }
    for (auto const &val : this->__textVec) {
        Type::Color &col_text = val->getColor();
        uChar &a_text = col_text.getA();
        if (this->__speedContainer >= 1.0f) {
            a_text -= this->__speedContainer;
        }
    }
    if (this->__speedContainer >= 1.0f) {
        this->__speedContainer = 0.0f;
    }
    if (a == 0) {
        return (true);
    }
    return (false);
}

void Bomberman::Menu::CreditsComponent::draw() const
{
    this->__img.render();
    for (auto const &val : this->__textVec) {
        val->render();
    }
}

Bomberman::Menu::Credits::Credits(SceneManager &manager) : Scene(manager)
{
    this->__objContainer.emplace_back(std::make_unique<Image>(Bomberman::Config::ExecutablePath + "assets/MainMenu/credits_back.png", "background", GameObject::ObjectType::DECOR, Type::Vector<3>(0.0f, 0.0f, 0.0f)));
    this->__textIndex = 0;

    std::vector<std::string> textSetOne;
    textSetOne.push_back("The team behind the Bomberman game !");

    std::vector<std::string> textSetTwo;
    textSetTwo.push_back("Arthur Junges");

    std::vector<std::string> textSetThree;
    textSetThree.push_back("Alexandre Burger");

    std::vector<std::string> textSetFour;
    textSetFour.push_back("Maxime Saidi");

    std::vector<std::string> textSetFive;
    textSetFive.push_back("Mehdi Meknaci");

    std::vector<std::string> textSetSix;
    textSetSix.push_back("Théo Grosjean");

    std::vector<std::string> textSetSeven;
    textSetSeven.push_back("Virgile Agnel");

    this->__textVector.emplace_back(0, std::make_unique<CreditsComponent>(Bomberman::Config::ExecutablePath + "assets/MainMenu/lobby.png", textSetOne));
    this->__textVector.emplace_back(1, std::make_unique<CreditsComponent>("", textSetTwo));
    this->__textVector.emplace_back(2, std::make_unique<CreditsComponent>("", textSetThree));
    this->__textVector.emplace_back(3, std::make_unique<CreditsComponent>("", textSetFour));
    this->__textVector.emplace_back(4, std::make_unique<CreditsComponent>("", textSetFive));
    this->__textVector.emplace_back(5, std::make_unique<CreditsComponent>("", textSetSix));
    this->__textVector.emplace_back(6, std::make_unique<CreditsComponent>("", textSetSeven));
}

void Bomberman::Menu::Credits::update(const double &elapsed)
{
    RayLib::Window &win = RayLib::Window::getInstance();

    // TODO: HANDLE RETURN WITH CONTROLLER
    if (win.getInputKeyboard().isKeyPressed(::KEY_BACKSPACE) || RayLib::Window::getInstance().getInputGamepad().isGamepadButtonPressed(0, RayLib::Window::B)) {
        this->__manager.unloadScene();
        return;
    }
    for (auto const &val : this->__objContainer) {
        val->update(elapsed);
    }
    for (auto const &val : this->__textVector) {
        if (val.first == this->__textIndex) {
            if (val.second->updateTextVec(SPEED * elapsed) == true) {
                this->__textIndex++;
                if ((size_t)this->__textIndex == this->__textVector.size()) {
                    this->__manager.unloadScene();
                    return;
                }
                break;
            }
        }
    }
}

void Bomberman::Menu::Credits::drawScene()
{
    for (auto const &val : this->__objContainer) {
        if (val->getDisplay()) {
            val->render();
        }
    }
    for (auto const &val : this->__textVector) {
        if (val.first == this->__textIndex) {
            std::cout << "drawing " << val.first << " index is :  " << this->__textIndex << std::endl;
            val.second->draw();
            break;
        }
    }
}