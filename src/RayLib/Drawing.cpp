/**
 * @file Drawing.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Drawing.hpp"

RayLib::Drawing::Drawing()
{
}

RayLib::Drawing::~Drawing()
{
}

void RayLib::Drawing::clearBackground(Type::Color color) const
{
    ::ClearBackground(::Color {color.getR(), color.getG(), color.getB(), color.getA()});
}

void RayLib::Drawing::beginDrawing(void) const
{
    ::BeginDrawing();
}

void RayLib::Drawing::endDrawing(void) const
{
    ::EndDrawing();
}

void RayLib::Drawing::beginMode2D(Type::Camera2D camera) const
{
    ::BeginMode2D(
        ::Camera2D {
            ::Vector2 {camera.getOffset().getX(), camera.getOffset().getY()},
            ::Vector2 {camera.getTarget().getX(), camera.getTarget().getY()},
            camera.getRotation(),
            camera.getZoom()
        }
    );
}

void RayLib::Drawing::endMode2D(void) const
{
    ::EndMode2D();
}

void RayLib::Drawing::beginMode3D(Type::Camera3D camera) const
{
    ::BeginMode3D(
        ::Camera3D {
            ::Vector3 {camera.getPosition().getX(), camera.getPosition().getY(), camera.getPosition().getZ()},
            ::Vector3 {camera.getTarget().getX(), camera.getTarget().getY(), camera.getTarget().getZ()},
            ::Vector3 {camera.getUp().getX(), camera.getUp().getY(), camera.getUp().getZ()},
            camera.getFovy(),
            camera.getProjection()
        }
    );
}

void RayLib::Drawing::endMode3D(void) const
{
    ::EndMode3D();
}

void RayLib::Drawing::beginTextureMode(Type::RenderTexture target) const
{
    ::BeginTextureMode(
        ::RenderTexture2D {
            target.getId(),
            ::Texture {target.getTexture().getId(), target.getTexture().getWidth(), target.getTexture().getHeight(), target.getTexture().getMipmaps(), target.getTexture().getFormat()},
            ::Texture {target.getDepth().getId(), target.getDepth().getWidth(), target.getDepth().getHeight(), target.getDepth().getMipmaps(), target.getDepth().getFormat()}
        }
    );
}

void RayLib::Drawing::endTextureMode(void) const
{
    ::EndTextureMode();
}

void RayLib::Drawing::beginBlendMode(int mode) const
{
    ::BeginBlendMode(mode);
}

void RayLib::Drawing::endBlendMode(void) const
{
    ::EndBlendMode();
}

void RayLib::Drawing::beginScissorMode(int x, int y, int width, int height) const
{
    ::BeginScissorMode(x, y, width, height);
}

void RayLib::Drawing::endScissorMode(void) const
{
    ::EndScissorMode();
}
