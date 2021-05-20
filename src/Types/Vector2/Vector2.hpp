/**
 * @file Vector2.hpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

namespace Types {
    /**
     * @brief Data Class that hold data on a vector2
     * 
     */
    class Vector2 {
        public:
            Vector2() = delete;
            /**
             * @brief Construct a new Vector 2 object
             * 
             * @param x 
             * @param y 
             */
            Vector2(const float &x, const float &y);
            /**
             * @brief Construct a new Vector 2 object
             * 
             * @param cpy 
             */
            Vector2(const Vector2 &cpy);
            /**
             * @brief Construct a new Vector 2 object
             * 
             * @param cpy 
             */
            Vector2(const Vector2 &&cpy);
            /**
             * @brief copy vector
             * 
             * @param cpy 
             * @return Vector2& 
             */
            Vector2 &operator = (const Vector2 &cpy);
            /**
             * @brief add two vector
             * 
             * @param val 
             * @return Vector2& 
             */
            Vector2 operator + (const Vector2 &val);
            /**
             * @brief sub two vector
             * 
             * @param val 
             * @return Vector2& 
             */
            Vector2 operator - (const Vector2 &val);
            /**
             * @brief divide two vector
             * 
             * @param val 
             * @return Vector2& 
             */
            Vector2 operator / (const Vector2 &val);
            /**
             * @brief multiplie two vector
             * 
             * @param val 
             * @return Vector2& 
             */
            Vector2 operator * (const Vector2 &val);
            /**
             * @brief get X
             * 
             * @return float& 
             */
            inline float &getX()
            {
                return (this->__x);
            }
            /**
             * @brief get Y
             * 
             * @return float& 
             */
            inline float &getY()
            {
                return (this->__y);
            }
        protected:
        private:
            float __x;
            float __y;
    };
}