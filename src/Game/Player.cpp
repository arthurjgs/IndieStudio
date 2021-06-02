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
    _animation->setScale(Type::Vector<3>(12.0f, 12.0f, 12.0f));
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

void Bomberman::Player::setSpeed(int speed)
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
    _animation->render(this->_state, this->getPosition());
}

void Bomberman::Player::update(const double &elapsed)
{
    if (this->_state == PlayerAnimation::ACTION) {
        if (elapsed - this->_startAnimTime >= 0.5) {
            this->_state = PlayerAnimation::IDLE;
            this->_startAnimTime = 0;
            this->_animation->resetAnimations();
        }
    }

    if (this->_state != PlayerAnimation::IDLE
    && this->_state != PlayerAnimation::WALKING) return;

    if (IsKeyDown(KEY_W)) {
        this->_state = PlayerAnimation::WALKING;
        this->Move(Type::Vector<3>(0.0f, 0.0f, -_speed));
    }
    else if (IsKeyDown(KEY_A)) {
        this->_state = PlayerAnimation::WALKING;
        this->Move(Type::Vector<3>(-_speed, 0.0f, 0.0f));
    }
    else if (IsKeyDown(KEY_S)) {
        this->_state = PlayerAnimation::WALKING;
        this->Move(Type::Vector<3>(0.0f, 0.0f, _speed));
    }
    else if (IsKeyDown(KEY_D)) {
        this->_state = PlayerAnimation::WALKING;
        this->Move(Type::Vector<3>(_speed, 0.0f, 0.0f));
    }
    else if (IsKeyDown(KEY_E)) {
        this->_state = PlayerAnimation::ACTION;
        this->_startAnimTime = elapsed;
        doAction();
    }
    else {
        this->_state = PlayerAnimation::IDLE;
    }
}

void Bomberman::Player::doAction()
{
    this->_bombs--;
}
