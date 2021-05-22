/**
 * @file Camera2D.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CAMERA2D_HPP_
#define CAMERA2D_HPP_

#include "../Vector/Vector.hpp"

namespace Type
{
    class Camera2D {
        public:
            Camera2D() = delete;
            Camera2D(const Type::Vector<2> offset, const Type::Vector<2> target, const float rotation, const float zoom);
            Camera2D(const Type::Camera2D &cpy);
            Camera2D operator =(const Camera2D &cpy);
            ~Camera2D() = default;
            inline Type::Vector<2> &getOffset()
            {
                return _offset;
            }
            inline Type::Vector<2> getOffset() const
            {
                return _offset;
            }
            inline Type::Vector<2> &getTarget()
            {
                return _target;
            }
            inline Type::Vector<2> getTarget() const
            {
                return _target;
            }
            inline float &getRotation()
            {
                return _rotation;
            }
            inline float getRotation() const
            {
                return _rotation;
            }
            inline float &getZoom()
            {
                return _zoom;
            }
            inline float getZoom() const
            {
                return _zoom;
            }

        protected:
        private:
            Type::Vector<2> _offset;
            Type::Vector<2> _target;
            float _rotation;
            float _zoom;
    };
}

#endif /* !CAMERA2D_HPP_ */
