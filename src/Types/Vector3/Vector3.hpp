/**
 * @file Vector3.hpp
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
     * @brief Data class that hold info on a vector3
     * 
     */
    class Vector3 {
        public:
            Vector3() = delete;
            /**
             * @brief Construct a new Vector 3 object
             * 
             * @param x 
             * @param y 
             * @param z 
             */
            Vector3(const float &x, const float &y, const float &z);
            /**
             * @brief Construct a new Vector 3 object
             * 
             * @param cpy 
             */
            Vector3(const Vector3 &cpy);
            /**
             * @brief Construct a new Vector 3 object
             * 
             * @param cpy 
             */
            Vector3(const Vector3 &&cpy);
            /**
             * @brief copy instance of cpy into this
             * 
             * @param cpy 
             * @return Vector3& 
             */
            Vector3 &operator = (const Vector3 &cpy);
            /**
             * @brief add two vector together
             * 
             * @param val 
             * @return Vector3& 
             */
            Vector3 operator + (const Vector3 &val);
            /**
             * @brief substract two vector together
             * 
             * @param val 
             * @return Vector3& 
             */
            Vector3 operator - (const Vector3 &val);
            /**
             * @brief divide two vector together
             * 
             * @param val 
             * @return Vector3& 
             */
            Vector3 operator / (const Vector3 &val);
            /**
             * @brief multiple two vector together
             * 
             * @param val 
             * @return Vector3& 
             */
            Vector3 operator * (const Vector3 &val);
            /**
             * @brief Destroy the Vector 3 object
             * 
             */
            ~Vector3() = default;
            /**
             * @brief get X data
             * 
             * @return float& 
             */
            inline float &getX()
            {
                return (this->__x);
            }
            /**
             * @brief get Y data
             * 
             * @return float& 
             */
            inline float &getY()
            {
                return (this->__y);
            }
            /**
             * @brief get Z data
             * 
             * @return float& 
             */
            inline float &getZ()
            {
                return (this->__z);
            }
        protected:
        private:
            float __x;
            float __y;
            float __z;
    };
}