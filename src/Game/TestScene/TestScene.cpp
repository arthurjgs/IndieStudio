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
    _listButton.push_back(std::make_unique<Bomberman::Button>("test", Type::Vector<3>(900, 500, 0), "./assets/buttons/app.png"));
}

void Bomberman::TestScene::update(const double &elapsed)
{
    (void)elapsed;
    _listButton[0]->update(elapsed);
}

void Bomberman::TestScene::drawScene()
{
    _listButton[0]->render();
}