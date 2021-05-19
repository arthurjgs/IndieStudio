/**
 * @file RayLibShapes.hpp
 * @author Virgie Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef RAYLIBSHAPES_HPP_
#define RAYLIBSHAPES_HPP_

#include "../../shared/Modules/IShapes.hpp"
#include <raylib.h>

namespace rl
{
    class RayLibShapes : public module::IShapes {
        public:
            RayLibShapes() = default;
            RayLibShapes(const RayLibShapes &) = delete;
            RayLibShapes(const RayLibShapes &&) = delete;
            RayLibShapes &operator = (const RayLibShapes &) = delete;
            ~RayLibShapes() = default;

            /**
             * @brief Set texture and rectangle to be used on shapes drawing
             * 
             * @param texture 
             * @param source 
             */
            void SetShapesTexture(const Texture2D &texture, const Rectangle &source) const;
            /**
             * @brief Draw a pixel
             * 
             * @param posX 
             * @param posY 
             * @param color 
             */
            void DrawPixel(const int &posX, const int &posY, const Color &color) const;
            /**
             * @brief Draw a pixel (Vector version)
             * 
             * @param position 
             * @param color 
             */
            void DrawPixelV(const Vector2 &position, const Color &color) const;
            /**
             * @brief Draw a line
             * 
             * @param startPosX 
             * @param startPosY 
             * @param endPosX 
             * @param endPosY 
             * @param color 
             */
            void DrawLine(const int &startPosX, const int &startPosY, const int &endPosX, const int &endPosY, const Color &color) const;
            /**
             * @brief Draw a line (Vector version)
             * 
             * @param startPos 
             * @param endPos 
             * @param color 
             */
            void DrawLineV(const Vector2 &startPos, const Vector2 &endPos, const Color &color) const;
            /**
             * @brief Draw a line defining thickness
             * 
             * @param startPos 
             * @param endPos 
             * @param thick 
             * @param color 
             */
            void DrawLineEx(const Vector2 &startPos, const Vector2 &endPos, const float &thick, const Color &color) const;
            /**
             * @brief Draw a line using cubic-bezier curves in-out
             * 
             * @param startPos 
             * @param endPos 
             * @param thick 
             * @param color 
             */
            void DrawLineBezier(const Vector2 &startPos, const Vector2 &endPos, const float &thick, const Color &color) const;
            /**
             * @brief Draw line using quadratic bezier curves with a control point
             * 
             * @param startPos 
             * @param endPos 
             * @param controlPos 
             * @param thick 
             * @param color 
             */
            void DrawLineBezierQuad(const Vector2 &startPos, const Vector2 &endPos, const Vector2 &controlPos, const float &thick, const Color &color) const;
            /**
             * @brief Draw lines sequence
             * 
             * @param points 
             * @param pointsCount 
             * @param color 
             */
            void DrawLineStrip(Vector2 *&points, const int &pointsCount, const Color &color) const;
            /**
             * @brief Draw a color-filled circle
             * 
             * @param centerX 
             * @param centerY 
             * @param radius 
             * @param color 
             */
            void DrawCircle(const int &centerX, const int &centerY, const float &radius, const Color &color) const;
            /**
             * @brief Draw a piece of a circle
             * 
             * @param center 
             * @param radius 
             * @param startAngle 
             * @param endAngle 
             * @param segments 
             * @param color 
             */
            void DrawCircleSector(const Vector2 &center, const float &radius, const float &startAngle, const float &endAngle, const int &segments, const Color &color) const;
            /**
             * @brief Draw circle sector outline
             * 
             * @param center 
             * @param radius 
             * @param startAngle 
             * @param endAngle 
             * @param segments 
             * @param color 
             */
            void DrawCircleSectorLines(const Vector2 &center, const float &radius, const float &startAngle, const float &endAngle, const int &segments, const Color &color) const;
            /**
             * @brief Draw a gradient-filled circle
             * 
             * @param centerX 
             * @param centerY 
             * @param radius 
             * @param color1 
             * @param color2 
             */
            void DrawCircleGradient(const int &centerX, const int &centerY, const float &radius, const Color &color1, const Color &color2) const;
            /**
             * @brief Draw a color-filled circle (Vector version)
             * 
             * @param center 
             * @param radius 
             * @param color 
             */
            void DrawCircleV(const Vector2 &center, const float &radius, const Color &color) const;
            /**
             * @brief Draw circle outline
             * 
             * @param centerX 
             * @param centerY 
             * @param radius 
             * @param color 
             */
            void DrawCircleLines(const int &centerX, const int &centerY, const float &radius, const Color &color) const;
            /**
             * @brief Draw ellipse
             * 
             * @param centerX 
             * @param centerY 
             * @param radiusH 
             * @param radiusV 
             * @param color 
             */
            void DrawEllipse(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Color &color) const;
            /**
             * @brief Draw ellipse outline
             * 
             * @param centerX 
             * @param centerY 
             * @param radiusH 
             * @param radiusV 
             * @param color 
             */
            void DrawEllipseLines(const int &centerX, const int &centerY, const float &radiusH, const float &radiusV, const Color &color) const;
            /**
             * @brief Draw ring
             * 
             * @param center 
             * @param innerRadius 
             * @param outerRadius 
             * @param startAngle 
             * @param endAngle 
             * @param segments 
             * @param color 
             */
            void DrawRing(const Vector2 &center, const float &innerRadius, const float &outerRadius, const float &startAngle, const float &endAngle, const int &segments, const Color &color) const;
            /**
             * @brief Draw ring outline
             * 
             * @param center 
             * @param innerRadius 
             * @param outerRadius 
             * @param startAngle 
             * @param endAngle 
             * @param segments 
             * @param color 
             */
            void DrawRingLines(const Vector2 &center, const float &innerRadius, const float &outerRadius, const float &startAngle, const float &endAngle, const int &segments, const Color &color) const;
            /**
             * @brief Draw a color-filled rectangle
             * 
             * @param posX 
             * @param posY 
             * @param width 
             * @param height 
             * @param color 
             */
            void DrawRectangle(const int &posX, const int &posY, const int &width, const int &height, const Color &color) const;
            /**
             * @brief Draw a color-filled rectangle (Vector version)
             * 
             * @param position 
             * @param size 
             * @param color 
             */
            void DrawRectangleV(const Vector2 &position, const Vector2 &size, const Color &color) const;
            /**
             * @brief Draw a color-filled rectangle
             * 
             * @param rec 
             * @param color 
             */
            void DrawRectangleRec(const Rectangle &rec, const Color &color) const;
            /**
             * @brief Draw a color-filled rectangle with pro parameters
             * 
             * @param rec 
             * @param origin 
             * @param rotation 
             * @param color 
             */
            void DrawRectanglePro(const Rectangle &rec, const Vector2 &origin, const float &rotation, const Color &color) const;
            /**
             * @brief Draw a vertical-gradient-filled rectangle
             * 
             * @param posX 
             * @param posY 
             * @param width 
             * @param height 
             * @param color1 
             * @param color2 
             */
            void DrawRectangleGradientV(const int &posX, const int &posY, const int &width, const int &height, const Color &color1, const Color &color2) const;
            /**
             * @brief Draw a horizontal-gradient-filled rectangle
             * 
             * @param posX 
             * @param posY 
             * @param width 
             * @param height 
             * @param color1 
             * @param color2 
             */
            void DrawRectangleGradientH(const int &posX, const int &posY, const int &width, const int &height, const Color &color1, const Color &color2) const;
            /**
             * @brief Draw a gradient-filled rectangle with custom vertex colors
             * 
             * @param rec 
             * @param col1 
             * @param col2 
             * @param col3 
             * @param col4 
             */
            void DrawRectangleGradientEx(const Rectangle &rec, const Color &col1, const Color &col2, const Color &col3, const Color &col4) const;
            /**
             * @brief Draw rectangle outline
             * 
             * @param posX 
             * @param posY 
             * @param width 
             * @param height 
             * @param color 
             */
            void DrawRectangleLines(const int &posX, const int &posY, const int &width, const int &height, const Color &color) const;
            /**
             * @brief Draw rectangle outline with extended parameters
             * 
             * @param rec 
             * @param lineThick 
             * @param color 
             */
            void DrawRectangleLinesEx(const Rectangle &rec, const int &lineThick, const Color &color) const;
            /**
             * @brief Draw rectangle with rounded edges
             * 
             * @param rec 
             * @param roundness 
             * @param segments 
             * @param color 
             */
            void DrawRectangleRounded(const Rectangle &rec, const float &roundness, const int &segments, const Color &color) const;
            /**
             * @brief Draw rectangle with rounded edges outline
             * 
             * @param rec 
             * @param roundness 
             * @param segments 
             * @param lineThick 
             * @param color 
             */
            void DrawRectangleRoundedLines(const Rectangle &rec, const float &roundness, const int &segments, const int &lineThick, const Color &color) const;
            /**
             * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
             * 
             * @param v1 
             * @param v2 
             * @param v3 
             * @param color 
             */
            void DrawTriangle(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Color &color) const;
            /**
             * @brief Draw triangle outline (vertex in counter-clockwise order!)
             * 
             * @param v1 
             * @param v2 
             * @param v3 
             * @param color 
             */
            void DrawTriangleLines(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Color &color) const;
            /**
             * @brief Draw a triangle fan defined by points (first vertex is the center)
             * 
             * @param points 
             * @param pointsCount 
             * @param color 
             */
            void DrawTriangleFan(Vector2 *&points, const int &pointsCount, const Color &color) const;
            /**
             * @brief Draw a triangle strip defined by points
             * 
             * @param points 
             * @param pointsCount 
             * @param color 
             */
            void DrawTriangleStrip(Vector2 *&points, const int &pointsCount, const Color &color) const;
            /**
             * @brief Draw a regular polygon (Vector version)
             * 
             * @param center 
             * @param sides 
             * @param radius 
             * @param rotation 
             * @param color 
             */
            void DrawPoly(const Vector2 &center, const int &sides, const float &radius, const float &rotation, const Color &color) const;
            /**
             * @brief Draw a polygon outline of n sides
             * 
             * @param center 
             * @param sides 
             * @param radius 
             * @param rotation 
             * @param color 
             */
            void DrawPolyLines(const Vector2 &center, const int &sides, const float &radius, const float &rotation, const Color &color) const;
            /**
             * @brief Check collision between two rectangles
             * 
             * @param rec1 
             * @param rec2 
             * @return true 
             * @return false 
             */
            bool CheckCollisionRecs(const Rectangle &rec1, const Rectangle &rec2) const;
            /**
             * @brief Check collision between two circles
             * 
             * @param center1 
             * @param radius1 
             * @param center2 
             * @param radius2 
             * @return true 
             * @return false 
             */
            bool CheckCollisionCircles(const Vector2 &center1, const float &radius1, const Vector2 &center2, const float &radius2) const;
            /**
             * @brief Check collision between circle and rectangle
             * 
             * @param center 
             * @param radius 
             * @param rec 
             * @return true 
             * @return false 
             */
            bool CheckCollisionCircleRec(const Vector2 &center, const float &radius, const Rectangle &rec) const;
            /**
             * @brief Check if point is inside rectangle
             * 
             * @param point 
             * @param rec 
             * @return true 
             * @return false 
             */
            bool CheckCollisionPointRec(const Vector2 &point, const Rectangle &rec) const;
            /**
             * @brief Check if point is inside circle
             * 
             * @param point 
             * @param center 
             * @param radius 
             * @return true 
             * @return false 
             */
            bool CheckCollisionPointCircle(const Vector2 &point, const Vector2 &center, const float &radius) const;
            /**
             * @brief Check if point is inside a triangle
             * 
             * @param point 
             * @param p1 
             * @param p2 
             * @param p3 
             * @return true 
             * @return false 
             */
            bool CheckCollisionPointTriangle(const Vector2 &point, const Vector2 &p1, const Vector2 &p2, const Vector2 &p3) const;
            /**
             * @brief Check the collision between two lines defined by two points each, returns collision point by reference
             * 
             * @param startPos1 
             * @param endPos1 
             * @param startPos2 
             * @param endPos2 
             * @param collisionPoint 
             * @return true 
             * @return false 
             */
            bool CheckCollisionLines(const Vector2 &startPos1, const Vector2 &endPos1, const Vector2 &startPos2, const Vector2 &endPos2, Vector2 *&collisionPoint) const;
            /**
             * @brief Get collision rectangle for two rectangles collision
             * 
             * @param rec1 
             * @param rec2 
             * @return Rectangle 
             */
            Rectangle GetCollisionRec(const Rectangle &rec1, const Rectangle &rec2) const; 
        protected:
        private:
    };
}

#endif /* !RAYLIBSHAPES_HPP_ */
