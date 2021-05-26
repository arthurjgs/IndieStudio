/**
 * @file SceneManager.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "SceneManager.hpp"

void Bomberman::SceneManager::unloadScene()
{
    this->__engine.pop();
}

void Bomberman::SceneManager::update(const double &elapsed)
{
    this->__engine.top().get()->update(elapsed);
}

void Bomberman::SceneManager::checkStack() const
{
    if (this->__engine.size() == 0) {
        // TODO: modify this bellow by custom error type
        throw std::runtime_error("Error scene stack is empty nothing to render");
    }
}

void Bomberman::SceneManager::draw()
{
    this->__engine.top().get()->drawScene();
}
