/**
 * @file Matrix.hpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#define MATRIX_SIZE (16)

namespace Types {
    /**
     * @brief Data class that hold info on a matrix
     * 
     */
    class Matrix {
        public:
            Matrix() = delete;
            /**
             * @brief Construct a new Matrix object
             * 
             * @param matrix 
             */
            Matrix(const float *&matrix);
            /**
             * @brief Construct a new Matrix object
             * 
             * @param cpy 
             */
            Matrix(const Matrix &cpy);
            /**
             * @brief Construct a new Matrix object
             * 
             * @param cpy 
             */
            Matrix(const Matrix &&cpy);
            /**
             * @brief copy a matrix into another one
             * 
             * @param cpy 
             * @return Matrix& 
             */
            Matrix &operator = (const Matrix &cpy);
            /**
             * @brief Destroy the Matrix object
             * 
             */
            ~Matrix() = default;
            /**
             * @brief Get the Matrix object
             * 
             * @return float* 
             */
            inline float *getMatrix()
            {
                return (this->__matrix);
            }
        protected:
        private:
            float __matrix[MATRIX_SIZE];
    };
}