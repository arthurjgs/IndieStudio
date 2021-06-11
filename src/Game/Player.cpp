/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include "Player.hpp"

Bomberman::Player::Player(const std::string &name, const Type::Vector<3> &position, float speed, int bombs, int range) : GameObject(name, PLAYER, position),
_range(range),
_speed(speed),
_startActionTime(0),
_alreadyCreatedBomb(false)
{
    try {
        for (int i = 0; i < bombs; i++)
            _bombTimers.emplace_back(0);
    }
    catch (GameException &g) {
        throw g;
    }
}

Bomberman::Player::~Player() = default;

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
    this->_scale = scale;
}

Bomberman::Player::PlayerState Bomberman::Player::getState()
{
    return this->_state;
}

void Bomberman::Player::render() const
{
    std::weak_ptr<RayLib::Models::Animate> model;
    switch (_state) {
        case IDLE:
            model = RayLib::Manager3D::getInstance().getModel(_name + "IDLE");
            break;
        case WALKING:
            model = RayLib::Manager3D::getInstance().getModel(_name + "WALKING");
            break;
        case ACTION:
            model = RayLib::Manager3D::getInstance().getModel(_name + "ACTION");
            break;
        case DEAD:
            model = RayLib::Manager3D::getInstance().getModel(_name + "DEAD");
            break;
    }
    model.lock()->render(this->getPosition(), this->_rotationAngle, this->_scale, Type::Vector<3>(0.0f, 1.0f, 0.0f));
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
    Type::Vector<3> position = this->getPosition();
    Type::Vector<3> roundedPosition(round(position.getX()), round(position.getY()), round(position.getZ()));
    return std::make_shared<Bomb>(roundedPosition, this->getRange());
}

void Bomberman::Player::update(const double &elapsed)
{
    auto currState = this->getState();
    checkTimer(elapsed);

    if (currState == ACTION) {
        _startActionTime += elapsed;
        if (_startActionTime >= 0.5f) {
            _startActionTime = 0;
            _alreadyCreatedBomb = false;
            this->setState(IDLE);
        }
    }

    switch (_state) {
        case IDLE:
            RayLib::Manager3D::getInstance().getModel(_name + "IDLE")->update(elapsed);
            break;
        case WALKING:
            RayLib::Manager3D::getInstance().getModel(_name + "WALKING")->update(elapsed);
            break;
        case ACTION:
            RayLib::Manager3D::getInstance().getModel(_name + "ACTION")->update(elapsed);
            break;
        case DEAD:
            RayLib::Manager3D::getInstance().getModel(_name + "DEAD")->update(elapsed);
            break;
    }

    if (currState != IDLE && currState != WALKING) return;

    if (IsKeyDown(KEY_W)) {
        this->setState(WALKING);
        this->setRotationAngle(180.0f);
        this->Move(Type::Vector<3>(0.0f, 0.0f, static_cast<float>(-_speed * elapsed)));
    }
    else if (IsKeyDown(KEY_A)) {
        this->setState(WALKING);
        this->setRotationAngle(-90.0f);
        this->Move(Type::Vector<3>(static_cast<float>(-_speed * elapsed), 0.0f, 0.0f));
    }
    else if (IsKeyDown(KEY_S)) {
        this->setState(WALKING);
        this->setRotationAngle(0.0f);
        this->Move(Type::Vector<3>(0.0f, 0.0f, static_cast<float>(_speed * elapsed)));
    }
    else if (IsKeyDown(KEY_D)) {
        this->setState(WALKING);
        this->setRotationAngle(90.0f);
        this->Move(Type::Vector<3>(static_cast<float>(_speed * elapsed), 0.0f, 0.0f));
    }
    else if (IsKeyDown(KEY_E)) {
        if (!checkFreeTimer())
            return;
        this->setState(ACTION);
        launchFreeTimer(elapsed);
        _startActionTime += elapsed;
    }
    else {
        this->setState(IDLE);
    }
}

void Bomberman::Player::setState(const PlayerState &state)
{
    this->_state = state;
}

void Bomberman::Player::setRotationAngle(const double &rotationAngle)
{
    this->_rotationAngle = rotationAngle;
}

