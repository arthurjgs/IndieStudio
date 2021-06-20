/**
 * @file SimpleModel.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../../Types/Color/Color.hpp"
#include "../../../Types/Vector/Vector.hpp"
#include "../../../Types/RenderTexture/Texture.hpp"

namespace RayLib {
    namespace Models {
        class SimpleModel {
            public:
                SimpleModel() = default;
                ~SimpleModel() = default;
                SimpleModel(const SimpleModel &cpy) = delete;
                SimpleModel &operator = (const SimpleModel &cpy) = delete;

                static void DrawLine3D(const Type::Vector<3> &startPos, const Type::Vector<3> &endPos, const Type::Color &color);
                static void DrawPoint3D(const Type::Vector<3> &position, const Type::Color &color);
                static void DrawCircle3D(const Type::Vector<3> &center, float radius, const Type::Vector<3> &rotationAxis, float rotationAngle, const Type::Color &color);
                static void DrawTriangle3D(const Type::Vector<3> &v1, const Type::Vector<3> &v2, const Type::Vector<3> &v3, const Type::Color &color);
                static void DrawTriangleStrip3D(Type::Vector<3> &points, int pointsCount, const Type::Color &color);
                static void DrawCube(const Type::Vector<3> &position, float width, float height, float length, const Type::Color &color);
                static void DrawCubeV(const Type::Vector<3> &position, const Type::Vector<3> &size, const Type::Color &color);
                static void DrawCubeWires(const Type::Vector<3> &position, float width, float height, float length, const Type::Color &color);
                static void DrawCubeWiresV(const Type::Vector<3> &position, const Type::Vector<3> &size, const Type::Color &color);
                static void DrawCubeTexture(const Type::Texture &texture, const Type::Vector<3> &position, float width, float height, float length, const Type::Color &color);
                static void DrawSphere(const Type::Vector<3> &centerPos, float radius, const Type::Color &color);
                static void DrawSphereEx(const Type::Vector<3> &centerPos, float radius, int rings, int slices, const Type::Color &color);
                static void DrawSphereWires(const Type::Vector<3> &centerPos, float radius, int rings, int slices, const Type::Color &color);
                static void DrawCylinder(const Type::Vector<3> &position, float radiusTop, float radiusBottom, float height, int slices, const Type::Color &color);
                static void DrawCylinderWires(const Type::Vector<3> &position, float radiusTop, float radiusBottom, float height, int slices, const Type::Color &color);
                static void DrawPlane(const Type::Vector<3> &centerPos, const Type::Vector<2> &size, const Type::Color &color);
                static void DrawGrid(int slices, float spacing);    
            private:
            protected:
        };
    }
}