/**
 * @file SimpleModel.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "SimpleModel.hpp"

void RayLib::Models::SimpleModel::DrawLine3D(const Type::Vector<3> &startPos, const Type::Vector<3> &endPos, const Type::Color &color)
{
    ::DrawLine3D(
        ::Vector3 {startPos.getX(), startPos.getY(), startPos.getZ()},
        ::Vector3 {endPos.getX(), endPos.getY(), endPos.getZ()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawPoint3D(const Type::Vector<3> &position, const Type::Color &color)
{
    ::DrawPoint3D(
        ::Vector3 {position.getX(), position.getY(), position.getZ()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawCircle3D(const Type::Vector<3> &center, float radius, const Type::Vector<3> &rotationAxis, float rotationAngle, const Type::Color &color)
{
    ::DrawCircle3D(
        ::Vector3 {center.getX(), center.getY(), center.getZ()},
        radius,
        ::Vector3 {rotationAxis.getX(), rotationAxis.getY(), rotationAxis.getZ()},
        rotationAngle,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawTriangle3D(const Type::Vector<3> &v1, const Type::Vector<3> &v2, const Type::Vector<3> &v3, const Type::Color &color)
{
    ::DrawTriangle3D(
        ::Vector3 {v1.getX(), v1.getY(), v1.getZ()},
        ::Vector3 {v2.getX(), v2.getY(), v2.getZ()},
        ::Vector3 {v3.getX(), v3.getY(), v3.getZ()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawTriangleStrip3D(Type::Vector<3> &points, int pointsCount, const Type::Color &color)
{
    ::Vector3 dummy = {points.getX(), points.getY(), points.getZ()};
    ::DrawTriangleStrip3D(
        &dummy,
        pointsCount,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
    float &x = points.getX();
    float &y = points.getY();
    float &z = points.getZ();
    x = dummy.x;
    y = dummy.y;
    z = dummy.z;
}

void RayLib::Models::SimpleModel::DrawCube(const Type::Vector<3> &position, float width, float height, float length, const Type::Color &color)
{
    ::DrawCube(
        ::Vector3 {position.getX(), position.getY(), position.getZ()},
        width,
        height,
        length,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawCubeV(const Type::Vector<3> &position, const Type::Vector<3> &size, const Type::Color &color)
{
    ::DrawCubeV(
        ::Vector3 {position.getX(), position.getY(), position.getZ()},
        ::Vector3 {size.getX(), size.getY(), size.getZ()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );  
}

void RayLib::Models::SimpleModel::DrawCubeWires(const Type::Vector<3> &position, float width, float height, float length, const Type::Color &color)
{
    ::DrawCubeWires(
        ::Vector3 {position.getX(), position.getY(), position.getZ()},
        width,
        height,
        length,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawCubeWiresV(const Type::Vector<3> &position, const Type::Vector<3> &size, const Type::Color &color)
{
    ::DrawCubeWiresV(
        ::Vector3 {position.getX(), position.getY(), position.getZ()},
        ::Vector3 {size.getX(), size.getY(), size.getZ()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );  
}

void RayLib::Models::SimpleModel::DrawCubeTexture(const Type::Texture &texture, const Type::Vector<3> &position, float width, float height, float length, const Type::Color &color)
{
    ::DrawCubeTexture(
        ::Texture2D {texture.getId(), texture.getWidth(), texture.getHeight(), texture.getMipmaps(), texture.getFormat()},
        ::Vector3 {position.getX(), position.getY(), position.getZ()},
        width,
        height,
        length,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawSphere(const Type::Vector<3> &centerPos, float radius, const Type::Color &color)
{
    ::DrawSphere(
        ::Vector3 {centerPos.getX(), centerPos.getY(), centerPos.getZ()},
        radius,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawSphereEx(const Type::Vector<3> &centerPos, float radius, int rings, int slices, const Type::Color &color)
{
    ::DrawSphereEx(
        ::Vector3 {centerPos.getX(), centerPos.getY(), centerPos.getZ()},
        radius,
        rings,
        slices,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawSphereWires(const Type::Vector<3> &centerPos, float radius, int rings, int slices, const Type::Color &color)
{
    ::DrawSphereWires(
        ::Vector3 {centerPos.getX(), centerPos.getY(), centerPos.getZ()},
        radius,
        rings,
        slices,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawCylinder(const Type::Vector<3> &position, float radiusTop, float radiusBottom, float height, int slices, const Type::Color &color)
{
    ::DrawCylinder(
        ::Vector3 {position.getX(), position.getY(), position.getZ()},
        radiusTop,
        radiusBottom,
        height,
        slices,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawCylinderWires(const Type::Vector<3> &position, float radiusTop, float radiusBottom, float height, int slices, const Type::Color &color)
{
    ::DrawCylinderWires(
        ::Vector3 {position.getX(), position.getY(), position.getZ()},
        radiusTop,
        radiusBottom,
        height,
        slices,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawPlane(const Type::Vector<3> &centerPos, const Type::Vector<2> &size, const Type::Color &color)
{
    ::DrawPlane(
        ::Vector3 {centerPos.getX(), centerPos.getY(), centerPos.getZ()},
        ::Vector2 {size.getX(), size.getY()},
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Models::SimpleModel::DrawGrid(int slices, float spacing)
{
    ::DrawGrid(slices, spacing);
}   
