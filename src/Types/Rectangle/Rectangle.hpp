/**
 * @file Rectangle.hpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

namespace Type {
    /**
     * @brief Data Class holding rectangle info
     * 
     */
    class Rectangle {
        public:
            Rectangle() = delete;
            /**
             * @brief Construct a new Rectangle object
             * 
             * @param x 
             * @param y 
             * @param width 
             * @param height 
             */
            Rectangle(const float &x, const float &y, const float &width, const float &height);
            /**
             * @brief Construct a new Rectangle object
             * 
             * @param cpy 
             */
            Rectangle(const Rectangle &cpy);
            /**
             * @brief Construct a new Rectangle object
             * 
             * @param cpy 
             */
            Rectangle(const Rectangle &&cpy);
            ~Rectangle() = default;
            /**
             * @brief copy rectangle
             * 
             * @param cpy 
             * @return Rectangle& 
             */
            Rectangle &operator = (const Rectangle &cpy);
            /**
             * @brief add two rectangle
             * 
             * @param val 
             * @return Rectangle& 
             */
            Rectangle operator + (const Rectangle &val);
            /**
             * @brief substract two rectangle 
             * 
             * @param val 
             * @return Rectangle& 
             */
            Rectangle operator - (const Rectangle &val);
            /**
             * @brief multiplies two rectangle
             * 
             * @param val 
             * @return Rectangle& 
             */
            Rectangle operator * (const Rectangle &val);
            /**
             * @brief divide two rectangle
             * 
             * @param val 
             * @return Rectangle& 
             */
            Rectangle operator / (const Rectangle &val);
            /**
             * @brief Get the X object
             * 
             * @return float& 
             */
            inline float &getX()
            {
                return (this->__x);
            }
            /**
             * @brief Get the Y object
             * 
             * @return float& 
             */
            inline float &getY()
            {
                return (this->__y);
            }
            /**
             * @brief Get the Width object
             * 
             * @return float& 
             */
            inline float &getWidth()
            {
                return (this->__width);
            }
            /**
             * @brief Get the Height object
             * 
             * @return float& 
             */
            inline float &getHeight()
            {
                return (this->__height);
            }
            inline float getX() const
            {
                return (this->__x);
            }
            inline float getY() const
            {
                return (this->__y);
            }
            inline float getWidth() const
            {
                return (this->__width);
            }
            inline float getHeight() const
            {
                return (this->__height);
            }
        protected:
        private:
            float __x;
            float __y;
            float __width;
            float __height;
    };
}