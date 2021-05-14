/**
 *  @file   RayLib.cpp
 *  @brief  RayLib Encapsulation Header
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/


#ifndef BOMBERMAN_RAYLIB_HPP
#define BOMBERMAN_RAYLIB_HPP

#include <IGraphicalLibrary.hpp>
#include "raylib.h"

#if defined _WIN32 || defined __CYGWIN__
#ifdef BUILDING_DLL
    #define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
  #else
    #define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
  #endif
  #define DLL_LOCAL
#else
#if __GNUC__ >= 4
#define DLL_PUBLIC __attribute__ ((visibility ("default")))
#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define DLL_PUBLIC
    #define DLL_LOCAL
#endif
#endif

class RayLib : public IGraphicalLibrary {
public:
    RayLib(float width, float height, const std::string &title);

    size_t getElapsedTime();

private:
    Vector2 windowDimensions;
protected:
};

extern "C" DLL_PUBLIC IGraphicalLibrary *entryPointGraphicalLibrary()
{
    static RayLib lib(1920, 1080, "Bomberman");
    return &lib;
}


#endif //BOMBERMAN_RAYLIB_HPP
