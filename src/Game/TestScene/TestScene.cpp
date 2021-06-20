/**
 * @file TestScene.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "TestScene.hpp"
#include <memory>
#include <Game/Config.hpp>

Bomberman::TestScene::TestScene(SceneManager &manager) :
Scene(manager),
test(Bomberman::Config::ExecutablePath + "assets/LoadingScreen/loading_word.png", "test", GameObject::ObjectType::DECOR, Type::Vector<3>(500.0f, 500.0f, 0.0f))
{
}

void Bomberman::TestScene::update(const double &elapsed)
{
    this->test.update(elapsed);
    _listButton[0]->update(elapsed);
}

void Bomberman::TestScene::drawScene()
{
    this->test.render();
}