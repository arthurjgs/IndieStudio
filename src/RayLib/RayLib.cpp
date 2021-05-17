/**
 *  @file   RayLib.cpp
 *  @brief  RayLib Encapsulation
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/

#include "RayLib.hpp"

RayLib::RayLib(float width, float height, const std::string &title)
{
    this->windowDimensions.x = width;
    this->windowDimensions.y = height;
}

size_t RayLib::getElapsedTime()
{
    return 0;
}
