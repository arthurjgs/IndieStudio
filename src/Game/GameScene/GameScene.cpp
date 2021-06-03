/**
 * @file TestScene.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "GameScene.hpp"
#include <cmath>
#include <RayLib/Window.hpp>
#include <RayLib/Model/Collision/Collision.hpp>


Bomberman::GameScene::GameScene(SceneManager &manager,
                                const std::string &playerDll1, const std::string &playerDll2,
                                const std::string &playerDll3, const std::string &playerDll4) : Scene(manager), _camera(
                                        Type::Vector<3>(0.0f, 40.0f, 27.5f),
                                        Type::Vector<3>(0.0f, 0.0f, 0.0f),
                                                Type::Vector<3>(0.0f, 1.0f, 0.0f),
                                                        20.0f,
                                        CAMERA_PERSPECTIVE), _background("assets/map/default/bg.png", "Background", GameObject::DECOR, Type::Vector<3>(0.0f, 0.0f, 0.0f))
{
    this->_listPlayers[0] = std::make_unique<Player>("Player1", Type::Vector<3>(-7.0f, 0.0f, -7.0f), "assets/models/bomberman");
    this->_gameMap = std::make_unique<Bomberman::Map>("assets/map/default", Type::Vector<3>(-8.0f, 0.0f, -8.0f));
}

bool Bomberman::GameScene::checkColision(int playerIndex) const
{
    Type::Vector<2> playerPos = { _listPlayers[playerIndex]->getPosition().getX(), _listPlayers[playerIndex]->getPosition().getZ() };
    Type::Vector<2> cubicMap = this->_gameMap->getCubicMap();
    int cubicMapX = static_cast<int>(cubicMap.getX());
    int cubicMapY = static_cast<int>(cubicMap.getY());
    float playerRadius = 0.3f;
    std::vector<Type::Color> mapPixels = _gameMap->getMapPixels();

    int playerCellX = static_cast<int>(round(playerPos.getX() - _gameMap->getPosition().getX() + 0.5f));
    int playerCellY = static_cast<int>(round(playerPos.getY() - _gameMap->getPosition().getZ() + 0.5f));

    if (playerCellX < 0) playerCellX = 0;
    else if (playerCellX >= cubicMapX) playerCellX = cubicMapX - 1;

    if (playerCellY < 0) playerCellY = 0;
    else if (playerCellY >= cubicMapY) playerCellY = cubicMapY - 1;

    for (int y = 0; y < cubicMapY; y++)
    {
        for (int x = 0; x < cubicMapX; x++)
        {
            if ((mapPixels[y * cubicMapX + x].getR() == 255) &&
                (RayLib::Models::Collision::CheckCollisionCircleRec(playerPos, playerRadius,
                                         Type::Rectangle { _gameMap->getPosition().getX() - 0.5f + x * 1.0f,
                                                           _gameMap->getPosition().getZ() - 0.5f + y * 1.0f,
                                                           1.0f,
                                                           1.0f })))
            {
                return true;
            }
        }
    }

    return false;
}

void Bomberman::GameScene::update(const double &elapsed)
{
    auto oldPosition = _listPlayers[0]->getPosition();
    _listPlayers[0]->update(elapsed);
    if (checkColision(0))
        _listPlayers[0]->setPosition(oldPosition);
    //for (auto &player : _listPlayers)
    //    player->update(elapsed);
}

void Bomberman::GameScene::drawScene()
{
    _background.render();
    RayLib::Window::getInstance().getDrawing().beginMode3D(_camera);
    _gameMap->render();
    _listPlayers[0]->render();
    //for (auto &player : _listPlayers)
    //    player->render();
    RayLib::Window::getInstance().getDrawing().endMode3D();
}