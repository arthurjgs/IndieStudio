/**
 *  @file   RayLib.cpp
 *  @brief  RayLib Encapsulation
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/

#include "RayLib.hpp"

rl::RayLib::RayLib(float width, float height, const std::string &title) :_rCore(width, height, title)
{
}

size_t rl::RayLib::getElapsedTime()
{
    return 0;
}

module::ICore &rl::RayLib::getCore()
{
    return _rCore;
}

module::IShapes &rl::RayLib::getShapes()
{
    return _rShapes;
}

module::ITextures &rl::RayLib::getTextures()
{
    return _rTextures;
}

module::IText &rl::RayLib::getText()
{
    return _rText;
}

module::IModels &rl::RayLib::getModels()
{
    return _rModels;
}

module::IAudio &rl::RayLib::getAudio()
{
    return _rAudio;
}

module::IPhysic &rl::RayLib::getPhysic()
{
    return _rPhysic;
}
