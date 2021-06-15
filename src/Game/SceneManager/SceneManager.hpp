/**
 * @file SceneManager.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <stack>
#include <memory>
#include "Scene/Scene.hpp"

namespace Bomberman {
    class Scene;

    class SceneManager {
        public:
            SceneManager() = default;
            ~SceneManager() = default;
            SceneManager(const SceneManager &) = delete;
            SceneManager &operator = (const SceneManager &) = delete;

            template<typename scene, typename ...Args>
            void newScene(Args &&...args)
            {
                std::unique_ptr<scene> result = std::make_unique<scene>(*this, std::forward<Args>(args)...);

                this->__engine.push(std::move(result));
            }
            
            template<typename scene, typename ...Args>
            void replaceTop(Args &&...args)
            {
                std::unique_ptr<scene> result = std::make_unique<scene>(*this, std::forward<Args>(args)...);

                if (this->__engine.size() == 0) {
                    // TODO: custom exception type
                    throw std::runtime_error("error can't replace stack is empty");
                }
                this->__engine.top() = std::move(result);
            }
            
            template<typename scene, typename ...Args>
            inline void clearStack(Args &&...args)
            {
                while (!this->__engine.empty()) {
                    this->__engine.pop();
                }
                this->newScene<scene, Args...>(std::forward<Args>(args)...);
            }

            inline int getSize() const
            {
                return (this->__engine.size());
            }

            void unloadScene();
            void update(const double &elapsed);
            void draw();
            void checkStack() const;
        private:
        protected:
            std::stack<std::unique_ptr<Scene>> __engine;
    };
}