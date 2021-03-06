/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

#include "RayLib/Model/Animate/Animate.hpp"
#include <RayLib/InputKeyboard.hpp>
#include <Game/Bomb/Bomb.hpp>
#include <memory>
#include <RayLib/Manager3D.hpp>

namespace Bomberman {
    class Player : public GameObject {
    public:
        enum PlayerState {
            IDLE,
            WALKING,
            ACTION,
            DEAD
        };
        enum Direction {
            NONE,
            LEFT,
            RIGHT,
            UP,
            DOWN
        };

        Player(const std::string &name, const Type::Vector<3> &position, bool isAi, int controller, const std::string &dllPath, float speed = 3.0f, int bombs = 1, int range = 2);
        Player(const std::string &name, const Type::Vector<3> &position, bool isAi, int controller, float speed = 3.0f, int bombs = 1, int range = 2);
        ~Player() override;

        void setRange(int range);
        int getRange();
        void setSpeed(float range);
        double getSpeed();
        void addBomb();
        void setScale(const Type::Vector<3> &scale);
        PlayerState getState();
        void setState(const PlayerState &state);
        void setRotationAngle(const double &rotationAngle);
        double getRotationAngle() const;

        void Move(const Type::Vector<3> &vector);

        void render() const override;
        void update(const double &elapsed) override;

        bool checkFreeTimer();
        void launchFreeTimer(const double &elapsed);
        void checkTimer(const double &elapsed);
        void updateCollisions(Type::Vector<3> position, int update);
        void updateDangers(Type::Vector<3> position, int range, int update);
        std::shared_ptr<Bomb> createBomb();

        inline std::string getPath() const { return (this->_dllPath); }
        inline bool getIsAi() const { return (this->_isAi); }
        inline int getController() const { return (this->_controller); }
        inline int getBombs() const { return (this->_bombs); }
        inline bool getAlive() const { return (this->_alive); }

        inline void setAlive(bool val) { this->_alive = val; }
    private:
        void _iaOrPlayer(double elapsed);
        void _playerHandler(double elapsed);
        void _playerKeyboard(double elapsed);
        void _playerGamepad(double elapsed);
        void _AiHandler(double elapsed);
        void _moveAi(double elapsed);
        void _setNewGoalOffense(double elapsed);
        void _setNewGoalDefense(double elapsed);
        bool _isSolidBlock(int x, int z);
        bool _isDangerousBox(int x, int z);
        int _range;
        float _speed;
        std::vector<double> _bombTimers;
        Type::Vector<3> _scale;
        PlayerState _state;
        double _startActionTime;
        bool _alreadyCreatedBomb;
        double _rotationAngle;
        bool _isAi;
        bool _alive;
        int _bombs;
        int _controller;
        std::string _dllPath;
        std::pair<int, int> _newGoal;
        std::pair<float, float> _goalPosition;
        std::pair<float, float> _basePosition;
        Direction _dir;
        double _wait;
        int _walls[15][15] = {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
        int _dangers[15][15] =
                {
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                };
    };
}

#endif //BOMBERMAN_PLAYER_HPP
