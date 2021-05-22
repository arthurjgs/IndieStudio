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
            void clearBackground(Type::Color color);
            void beginDrawing(void);
            void endDrawing(void);
            void beginMode2D(Type::Camera2D camera);
            void endMode2D(void);
            void beginMode3D(Type::Camera3D camera);
            void endMode3D(void);
            void beginTextureMode(Type::RenderTexture target);
            void endTextureMode(void);
            void beginBlendMode(int mode);
            void endBlendMode(void);
            void beginScissorMode(int x, int y, int width, int height);
            void endScissorMode(void);

        protected:
        private:
    };
}

#endif /* !DRAWING_HPP_ */
