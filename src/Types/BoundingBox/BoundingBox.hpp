/**
 * @file BoundingBox.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../Vector/Vector.hpp"

namespace Type {
    class BoundingBox {
        public:
            BoundingBox(const Vector<3> &min, const Vector<3> &max);
            ~BoundingBox() = default;

            BoundingBox(const BoundingBox &cpy);
            BoundingBox &operator = (const BoundingBox &cpy);

            inline Vector<3> &getMin() { return (this->__min); }
            inline Vector<3> &getMax() { return (this->__max); }
        
            inline Vector<3> getMin() const { return (this->__min); }
            inline Vector<3> getMax() const { return (this->__max); }
        
            BoundingBox operator + (const BoundingBox &cpy);
            BoundingBox &operator += (const BoundingBox &cpy);
            BoundingBox operator - (const BoundingBox &cpy);
            BoundingBox &operator -= (const BoundingBox &cpy);
            BoundingBox operator * (const BoundingBox &cpy);
            BoundingBox &operator *= (const BoundingBox &cpy);
            BoundingBox operator / (const BoundingBox &cpy);
            BoundingBox &operator /= (const BoundingBox &cpy);
        protected:
        private:
            Vector<3> __min;
            Vector<3> __max;
    };
}