/**
 * @file SpriteSheetPlayer.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "SpriteSheetPlayer.hpp"

Bomberman::SpriteSheetPlayer::SpriteSheetPlayer(const std::string &pathToSheet, size_t spriteIPS, const Type::Rectangle &rect, const Type::Vector<2> &pos, const std::string &name, size_t frameNb, bool display) :
GameObject(name, GameObject::ObjectType::DECOR, Type::Vector<3>(pos.getX(), pos.getY(), 0.0f), display),
__rect(rect),
__texture(pathToSheet)
{
    this->__pathToSheet = pathToSheet;
    this->__spriteIPS = spriteIPS;
    this->__frameCounter = 0;
    this->__frameNumber = frameNb;
    this->__currentFrame = 0;
}

void Bomberman::SpriteSheetPlayer::render() const
{
    Type::Vector<2> vec(this->getPosition().getX(), this->getPosition().getY());

    this->__texture.drawTextureRec(this->__rect, vec, Type::Color(255, 255, 255, 255));
}

void Bomberman::SpriteSheetPlayer::update(const double &elapsed)
{
    float dummy = this->__spriteIPS * elapsed;

    this->__frameCounter++;
    if (this->__frameCounter > (RayLib::Window::getInstance().getRefreshRate() / dummy)) {
        std::cout << "DEBUG" << std::endl;
        this->__frameCounter = 0;
        this->__currentFrame++;

        float &x = this->__rect.getX();
        float &y = this->__rect.getY();

        if (this->__currentFrame > this->__frameNumber) {
            x = 0.0f;
            y = 0.0f;
        }
        x += this->__rect.getWidth();
        if (x >= this->__texture.getWidth()) {
            y += this->__rect.getHeight();
            x = 0.0f;
        }
    }
}