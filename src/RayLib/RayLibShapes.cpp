/**
 * @file RayLibShapes.cpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "RayLibShapes.hpp"

void rl::RayLibShapes::SetShapesTexture(const Texture2D &texture, const Rectangle &source) const
{
    ::SetShapesTexture(texture, source);
}

void rl::RayLibShapes::DrawPixel(const int &posX, const int &posY, const Color &color) const
{
    ::DrawPixel(posX, posY, color);
}

void rl::RayLibShapes::DrawPixelV(const Vector2 &position, const Color &color) const
{
    ::DrawPixelV(position, color);
}

void rl::RayLibShapes::DrawLine(const int &startPosX, const int &startPosY, const int &endPosX, const int &endPosY, const Color &color) const
{
    ::DrawLine(startPosX, startPosY, endPosX, endPosY, color);
}

void rl::RayLibShapes::DrawLineV(const Vector2 &startPos, const Vector2 &endPos, const Color &color) const
{
    ::DrawLineV(startPos, endPos, color);
}

void rl::RayLibShapes::DrawLineEx(const Vector2 &startPos, const Vector2 &endPos, const float &thick, const Color &color) const
{
    ::DrawLineEx(startPos, endPos, thick, color);
}

void rl::RayLibShapes::DrawLineBezier(const Vector2 &startPos, const Vector2 &endPos, const float &thick, const Color &color) const
{
    ::DrawLineBezier(startPos, endPos, thick, color);
}

void rl::RayLibShapes::DrawLineBezierQuad(const Vector2 &startPos, const Vector2 &endPos, const Vector2 &controlPos, const float &thick, const Color &color) const
{
    ::DrawLineBezierQuad(startPos, endPos, controlPos, thick, color);
}

void rl::RayLibShapes::DrawLineStrip(Vector2 *&points, const int &pointsCount, const Color &color) const
{
    ::DrawLineStrip(points, pointsCount, color);
}

void rl::RayLibShapes::DrawCircle(const int &centerX, const int &centerY, const float &radius, const Color &color) const
{
    ::DrawCircle(centerX, centerY, radius, color);
}

void rl::RayLibShapes::DrawCircleSector(const Vector2 &center, const float &radius, const float &startAngle, const float &endAngle, const int &segments, const Color &color) const
{
    ::DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
}   

void rl::RayLibShapes::DrawCircleSectorLines(const Vector2 &center, const float &radius, const float &startAngle, const float &endAngle, const int &segments, const Color &color) const
{
    ::DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
}

void rl::RayLibShapes::DrawCircleGradient(const int &centerX, const int &centerY, const float &radius, const Color &color1, const Color &color2) const
{
    ::DrawCircleGradient(centerX, centerY, radius, color1, color2);
}

void rl::RayLibShapes::DrawCircleV(const Vector2 &center, const float &radius, const Color &color) const
{
    ::DrawCircleV(center, radius, color);
}

void rl::RayLibShapes::DrawCircleLines(const int &centerX, const int &centerY, const float &radius, const Color &color) const
{
    ::DrawCircleLines(centerX, centerY, radius, color);
}

void rl::RayLibShapes::DrawEllipse(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Color &color) const
{
    ::DrawEllipse(centerX, centerY, radiusH, radiusV, color);
}

void rl::RayLibShapes::DrawEllipseLines(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Color &color) const
{
    ::DrawEllipseLines(centerX, centerY, radiusH, radiusV, color);
}

void rl::RayLibShapes::DrawRing(const Vector2 &center, const float &innerRadius, const float &outerRadius, const float &startAngle, const float &endAngle, const int &segments, const Color &color) const
{
    ::DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}

void rl::RayLibShapes::DrawRingLines(const Vector2 &center, const float &innerRadius, const float &outerRadius, const float &startAngle, const float &endAngle, const int &segments, const Color &color) const
{
    ::DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}

void rl::RayLibShapes::DrawRectangle(const int &posX, const int &posY, const int &width, const int &height, const Color &color) const
{
    ::DrawRectangle(posX, posY, width, height, color);
}

void rl::RayLibShapes::DrawRectangleV(const Vector2 &position, const Vector2 &size, const Color &color) const
{
    ::DrawRectangleV(position, size, color);
}

void rl::RayLibShapes::DrawRectangleRec(const Rectangle &rec, const Color &color) const
{
    ::DrawRectangleRec(rec, color);
}

void rl::RayLibShapes::DrawRectanglePro(const Rectangle &rec, const Vector2 &origin, const float &rotation, const Color &color) const
{
    ::DrawRectanglePro(rec, origin, rotation, color);
}

void rl::RayLibShapes::DrawRectangleGradientV(const int &posX, const int &posY, const int &width, const int &height, const Color &color1, const Color &color2) const
{
    ::DrawRectangleGradientV(posX, posY, width, height, color1, color2);
}

void rl::RayLibShapes::DrawRectangleGradientH(const int &posX, const int &posY, const int &width, const int &height, const Color &color1, const Color &color2) const
{
    ::DrawRectangleGradientH(posX, posY, width, height, color1, color2);
}

void rl::RayLibShapes::DrawRectangleGradientEx(const Rectangle &rec, const Color &col1, const Color &col2, const Color &col3, const Color &col4) const
{
    ::DrawRectangleGradientEx(rec, col1, col2, col3, col4);
}

void rl::RayLibShapes::DrawRectangleLines(const int &posX, const int &posY, const int &width, const int &height, const Color &color) const
{
    ::DrawRectangleLines(posX, posY, width, height, color);
}

void rl::RayLibShapes::DrawRectangleLinesEx(const Rectangle &rec, const int &lineThick, const Color &color) const
{
    ::DrawRectangleLinesEx(rec, lineThick, color);
}

void rl::RayLibShapes::DrawRectangleRounded(const Rectangle &rec, const float &roundness, const int &segments, const Color &color) const
{
    ::DrawRectangleRounded(rec, roundness, segments, color);
}

void rl::RayLibShapes::DrawRectangleRoundedLines(const Rectangle &rec, const float &roundness, const int &segments, const int &lineThick, const Color &color) const
{
    ::DrawRectangleRoundedLines(rec, roundness, segments, lineThick, color);
}

void rl::RayLibShapes::DrawTriangle(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Color &color) const
{
    ::DrawTriangle(v1, v2, v3, color);
}

void rl::RayLibShapes::DrawTriangleLines(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Color &color) const
{
    ::DrawTriangleLines(v1, v2, v3, color);
}

void rl::RayLibShapes::DrawTriangleFan(Vector2 *&points, const int &pointsCount, const Color &color) const
{
    ::DrawTriangleFan(points, pointsCount, color);
}

void rl::RayLibShapes::DrawTriangleStrip(Vector2 *&points, const int &pointsCount, const Color &color) const
{
    ::DrawTriangleStrip(points, pointsCount, color);
}

void rl::RayLibShapes::DrawPoly(const Vector2 &center, const int &sides, const float &radius, const float &rotation, const Color &color) const
{
    ::DrawPoly(center, sides, radius, rotation, color);
}

void rl::RayLibShapes::DrawPolyLines(const Vector2 &center, const int &sides, const float &radius, const float &rotation, const Color &color) const
{
    ::DrawPolyLines(center, sides, radius, rotation, color);
}

bool rl::RayLibShapes::CheckCollisionRecs(const Rectangle &rec1, const Rectangle &rec2) const
{
    return (::CheckCollisionRecs(rec1, rec2));
}

bool rl::RayLibShapes::CheckCollisionCircles(const Vector2 &center1, const float &radius1, const Vector2 &center2, const float &radius2) const
{
    return (::CheckCollisionCircles(center1, radius1, center2, radius2));
}

bool rl::RayLibShapes::CheckCollisionCircleRec(const Vector2 &center, const float &radius, const Rectangle &rec) const
{
    return (::CheckCollisionCircleRec(center, radius, rec));
}

bool rl::RayLibShapes::CheckCollisionPointRec(const Vector2 &point, const Rectangle &rec) const
{
    return (::CheckCollisionPointRec(point, rec));
}

bool rl::RayLibShapes::CheckCollisionPointCircle(const Vector2 &point, const Vector2 &center, const float &radius) const
{
    return (::CheckCollisionPointCircle(point, center, radius));
}

bool rl::RayLibShapes::CheckCollisionPointTriangle(const Vector2 &point, const Vector2 &p1, const Vector2 &p2, const Vector2 &p3) const
{
    return (::CheckCollisionPointTriangle(point, p1, p2, p3));
}

bool rl::RayLibShapes::CheckCollisionLines(const Vector2 &startPos1, const Vector2 &endPos1, const Vector2 &startPos2, const Vector2 &endPos2, Vector2 *&collisionPoint) const
{
    return (::CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, collisionPoint));
}

Rectangle rl::RayLibShapes::GetCollisionRec(const Rectangle &rec1, const Rectangle &rec2) const
{
    return (::GetCollisionRec(rec1, rec2));
}