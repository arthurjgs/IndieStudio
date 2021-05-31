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
#include <unistd.h>


Bomberman::TestScene::TestScene(SceneManager &manager) :
Scene(manager)
{
    ::usleep(10000000);
}

void Bomberman::TestScene::update(const double &elapsed)
{
    (void)elapsed;
}

void Bomberman::TestScene::drawScene()
{
    this->__text.DrawText("THIS IS A TEST SCENE", 500, 500, 100, Type::Color(0, 0, 0, 255));
}