/**
 * @file Vector4.hpp
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
     * @brief Data class that hold info on a vector4
     * 
     */
    class Vector4 {
        public:
            Vector4() = delete;
            /**
             * @brief Construct a new Vector 4 object
             * 
             * @param x 
             * @param y 
             * @param z 
             * @param a 
             */
            Vector4(const float &x, const float &y, const float &z, const float &a);
            /**
             * @brief Construct a new Vector 4 object
             * 
             * @param cpy 
             */
            Vector4(const Vector4 &cpy);
            /**
             * @brief Construct a new Vector 4 object
             * 
             * @param cpy 
             */
            Vector4(const Vector4 &&cpy);
            /**
             * @brief 
             * 
             * @param cpy 
             * @return Vector4& 
             */
            Vector4 &operator = (const Vector4 &cpy);
            /**
             * @brief add two vector4
             * 
             * @param val 
             * @return Vector4& 
             */
            Vector4 operator + (const Vector4 &val);
            /**
             * @brief substract two vector4
             * 
             * @param val 
             * @return Vector4& 
             */
            Vector4 operator - (const Vector4 &val);
            /**
             * @brief divide two vector4
             * 
             * @param val 
             * @return Vector4& 
             */
            Vector4 operator / (const Vector4 &val);
            /**
             * @brief multiplie two vector4
             * 
             * @param val 
             * @return Vector4& 
             */
            Vector4 operator * (const Vector4 &val);
            /**
             * @brief Destroy the Vector 4 object
             * 
             */
            ~Vector4() = default;
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
            /**
             * @brief get A data
             * 
             * @return float& 
             */
            inline float &getA()
            {
                return (this->__a);
            }
        protected:
        private:
            float __x;
            float __y;
            float __z;
            float __a;
    };
}