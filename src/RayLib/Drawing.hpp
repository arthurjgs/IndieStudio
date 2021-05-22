/**
 * @file Drawing.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DRAWING_HPP_
#define DRAWING_HPP_

#include "../Types/Camera/Camera2D.hpp"
#include "../Types/Camera/Camera3D.hpp"
#include "../Types/RenderTexture/RenderTexture.hpp"
#include "../Types/Color/Color.hpp"

namespace RayLib
{
    class Drawing {
        public:
            Drawing();
            ~Drawing();
            void clearBackground(Type::Color color) const;
            void beginDrawing(void) const;
            void endDrawing(void) const;
            void beginMode2D(Type::Camera2D camera) const;
            void endMode2D(void) const;
            void beginMode3D(Type::Camera3D camera) const;
            void endMode3D(void) const;
            void beginTextureMode(Type::RenderTexture target) const;
            void endTextureMode(void) const;
            void beginBlendMode(int mode) const;
            void endBlendMode(void) const;
            void beginScissorMode(int x, int y, int width, int height) const;
            void endScissorMode(void) const;

        protected:
        private:
    };
}

#endif /* !DRAWING_HPP_ */
