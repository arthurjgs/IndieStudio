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

class RayLib : IGraphicalLibrary{
public:
    RayLib(float width, float height, const std::string &title);
    size_t getElapsedTime();
private:
    Vector2 windowDimensions;
protected:
};

#endif //BOMBERMAN_RAYLIB_HPP
