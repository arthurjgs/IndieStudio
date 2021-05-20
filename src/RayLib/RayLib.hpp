/**
 *  @file   RayLib.cpp
 *  @brief  RayLib Encapsulation Header
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/


#ifndef BOMBERMAN_RAYLIB_HPP
#define BOMBERMAN_RAYLIB_HPP

#include <raylib.h>
#include "RayLibCore.hpp"
#include "RayLibShapes.hpp"
#include "RayLibTextures.hpp"
#include "RayLibText.hpp"
#include "RayLibModels.hpp"
#include "RayLibRaudio.hpp"
#include "RayLibPhysac.hpp"

namespace rl
{
    class RayLib {
        public:
            RayLib(float width, float height, const std::string &title);
            size_t getElapsedTime();
            module::ICore &getCore();
            module::IShapes &getShapes();
            module::ITextures &getTextures();
            module::IText &getText();
            module::IModels &getModels();
            module::IAudio &getAudio();
            module::IPhysic &getPhysic();

        private:
            rl::RayLibCore _rCore;
            rl::RayLibShapes _rShapes;
            rl::RayLibTextures _rTextures;
            rl::RayLibText _rText;
            rl::RayLibModels _rModels;
            rl::RayLibRaudio _rAudio;
            rl::RayLibPhysac _rPhysic;
        protected:
    };
}

#endif //BOMBERMAN_RAYLIB_HPP
