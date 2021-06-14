/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include "Player.hpp"

Bomberman::Player::Player(const std::string &name, const Type::Vector<3> &position, const std::string &assetPath, float speed, int bombs, int range) : GameObject(name, PLAYER, position), _range(range), _speed(speed), _startActionTime(0), _alreadyCreatedBomb(false)
{
    try {
        _animation = std::make_unique<PlayerAnimation>(assetPath, position);
        for (int i = 0; i < bombs; i++)
            _bombTimers.emplace_back(0);
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

bool Bomberman::Player::checkFreeTimer()
{
    return std::any_of(_bombTimers.begin(), _bombTimers.end(), [](double t){ return t == 0.0; });
}

void Bomberman::Player::checkTimer(const double &elapsed)
{
    for (auto & timer : _bombTimers) {
        if (timer == 0)
            continue;
        else if (timer < 3)
            timer += elapsed;
        else
            timer = 0;
    }
}

void Bomberman::Player::launchFreeTimer(const double &elapsed)
{
    for (auto & timer : _bombTimers) {
        if (timer == 0) {
            timer += elapsed;
            return;
        }
    }
}

std::shared_ptr<Bomberman::Bomb> Bomberman::Player::createBomb()
{
    if (_alreadyCreatedBomb)
        return nullptr;
    _alreadyCreatedBomb = true;
    return std::make_shared<Bomb>("assets/models/bomb", this->getPosition(), GetTime(), this->getRange());
}

void Bomberman::Player::update(const double &elapsed)
{
    this->_animation->setPosition(this->getPosition());
    PlayerAnimation::PlayerState currState = this->_animation->getState();

    checkTimer(elapsed);

    if (currState == PlayerAnimation::ACTION) {
        _startActionTime += elapsed;
        if (_startActionTime >= 0.5f) {
            _startActionTime = 0;
            _alreadyCreatedBomb = false;
            this->_animation->setState(PlayerAnimation::IDLE);
        }
    }

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
        if (!checkFreeTimer())
            return;
        this->_animation->setState(PlayerAnimation::ACTION);
        launchFreeTimer(elapsed);
        _startActionTime += elapsed;
    }
    else {
        this->_animation->setState(PlayerAnimation::IDLE);
    }

    this->_animation->update(elapsed);
}

Bomberman::PlayerAnimation::PlayerState Bomberman::Player::getState()
{
    return this->_animation->getState();
}
