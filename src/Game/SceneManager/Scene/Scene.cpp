/**
 * @file Scene.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Scene.hpp"

Bomberman::Scene::Scene(SceneManager &manager) :
__manager(manager)
{
}

void Bomberman::Scene::_loadScene(const Scene &newScene)
{
    // Implement loading screen here
    (void)newScene;
}

Bomberman::GameObject &Bomberman::Scene::getObjFromName(const std::string &name, std::vector<GameObject> &container)
{
    for (GameObject &val : container) {
        if (val.getName() == name) {
            return (val);
        }
    }
    // TODO: throw error when name does not match
    throw std::runtime_error("does not match");
}

std::vector<std::reference_wrapper<Bomberman::GameObject>> Bomberman::Scene::getObjsFromType(const GameObject::ObjectType &type, std::vector<GameObject> &container)
{
    std::vector<std::reference_wrapper<GameObject>> vec;

    for (GameObject &val : container) {
        if (val.getType() == type) {
            vec.push_back(val);
        }
    }
    if (vec.size() == 0) {
        // TODO: OR DO NOTHING DEPENDS WHEN TYPE DOES NOT MATCH
    }
    return (vec);
}

void Bomberman::Scene::_unloadMe()
{
    // unload current scene
}