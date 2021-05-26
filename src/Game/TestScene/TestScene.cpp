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

Bomberman::TestScene::TestScene(SceneManager &manager) :
Scene(manager)
{

}

void Bomberman::TestScene::update(const double &elapsed)
{
    (void)elapsed;
}

void Bomberman::TestScene::drawScene()
{
    std::cout << "DRAWING LOADING" << std::endl;
    this->__text.DrawText("THIS IS A TEST SCENE", 500, 500, 100, Type::Color(0, 0, 0, 255));
}