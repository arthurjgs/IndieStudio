/**
 * @file Texture.hpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <iostream>

namespace Types {
    /**
     * @brief Data class holding a texture info
     * 
     */
    class Texture {
        public:
            Texture() = delete;
            /**
             * @brief Construct a new Texture object
             * 
             * @param texturePath 
             * @param width 
             * @param height 
             */
            Texture(const std::string &texturePath, const int &width, const int &height);
            /**
             * @brief Construct a new Texture object
             * 
             * @param cpy 
             */
            Texture(const Texture &cpy);
            /**
             * @brief Construct a new Texture object
             * 
             * @param cpy 
             */
            Texture(const Texture &&cpy);
            /**
             * @brief Copy texture instance into current one
             * 
             * @param cpy 
             * @return Texture& 
             */
            Texture &operator = (const Texture &cpy);
            /**
             * @brief Destroy the Texture object
             * 
             */
            ~Texture() = default;
            /**
             * @brief Get the Path object
             * 
             * @return std::string& 
             */
            inline std::string &getPath()
            {
                return (this->__texturePath);
            }
            /**
             * @brief Get the Width object
             * 
             * @return int& 
             */
            inline int &getWidth()
            {
                return (this->__width);
            }
            /**
             * @brief Get the Height object
             * 
             * @return int& 
             */
            inline int &getHeight()
            {
                return (this->__height);
            }
        protected:
        private:
            std::string __texturePath;
            int __width;
            int __height;
    };
}