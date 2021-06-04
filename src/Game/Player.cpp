/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <RayLib/InputKeyboard.hpp>
#include "Player.hpp"
#include "GameException.hpp"

Bomberman::Player::Player(const std::string &name, const Type::Vector<3> &position, const std::string &assetPath, float speed, int bombs, int range) : GameObject(name, PLAYER, position), _range(range), _speed(speed), _bombs(bombs), _state(PlayerAnimation::IDLE), _startAnimTime(0)
{
    try {
        _animation = std::make_unique<PlayerAnimation>(assetPath, position);
    }
    catch (GameException &g) {
        throw g;
    }
}

Bomberman::Player::~Player()
{
    _animation.reset();
}

void Bomberman::Player::setRange(int range)
{
    this->_range = range;
}

int Bomberman::Player::getRange()
{
    return this->_range;
}

void Bomberman::Player::setBombs(int bombs)
{
    this->_bombs = bombs;
}

int Bomberman::Player::getBombs()
{
    return this->_bombs;
}

void Bomberman::Player::setSpeed(float speed)
{
    this->_speed = speed;
}

void Bomberman::Player::Move(const Type::Vector<3> &vector)
{
    this->setPosition(this->getPosition() + vector);
}

double Bomberman::Player::getSpeed()
{
    return this->_speed;
}

void Bomberman::Player::setScale(const Type::Vector<3> &scale)
{
    this->_animation->setScale(scale);
}

void Bomberman::Player::render() const
{
    _animation->render();
}

void Bomberman::Player::update(const double &elapsed)
{
    this->_animation->setPosition(this->getPosition());
    PlayerAnimation::PlayerState currState = this->_animation->getState();

    if (currState != PlayerAnimation::IDLE && currState != PlayerAnimation::WALKING) return;

    if (IsKeyDown(KEY_W)) {
        this->_animation->setState(PlayerAnimation::WALKING);
        this->_animation->setRotationAngle(180.0f);
        this->Move(Type::Vector<3>(0.0f, 0.0f, static_cast<float>(-_speed * elapsed)));
    }
    else if (IsKeyDown(KEY_A)) {
        this->_animation->setState(PlayerAnimation::WALKING);
        this->_animation->setRotationAngle(-90.0f);
        this->Move(Type::Vector<3>(static_cast<float>(-_speed * elapsed), 0.0f, 0.0f));
    }
    else if (IsKeyDown(KEY_S)) {
        this->_animation->setState(PlayerAnimation::WALKING);
        this->_animation->setRotationAngle(0.0f);
        this->Move(Type::Vector<3>(0.0f, 0.0f, static_cast<float>(_speed * elapsed)));
    }
    else if (IsKeyDown(KEY_D)) {
        this->_animation->setState(PlayerAnimation::WALKING);
        this->_animation->setRotationAngle(90.0f);
        this->Move(Type::Vector<3>(static_cast<float>(_speed * elapsed), 0.0f, 0.0f));
    }
    else if (IsKeyDown(KEY_E)) {
        this->_animation->setState(PlayerAnimation::ACTION);
        doAction();
    }
    else {
        this->_animation->setState(PlayerAnimation::IDLE);
    }

    this->_animation->update(elapsed);
}

void Bomberman::Player::doAction()
{
    this->_bombs--;
}
