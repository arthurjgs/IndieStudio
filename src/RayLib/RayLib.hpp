/**
 *  @file   RayLib.cpp
 *  @brief  RayLib Encapsulation Header
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/


#ifndef BOMBERMAN_RAYLIB_HPP
#define BOMBERMAN_RAYLIB_HPP

#include <IGraphicalLibrary.hpp>
#include <raylib.h>
#include "RayLibCore.hpp"
#include "RayLibShapes.hpp"
#include "RayLibTextures.hpp"
#include "RayLibText.hpp"
#include "RayLibModels.hpp"
#include "RayLibRaudio.hpp"
#include "RayLibPhysac.hpp"

#if __GNUC__ >= 4
#define DLL_PUBLIC __attribute__ ((visibility ("default")))
#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#endif

namespace rl
{
    class RayLib : public IGraphicalLibrary {
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

#if __GNUC__ >= 4
extern "C" DLL_PUBLIC IGraphicalLibrary *entryPointGraphicalLibrary()
{
    static rl::RayLib lib(1920, 1080, "Bomberman");
    return &lib;
}
#elif defined _WIN32 || defined __CYGWIN__
extern "C" __declspec(dllexport) IGraphicalLibrary *entryPointGraphicalLibrary()
{
    static RayLib lib(1920, 1080, "Bomberman");
    return &lib;
}
#endif

#endif //BOMBERMAN_RAYLIB_HPP
