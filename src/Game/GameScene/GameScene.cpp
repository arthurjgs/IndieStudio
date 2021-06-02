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
#include <unistd.h>
#include <RayLib/Window.hpp>


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

void Bomberman::GameScene::update(const double &elapsed)
{
    _listPlayers[0]->update(elapsed);
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