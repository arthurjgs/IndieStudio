/**
 * @file Vector.hpp
 * @author Virgile AGNEL
 * @brief 
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <iostream>
#include <array>

namespace Type {
    template<size_t vecSize> 
    class Vector {
        public:
            Vector()
            {
                static_assert(vecSize != 0, "Error can't create a vector of size 0.");
                this->__vector = {0};
            }

            template<typename ... Floats>
            Vector(Floats... args)
            {
                float arr[]{args ...};
                static_assert(sizeof(arr) / sizeof(float) == vecSize, "Error invalid parameters numbers.");
                static_assert(vecSize != 0, "Error can't create a vector of size 0.");
                for (size_t i = 0; i < vecSize; i++) {
                    this->__vector[i] = arr[i];
                }
            }

            Vector(const Vector<vecSize> &cpy)
            {
                for (size_t i = 0; i < vecSize; i++) {
                    this->__vector[i] = cpy.__vector[i];
                }
            }

            inline Vector<vecSize> &operator = (const Vector<vecSize> &cpy)
            {
                for (size_t i = 0; i < vecSize; i++) {
                    this->__vector[i] = cpy.__vector[i];
                }
                return (*this);
            }

            inline Vector<vecSize> operator + (const Vector<vecSize> &vec)
            {
                Vector<vecSize> res(*this);

                for (size_t i = 0; i < vecSize; i++) {
                    res.__vector[i] += vec.__vector[i];
                }
                return (res);
            }

            inline Vector<vecSize> operator += (const Vector<vecSize> &vec)
            {
                for (size_t i = 0; i < vecSize; i++) {
                    this->__vector[i] += vec.__vector[i];
                }
                return (*this);
            }

            inline Vector<vecSize> operator - (const Vector<vecSize> &vec)
            {
                Vector<vecSize> res(*this);

                for (size_t i = 0; i < vecSize; i++) {
                    res.__vector[i] -= vec.__vector[i];
                }
                return (res);
            }

            inline Vector<vecSize> operator -= (const Vector<vecSize> &vec)
            {
                for (size_t i = 0; i < vecSize; i++) {
                    this->__vector[i] -= vec.__vector[i];
                }
                return (*this);
            }

            inline Vector<vecSize> operator * (const Vector<vecSize> &vec)
            {
                Vector<vecSize> res(*this);

                for (size_t i = 0; i < vecSize; i++) {
                    res.__vector[i] *= vec.__vector[i];
                }
                return (res);
            }

            inline Vector<vecSize> operator *= (const Vector<vecSize> &vec)
            {
                for (size_t i = 0; i < vecSize; i++) {
                    this->__vector[i] *= vec.__vector[i];
                }
                return (*this);
            }

            inline Vector<vecSize> operator / (const Vector<vecSize> &vec)
            {
                Vector<vecSize> res(*this);

                for (size_t i = 0; i < vecSize; i++) {
                    res.__vector[i] /= vec.__vector[i];
                }
                return (res);
            }

            inline Vector<vecSize> operator /= (const Vector<vecSize> &vec)
            {
                for (size_t i = 0; i < vecSize; i++) {
                    this->__vector[i] /= vec.__vector[i];
                }
                return (*this);
            }

            inline float &getX() 
            {
                return (this->__vector[0]);
            }

            inline float &getY()
            {
                static_assert(vecSize > 1, "Error requesting a properties with invalid vector size");
                return (this->__vector[1]);
            }

            inline float &getZ()
            {
                static_assert(vecSize > 2, "Error requesting a properties with invalid vector size");
                return (this->__vector[2]);
            }

            inline float &getW()
            {
                static_assert(vecSize > 3, "Error requesting a properties with invalid vector size");
                return (this->__vector[3]);
            }

            template <size_t index>
            inline float &getVal()
            {
                static_assert(index < vecSize, "Error requesting index that is not valid");
                return (this->__vector[index]);
            }

            inline std::array<float, vecSize> getArray() const
            {
                return (this->__vector);
            }
            ~Vector() {};
        private:
            std::array<float, vecSize> __vector;
        protected:
    };
}

template<size_t vecSize>
std::ostream &operator << (std::ostream &str, const Type::Vector<vecSize> &vec)
{
    str << "[";
    std::array<float, vecSize> arr = vec.getArray();
    for (size_t i = 0; i < vecSize; i++) {
        if (i == vecSize - 1) {
            std::cout << arr[i];
        } else {
            std::cout << arr[i] << ", ";
        }
    }
    str << "]";
    return (str);
}