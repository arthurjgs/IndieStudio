/**
 * @file Camera.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "../Types/Camera/Camera3D.hpp"
#include <raylib.h>
#include <iostream>

namespace RayLib
{
    class Camera {
        public:
            Camera();
            ~Camera();
            void setCameraMode(Type::Camera3D camera, int mode) const;
            void updateCamera(Type::Camera3D &camera);
            void setCameraPanControl(int keyPan) const;
            void setCameraAltControl(int keyAlt) const;
            void setCameraSmoothZoomControl(int keySmoothZoom) const;
            void setCameraMoveControls(int frontKey, int backKey, int rightKey, int leftKey, int upKey, int downKey) const;

        protected:
        private:
    };
}

#endif /* !CAMERA_HPP_ */
