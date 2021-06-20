/**
 * @file Camera.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Camera.hpp"

RayLib::Camera::Camera()
{
}

RayLib::Camera::~Camera()
{
}

void RayLib::Camera::setCameraMode(Type::Camera3D camera, int mode) const
{
    ::SetCameraMode(
        ::Camera3D {
            ::Vector3 {camera.getPosition().getX(), camera.getPosition().getY(), camera.getPosition().getZ()},
            ::Vector3 {camera.getTarget().getX(), camera.getTarget().getY(), camera.getTarget().getZ()},
            ::Vector3 {camera.getUp().getX(), camera.getUp().getY(), camera.getUp().getZ()},
            camera.getFovy(),
            camera.getProjection()
        },
        mode
    );
}

void RayLib::Camera::updateCamera(Type::Camera3D &camera)
{
    ::Camera3D cameraTmp {
        ::Vector3 {camera.getPosition().getX(), camera.getPosition().getY(), camera.getPosition().getZ()},
        ::Vector3 {camera.getTarget().getX(), camera.getTarget().getY(), camera.getTarget().getZ()},
        ::Vector3 {camera.getUp().getX(), camera.getUp().getY(), camera.getUp().getZ()},
        camera.getFovy(),
        camera.getProjection()
    };
    ::UpdateCamera(&cameraTmp);
    Type::Vector<3> &position = camera.getPosition();
    Type::Vector<3> &target = camera.getTarget();
    Type::Vector<3> &up = camera.getUp();
    float &fovy = camera.getFovy();
    int &projection = camera.getProjection();
    position = Type::Vector<3>(cameraTmp.position.x, cameraTmp.position.y, cameraTmp.position.z);
    target = Type::Vector<3>(cameraTmp.target.x, cameraTmp.target.y, cameraTmp.target.z);
    up = Type::Vector<3>(cameraTmp.up.x, cameraTmp.up.y, cameraTmp.up.z);
    fovy = cameraTmp.fovy;
    projection = cameraTmp.projection;
}

void RayLib::Camera::setCameraPanControl(int keyPan) const
{
    ::SetCameraPanControl(keyPan);
}

void RayLib::Camera::setCameraAltControl(int keyAlt) const
{
    ::SetCameraAltControl(keyAlt);
}

void RayLib::Camera::setCameraSmoothZoomControl(int keySmoothZoom) const
{
    ::SetCameraSmoothZoomControl(keySmoothZoom);
}

void RayLib::Camera::setCameraMoveControls(int frontKey, int backKey, int rightKey, int leftKey, int upKey, int downKey) const
{
    ::SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey);
}
