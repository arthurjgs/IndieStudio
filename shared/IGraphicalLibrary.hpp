/**
 *  @file   IGraphicalLibrary.hpp
 *  @brief  Graphical Library interface
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/

#ifndef BOMBERMAN_IGRAPHICALLIBRARY_HPP
#define BOMBERMAN_IGRAPHICALLIBRARY_HPP

#include <iostream>

class IGraphicalLibrary {
public:
    virtual ~IGraphicalLibrary() = default;
    virtual size_t getElapsedTime() = 0;
};

#endif //BOMBERMAN_IGRAPHICALLIBRARY_HPP
