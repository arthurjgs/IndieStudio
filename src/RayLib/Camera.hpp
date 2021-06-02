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

// camera.position = (Vector3){ -0.251893f, 39.969784f, 18.012878f };  // Camera position
// camera.target = (Vector3){ -0.292523f, 31.065876f, 11.849975f };      // Camera looking at point
// camera.up = (Vector3){ -0.002688f, 10.0f, 0.002688f };          // Camera up vector (rotation towards target)
// camera.fovy = 20.0f;                                // Camera field-of-view Y
// camera.projection = CAMERA_PERSPECTIVE;  

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
