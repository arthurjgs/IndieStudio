/**
 * @file Scene.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../GameObject.hpp"
#include "../SceneManager.hpp"
#include <vector>

namespace Bomberman {
    class SceneManager;
    
    class Scene {
        public:
            Scene() = delete;
            Scene(SceneManager &manager);
            virtual ~Scene() = default;

            Scene(const Scene &cpy) = delete;
            Scene &operator = (const Scene &cpy) = delete;
            
            static GameObject &getObjFromName(const std::string &name, std::vector<GameObject> &container);
            static std::vector<std::reference_wrapper<GameObject>> getObjsFromType(const GameObject::ObjectType &type, std::vector<GameObject> &container);
            virtual void update(const double &elapsed) = 0;
            virtual void drawScene() = 0;
        protected:
            SceneManager &__manager;
        private:
    };
}

#include "../SceneManager.hpp"