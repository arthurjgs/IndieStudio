/**
 * @file Image.hpp
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

namespace Type {
    /**
     * @brief Data class that hold info on an image
     * 
     */
    class Image {
        public:
            Image() = delete;
            /**
             * @brief Construct a new Image object
             * 
             * @param data 
             * @param width 
             * @param height 
             */
            Image(const std::string &data, const int &width, const int &height);
            /**
             * @brief Construct a new Image object
             * 
             * @param cpy 
             */
            Image(const Image &cpy);
            /**
             * @brief Construct a new Image object
             * 
             * @param cpy 
             */
            Image(const Image &&cpy);
            /**
             * @brief Copy Image to current instance
             * 
             * @param cpy 
             * @return Image& 
             */
            Image &operator = (const Image &cpy);
            /**
             * @brief Destroy the Image object
             * 
             */
            ~Image() = default;

            /**
             * @brief Get the Data object
             * 
             * @return std::string& 
             */
            inline std::string &getData()
            {
                return (this->__data);
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
            inline std::string getData() const
            {
                return (this->__data);
            }
            inline int getWidth() const
            {
                return (this->__width);
            }
            inline int getHeight() const
            {
                return (this->__height);
            }
        protected:
        private:
            std::string __data;
            int __width;              
            int __height;            
    };
}