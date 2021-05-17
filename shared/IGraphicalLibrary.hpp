/**
 *  @file   IGraphicalLibrary.hpp
 *  @brief  Graphical Library interface
 *  @author Arthur Junges
 *  @date   2021-05-12
 **/

#ifndef BOMBERMAN_IGRAPHICALLIBRARY_HPP
#define BOMBERMAN_IGRAPHICALLIBRARY_HPP

#include <iostream>
#include "Modules/ICore.hpp"
#include "Modules/IShapes.hpp"
#include "Modules/ITextures.hpp"
#include "Modules/IText.hpp"
#include "Modules/IModels.hpp"
#include "Modules/IAudio.hpp"
#include "Modules/IPhysic.hpp"

class IGraphicalLibrary {
public:
    virtual ~IGraphicalLibrary() = default;
    virtual size_t getElapsedTime() = 0;
    virtual module::ICore &getCore() = 0;
    virtual module::IShapes &getShapes() = 0;
    virtual module::ITextures &getTextures() = 0;
    virtual module::IText &getText() = 0;
    virtual module::IModels &getModels() = 0;
    virtual module::IAudio &getAudio() = 0;
    virtual module::IPhysic &getPhysic() = 0;
};

#endif //BOMBERMAN_IGRAPHICALLIBRARY_HPP
