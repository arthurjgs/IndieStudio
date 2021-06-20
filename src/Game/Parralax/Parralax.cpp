/**
 * @file Parralax.cpp
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Parralax.hpp"

Bomberman::ParralaxMember::ParralaxMember(const std::pair<const std::string, const double> pairData, const Type::Vector<2> &position) :
__textOne(pairData.first),
__textTwo(pairData.first),
__positionOne(position),
__positionTwo(static_cast<float>(__textOne.getWidth()), position.getY())
{
    this->__speed = pairData.second;
}

Bomberman::ParralaxMember &Bomberman::ParralaxMember::operator = (const ParralaxMember &&cpy)
{
    this->__textOne = cpy.__textOne;
    this->__textTwo = cpy.__textTwo;
    this->__positionOne = cpy.__positionOne;
    this->__positionOne = cpy.__positionTwo;
    this->__speed = cpy.__speed;
    return (*this);
}

Bomberman::ParralaxMember::ParralaxMember(const ParralaxMember &&cpy) :
__textOne(cpy.__textOne),
__textTwo(cpy.__textTwo),
__positionOne(cpy.__positionOne),
__positionTwo(cpy.__positionTwo)
{
    this->__speed = cpy.__speed;
}

void Bomberman::ParralaxMember::drawTextures() const
{
    this->__textOne.drawTextureV(this->__positionOne, Type::Color(255, 255, 255, 255));
    this->__textTwo.drawTextureV(this->__positionTwo, Type::Color(255, 255, 255, 255));
}

void Bomberman::ParralaxMember::update(const double &elapsed)
{
    const double speed = this->__speed * elapsed;

    float &textOneX = this->__positionOne.getX();
    float &textTwoX = this->__positionTwo.getX();

    textOneX -= speed;
    textTwoX -= speed;

    if (textOneX < -this->__textOne.getWidth()) {
        textOneX = this->__textOne.getWidth();
    }
    if (textTwoX < -this->__textOne.getWidth()) {
        textTwoX = this->__textOne.getWidth();
    }
}

Bomberman::Parralax::Parralax(const std::pair<const std::string, const double> *pathArr, const size_t &arrSize, const std::string &name, const Type::Vector<2> &position, bool display) :
GameObject(name, GameObject::ObjectType::DECOR, Type::Vector<3>(position.getX(), position.getY(), 0.0f), display)
{
    this->__arrSize = arrSize;
    for (size_t i = 0; i < this->__arrSize; i++) {
        this->__container.push_back(ParralaxMember(pathArr[i], position));
    }
}

void Bomberman::Parralax::render() const
{
    for (auto const &val : this->__container) {
        val.drawTextures();
    }
}

void Bomberman::Parralax::update(const double &elapsed)
{
    for (auto &val : this->__container) {
        val.update(elapsed);
    }
}
