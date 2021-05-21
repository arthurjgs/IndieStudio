/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Camera3D
*/

#ifndef CAMERA3D_HPP_
#define CAMERA3D_HPP_

#include "../Vector/Vector.hpp"

namespace Type
{
    class Camera3D {
        public:
            Camera3D() = delete;
            ~Camera3D() = default;
            Camera3D(Type::Vector<3> position, Type::Vector<3> target, Type::Vector<3> up, float fovy, int projection);
            Camera3D(const Camera3D &cpy);
            Camera3D operator =(const Camera3D &cpy);
            inline Type::Vector<3> &getPosition()
            {
                return _position;
            }
            inline Type::Vector<3> getPosition() const
            {
                return _position;
            }
            inline Type::Vector<3> &getTarget()
            {
                return _target;
            }
            inline Type::Vector<3> getTarget() const
            {
                return _target;
            }
            inline Type::Vector<3> &getUp()
            {
                return _up;
            }
            inline Type::Vector<3> getUp() const
            {
                return _up;
            }
            inline float &getFovy()
            {
                return _fovy;
            }
            inline float getFovy() const
            {
                return _fovy;
            }
            inline int &getProjection()
            {
                return _projection;
            }
            inline int getProjection() const
            {
                return _projection;
            }

        protected:
        private:
            Type::Vector<3> _position;
            Type::Vector<3> _target;
            Type::Vector<3> _up;
            float _fovy;
            int _projection;
    };
}

#endif /* !CAMERA3D_HPP_ */
