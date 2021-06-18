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

            inline Vector<3> &getMin() { return (this->_min); }
            inline Vector<3> &getMax() { return (this->_max); }
        
            inline Vector<3> getMin() const { return (this->_min); }
            inline Vector<3> getMax() const { return (this->_max); }
        
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
            Vector<3> _min;
            Vector<3> _max;
    };
}