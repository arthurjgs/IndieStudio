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
                                const std::string &playerDll3, const std::string &playerDll4) : Scene(manager),
                                _camera(Type::Vector<3>(0.0f, 40.0f, 20.0f),
                                        Type::Vector<3>(0.0f, 0.0f, 0.0f),
                                        Type::Vector<3>(0.0f, 1.0f, 0.0f),
                                        20.0f,
                                        CAMERA_PERSPECTIVE)
{

    std::shared_ptr<Map> gameMap = std::make_shared<Map>("assets/map/default", Type::Vector<3>(-7.0f, 0.0f, -7.0f));
    std::shared_ptr<Player> player1 = std::make_shared<Player>("Player1", Type::Vector<3>(-6.0f, 0.0f, -6.0f), "assets/models/bomberman");
    player1->setScale(Type::Vector<3>(15.0f, 15.0f, 15.0f));

    this->_gameObjectList.emplace_back(std::make_shared<Music>("MainMusic", "assets/sounds/music.mp3", 0.5f));
    this->_gameObjectList.emplace_back(gameMap);
    this->_gameObjectList.emplace_back(std::make_shared<Image>("assets/map/default/bg.png", "Background", GameObject::DECOR,
                                                               Type::Vector<3>(0.0f, 0.0f, 0.0f)));
    this->_gameObjectList.emplace_back(player1);

    this->_gameMap = gameMap;
    this->_listPlayers.emplace_back(player1);
}

bool Bomberman::GameScene::checkCollision(int playerIndex) const
{
    Type::Vector<2> playerPos = { _listPlayers[playerIndex].lock()->getPosition().getX(), _listPlayers[playerIndex].lock()->getPosition().getZ() };
    Type::Vector<2> cubicMap = this->_gameMap.lock()->getCubicMap();
    int cubicMapX = static_cast<int>(cubicMap.getX());
    int cubicMapY = static_cast<int>(cubicMap.getY());
    float playerRadius = 0.3f;
    std::vector<Type::Color> mapPixels = _gameMap.lock()->getMapPixels();

    int playerCellX = static_cast<int>(round(playerPos.getX() - _gameMap.lock()->getPosition().getX() + 0.5f));
    int playerCellY = static_cast<int>(round(playerPos.getY() - _gameMap.lock()->getPosition().getZ() + 0.5f));

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
                                         Type::Rectangle { _gameMap.lock()->getPosition().getX() - 0.5f + x * 1.0f,
                                                           _gameMap.lock()->getPosition().getZ() - 0.5f + y * 1.0f,
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
    for (auto & object : _gameObjectList) {
        if (object->getName().find("Player") == std::string::npos)
            object->update(elapsed);
    }

    for (auto & player : _listPlayers) {
        auto oldPosition = player.lock()->getPosition();
        player.lock()->update(elapsed);
        if (checkCollision(0))
            player.lock()->setPosition(oldPosition);
    }
    //for (auto &player : _listPlayers)
    //    player->update(elapsed);
}

void Bomberman::GameScene::drawScene()
{
    RayLib::Window::getInstance().getDrawing().beginMode3D(_camera);
    for (auto & object : _gameObjectList)
        object->render();
    //for (auto &player : _listPlayers)
    //    player->render();
    RayLib::Window::getInstance().getDrawing().endMode3D();
}