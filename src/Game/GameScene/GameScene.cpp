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
#include <Game/Bomb/Bomb.hpp>


Bomberman::GameScene::GameScene(SceneManager &manager,
                                const std::string &playerDll1, const std::string &playerDll2,
                                const std::string &playerDll3, const std::string &playerDll4) : Scene(manager),
                                _camera(Type::Vector<3>(0.0f, 40.0f, 20.0f),
                                        Type::Vector<3>(0.0f, 0.0f, 0.0f),
                                        Type::Vector<3>(0.0f, 1.0f, 0.0f),
                                        20.0f,
                                        CAMERA_PERSPECTIVE)
{
    RayLib::Manager3D::getInstance().setScene(RayLib::Manager3D::GAME);
    std::shared_ptr<Map> gameMap = std::make_shared<Map>("assets/map/default", Type::Vector<3>(-7.0f, 0.0f, -7.0f));
    std::shared_ptr<Player> player1 = std::make_shared<Player>("Bomberman", Type::Vector<3>(-6.0f, 0.0f, -6.0f));
    std::shared_ptr<Image> background = std::make_shared<Image>("assets/map/default/bg.png", "Background", GameObject::DECOR, Type::Vector<3>(0.0f, 0.0f, 0.0f));
    player1->setScale(Type::Vector<3>(15.0f, 15.0f, 15.0f));

    this->_gameObjectList.emplace_back(std::make_shared<Music>("MainMusic", "assets/sounds/music.mp3", 0.5f));
    this->_gameObjectList.emplace_back(gameMap);
    this->_gameObjectList.emplace_back(background);
    this->_gameObjectList.emplace_back(player1);

    this->_gameMap = gameMap;
    this->_listPlayers.emplace_back(player1);
    this->_background = background;
}

bool Bomberman::GameScene::checkCollisionForMap(const Type::Vector<3> &playerPosition) const
{
    Type::Vector<2> playerPos = { playerPosition.getX(), playerPosition.getZ() };
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

bool Bomberman::GameScene::checkCollisionForObjects(const Type::Vector<3> &playerPosition) const
{
    for (auto & obj : _gameObjectList) {
        if (obj->getType() == GameObject::PLAYER)
            continue;
        Type::Vector<3> enemyPosition = obj->getPosition();
        Type::Vector<3> playerRoundedPosition(static_cast<float>(round(playerPosition.getX())),
                                              static_cast<float>(round(playerPosition.getY())),
                                              static_cast<float>(round(playerPosition.getZ())));
        if (RayLib::Models::Collision::CheckCollisionBoxes(Type::BoundingBox(Type::Vector<3>(playerRoundedPosition.getX() - 1.0f / 2,
                                                                                             playerRoundedPosition.getY() - 1.0f / 2,
                                                                                             playerRoundedPosition.getZ() - 1.0f / 2),
                                                                             Type::Vector<3>(playerRoundedPosition.getX() - 1.0f / 2,
                                                                                             playerRoundedPosition.getY() - 1.0f / 2,
                                                                                             playerRoundedPosition.getZ() - 1.0f / 2)),
                                                           Type::BoundingBox(Type::Vector<3>(enemyPosition.getX() - 1.0f / 2,
                                                                                             enemyPosition.getY() - 1.0f / 2,
                                                                                             enemyPosition.getZ() - 1.0f / 2),
                                                                             Type::Vector<3>(enemyPosition.getX() - 1.0f / 2,
                                                                                             enemyPosition.getY() - 1.0f / 2,
                                                                                             enemyPosition.getZ() - 1.0f / 2)))) {
            if (obj->getType() == Bomb::FLAME)
                std::cout << "YOU SHOULD DIE" << std::endl;
            return true;
        }
    }
    return false;
}

void Bomberman::GameScene::update(const double &elapsed)
{
    // CHECK IF BOMB HAS EXPLODED
    for (auto & b : _bombList) {
        if (b.expired())
            continue;
        if (b.lock()->getState() == GameObject::DESTROYED) {
            auto flames = b.lock()->explode();
            for (auto & flame : flames) {
                _gameObjectList.emplace_back(flame);
            }
        }
    }

    // CHECK IF OBJECTS SHOULD BE DESTROYED
    _gameObjectList.erase(std::remove_if(
            _gameObjectList.begin(), _gameObjectList.end(),
            [] (std::shared_ptr<Bomberman::GameObject> &b) {
                return b->getState() == GameObject::DESTROYED;
            }), _gameObjectList.end());

    for (auto & object : _gameObjectList) {
        if (object->getType() != GameObject::PLAYER)
            object->update(elapsed);
    }

    for (auto & player : _listPlayers) {
        if (player.lock()->getState() == Player::PlayerState::ACTION) {
            std::shared_ptr<Bomb> bomb = player.lock()->createBomb();
            if (bomb != nullptr) {
                _gameObjectList.emplace_back(bomb);
                _bombList.emplace_back(bomb);
            }
        }
        auto oldPosition = player.lock()->getPosition();
        player.lock()->update(elapsed);
        if (checkCollisionForMap(player.lock()->getPosition()))
            player.lock()->setPosition(oldPosition);
        if (checkCollisionForObjects(player.lock()->getPosition()))
            player.lock()->setPosition(oldPosition);
    }
}

void Bomberman::GameScene::drawScene()
{
    _background.lock()->render();
    RayLib::Window::getInstance().getDrawing().beginMode3D(_camera);
   for (auto & object : _gameObjectList)
        object->render();
    RayLib::Window::getInstance().getDrawing().endMode3D();
}