/**
 * @file Matrix.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Matrix.hpp"

Types::Matrix::Matrix(const float *&matrix)
{
    for (int i = 0; i < MATRIX_SIZE; i++) {
        this->__matrix[i] = matrix[i];
    }
}

Types::Matrix::Matrix(const Matrix &cpy)
{
    for (int i = 0; i < MATRIX_SIZE; i++) {
        this->__matrix[i] = cpy.__matrix[i];
    }
}

Types::Matrix::Matrix(const Matrix &&cpy)
{
    for (int i = 0; i < MATRIX_SIZE; i++) {
        this->__matrix[i] = cpy.__matrix[i];
    }
}

Types::Matrix &Types::Matrix::operator = (const Matrix &cpy)
{
    for (int i = 0; i < MATRIX_SIZE; i++) {
        this->__matrix[i] = cpy.__matrix[i];
    }
    return (*this);
}