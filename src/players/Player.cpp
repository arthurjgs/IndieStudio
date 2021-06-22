/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <RayLib/Window.hpp>
#include "Player.hpp"

Bomberman::Player::Player(const std::string &name, const Type::Vector<3> &position, bool isAi, int controller, const std::string &dllPath, float speed, int bombs, int range) : GameObject(name, PLAYER, position),
_isAi(isAi),
_controller(controller),
_range(range),
_speed(speed),
_state(IDLE),
_startActionTime(0),
_alreadyCreatedBomb(false),
_rotationAngle(0)
{
    _wait = 0;
    _dir = NONE;
    try {
        for (int i = 0; i < bombs; i++)
            _bombTimers.emplace_back(0);
    }
    catch (GameException &g) {
        throw g;
    }
    this->_dllPath = dllPath;
    this->_bombs = bombs;
    this->_alive = true;
}

Bomberman::Player::Player(const std::string &name, const Type::Vector<3> &position, bool isAi, int controller, float speed, int bombs, int range) : GameObject(name, PLAYER, position),
_isAi(isAi),
_controller(controller),
_range(range),
_speed(speed),
_state(IDLE),
_startActionTime(0),
_alreadyCreatedBomb(false),
_rotationAngle(0)
{
    _wait = 0;
    _dir = NONE;
    try {
        for (int i = 0; i < bombs; i++)
            _bombTimers.emplace_back(0);
    }
    catch (GameException &g) {
        throw g;
    }
    this->_bombs = bombs;
    this->_alive = true;
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

void Bomberman::Player::updateCollisions(Type::Vector<3> position, int update)
{
    _walls[static_cast<int>(position.getZ()) + 7][static_cast<int>(position.getX()) + 7] = update;
}

void Bomberman::Player::updateDangers(Type::Vector<3> position, int range, int update)
{
    _dangers[static_cast<int>(position.getZ()) + 7][static_cast<int>(position.getX()) + 7] = 1;
    for (int i = 0; i < range; i++)
    {
        if (static_cast<int>(position.getZ()) + 7 + (i + 1) < 15)
            _dangers[static_cast<int>(position.getZ()) + 7 + (i + 1)][static_cast<int>(position.getX()) + 7] = update;
        if (static_cast<int>(position.getZ()) + 7 - (i + 1) > 0)
            _dangers[static_cast<int>(position.getZ()) + 7 - (i + 1)][static_cast<int>(position.getX()) + 7] = update;
        if (static_cast<int>(position.getX()) + 7 + (i + 1) < 15)
            _dangers[static_cast<int>(position.getZ()) + 7][static_cast<int>(position.getX()) + 7 + (i + 1)] = update;
        if (static_cast<int>(position.getX()) + 7 + (i + 1) > 0)
            _dangers[static_cast<int>(position.getZ()) + 7][static_cast<int>(position.getX()) + 7 - (i + 1)] = update;
    }
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
    Type::Vector<3> roundedPosition;
    if (_rotationAngle == 0)
        roundedPosition = Type::Vector<3>(static_cast<float>(round(position.getX())),
                                          static_cast<float>(round(position.getY())),
                                          static_cast<float>(round(position.getZ() + 1)));
    else if (_rotationAngle == 180)
        roundedPosition = Type::Vector<3>(static_cast<float>(round(position.getX())),
                                          static_cast<float>(round(position.getY())),
                                          static_cast<float>(round(position.getZ() - 1)));
    else if (_rotationAngle == 90)
        roundedPosition = Type::Vector<3>(static_cast<float>(round(position.getX() + 1)),
                                          static_cast<float>(round(position.getY())),
                                          static_cast<float>(round(position.getZ())));
    else if (_rotationAngle == -90)
        roundedPosition = Type::Vector<3>(static_cast<float>(round(position.getX()) - 1),
                                          static_cast<float>(round(position.getY())),
                                          static_cast<float>(round(position.getZ())));
    return std::make_shared<Bomb>(roundedPosition, this, this->getRange());
}

void Bomberman::Player::_playerKeyboard(double elapsed)
{
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

void Bomberman::Player::_playerGamepad(double elapsed)
{
    if (RayLib::Window::getInstance().getInputGamepad().isGamepadAvailable(_controller)) {
        if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonDown(_controller, RayLib::Window::XBOX::UP)) {
            this->setState(WALKING);
            this->setRotationAngle(180.0f);
            this->Move(Type::Vector<3>(0.0f, 0.0f, static_cast<float>(-_speed * elapsed)));
        }
        else if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonDown(_controller, RayLib::Window::XBOX::LEFT)) {
            this->setState(WALKING);
            this->setRotationAngle(-90.0f);
            this->Move(Type::Vector<3>(static_cast<float>(-_speed * elapsed), 0.0f, 0.0f));
        }
        else if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonDown(_controller, RayLib::Window::XBOX::DOWN)) {
            this->setState(WALKING);
            this->setRotationAngle(0.0f);
            this->Move(Type::Vector<3>(0.0f, 0.0f, static_cast<float>(_speed * elapsed)));
        }
        else if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonDown(_controller, RayLib::Window::XBOX::RIGHT)) {
            this->setState(WALKING);
            this->setRotationAngle(90.0f);
            this->Move(Type::Vector<3>(static_cast<float>(_speed * elapsed), 0.0f, 0.0f));
        }
        else if (RayLib::Window::getInstance().getInputGamepad().isGamepadButtonPressed(_controller, RayLib::Window::XBOX::A)) {
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
}

void Bomberman::Player::_playerHandler(double elapsed)
{
    if (_controller == -2)
        return;
    if (_controller == -1) {
        _playerKeyboard(elapsed);
    }
    else {
        _playerGamepad(elapsed);
    }
}

void Bomberman::Player::_AiHandler(double elapsed)
{
    if (_dir == NONE)
    {
        if (_dangers[static_cast<int>(floor(this->_position.getZ() + 7))][static_cast<int>(floor(this->_position.getX() + 7))] == 0)
            _setNewGoalOffense(elapsed);
    }
    if (_dir != NONE)
        _moveAi(elapsed);
}

void Bomberman::Player::_moveAi(double elapsed)
{
    if (_dir == LEFT)
    {
        this->setState(WALKING);
        this->setRotationAngle(-90.0f);
        this->Move(Type::Vector<3>(static_cast<float>(-_speed * elapsed / 2), 0.0f, 0.0f));
        if (this->_position.getX() <= _goalPosition.first)
        {
            _dir = NONE;
            float &x_less = this->_position.getX();
            x_less = _goalPosition.first;
        }
    }
    if (_dir == RIGHT)
    {
        this->setState(WALKING);
        this->setRotationAngle(90.0f);
        this->Move(Type::Vector<3>(static_cast<float>(_speed * elapsed / 2), 0.0f, 0.0f));
        if (this->_position.getX() >= _goalPosition.first)
        {
            _dir = NONE;
            float &x_plus = this->_position.getX();
            x_plus = _goalPosition.first;
        }
    }
    if (_dir == UP)
    {
        this->setState(WALKING);
        this->setRotationAngle(180.0f);
        this->Move(Type::Vector<3>(0.0f, 0.0f, static_cast<float>(-_speed * elapsed / 2)));
        if (this->_position.getZ() <= _goalPosition.second)
        {
            _dir = NONE;
            float &z_less = this->_position.getZ();
            z_less = _goalPosition.second;
        }
    }
    if (_dir == DOWN)
    {
        this->setState(WALKING);
        this->setRotationAngle(0.0f);
        this->Move(Type::Vector<3>(0.0f, 0.0f, static_cast<float>(_speed * elapsed / 2)));
        if (this->_position.getZ() >= _goalPosition.second)
        {
            _dir = NONE;
            float &z_plus = this->_position.getZ();
            z_plus = _goalPosition.second;
        }
    }
}

void Bomberman::Player::_setNewGoalOffense(double elapsed)
{
    int random = rand() % 4;
    switch (random)
    {
    case 0:
        if (!_isSolidBlock(-1, 0) && !_isDangerousBox(-1, 0))
        {
            _dir = LEFT;
            _goalPosition.first = this->_position.getX() - 1.0f;
            _goalPosition.second = this->_position.getZ();
            _basePosition.first = this->_position.getX();
            _basePosition.second = this->_position.getZ();
        }
        break;
    case 1:
        if (!_isSolidBlock(1, 0) && !_isDangerousBox(1, 0))
        {
            _dir = RIGHT;
            _goalPosition.first = this->_position.getX() + 1.0f;
            _goalPosition.second = this->_position.getZ();
            _basePosition.first = this->_position.getX();
            _basePosition.second = this->_position.getZ();
        }
        break;
    case 2:
        if (!_isSolidBlock(0, -1) && !_isDangerousBox(0, -1))
        {
            _dir = UP;
            _goalPosition.first = this->_position.getX();
            _goalPosition.second = this->_position.getZ() - 1.0f;
            _basePosition.first = this->_position.getX();
            _basePosition.second = this->_position.getZ();
        }
        break;
    case 3:
        if (!_isSolidBlock(0, 1) && !_isDangerousBox(0, 1))
        {
            _dir = DOWN;
            _goalPosition.first = this->_position.getX();
            _goalPosition.second = this->_position.getZ() + 1.0f;
            _basePosition.first = this->_position.getX();
            _basePosition.second = this->_position.getZ();
        }
        break;
    }
}

void Bomberman::Player::_setNewGoalDefense(double elapsed)
{
    int random = rand() % 4;
    switch (random)
    {
    case 0:
        if (!_isSolidBlock(-1, 0))
        {
            _dir = LEFT;
            _goalPosition.first = this->_position.getX() - 1.0f;
            _goalPosition.second = this->_position.getZ();
            _basePosition.first = this->_position.getX();
            _basePosition.second = this->_position.getZ();
        }
        break;
    case 1:
        if (!_isSolidBlock(1, 0))
        {
            _dir = RIGHT;
            _goalPosition.first = this->_position.getX() + 1.0f;
            _goalPosition.second = this->_position.getZ();
            _basePosition.first = this->_position.getX();
            _basePosition.second = this->_position.getZ();
        }
        break;
    case 2:
        if (!_isSolidBlock(0, -1))
        {
            _dir = UP;
            _goalPosition.first = this->_position.getX();
            _goalPosition.second = this->_position.getZ() - 1.0f;
            _basePosition.first = this->_position.getX();
            _basePosition.second = this->_position.getZ();
        }
        break;
    case 3:
        if (!_isSolidBlock(0, 1))
        {
            _dir = DOWN;
            _goalPosition.first = this->_position.getX();
            _goalPosition.second = this->_position.getZ() + 1.0f;
            _basePosition.first = this->_position.getX();
            _basePosition.second = this->_position.getZ();
        }
        break;
    }
}

bool Bomberman::Player::_isSolidBlock(int x, int z)
{
    if (_walls[static_cast<int>(floor(this->_position.getZ() + 7)) + z][static_cast<int>(floor(this->_position.getX() + 7)) + x] == 1)
        return true;
    return false;
}

bool Bomberman::Player::_isDangerousBox(int x, int z)
{
    if (_dangers[static_cast<int>(floor(this->_position.getZ() + 7)) + z][static_cast<int>(floor(this->_position.getX() + 7)) + x] == 1)
        return true;
    return false;
}

void Bomberman::Player::_iaOrPlayer(double elapsed)
{

    if (_isAi)
        if (_wait > 6)
            _AiHandler(elapsed);
    if (!_isAi)
        _playerHandler(elapsed);
}

void Bomberman::Player::update(const double &elapsed)
{
    auto currState = this->getState();
    checkTimer(elapsed);
    _wait += elapsed;

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
            RayLib::Manager3D::getInstance().getModel(_name + "IDLE")->update(elapsed / 10);
            break;
        case WALKING:
            RayLib::Manager3D::getInstance().getModel(_name + "WALKING")->update(elapsed/ 10);
            break;
        case ACTION:
            RayLib::Manager3D::getInstance().getModel(_name + "ACTION")->update(elapsed / 10);
            break;
        case DEAD:
            RayLib::Manager3D::getInstance().getModel(_name + "DEAD")->update(elapsed / 10);
            break;
    }

    if (currState != IDLE && currState != WALKING) return;

    _iaOrPlayer(elapsed);
}

void Bomberman::Player::setState(const PlayerState &state)
{
    this->_state = state;
}

void Bomberman::Player::setRotationAngle(const double &rotationAngle)
{
    this->_rotationAngle = rotationAngle;
}

double Bomberman::Player::getRotationAngle() const
{
    return this->_rotationAngle;
}

void Bomberman::Player::addBomb()
{
    _bombTimers.emplace_back(0);
}

