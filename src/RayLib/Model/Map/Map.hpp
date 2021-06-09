/**
 * @file Map.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#ifndef MAP_HPP_
#define MAP_HPP_

#include <raylib.h>
#include <iostream>
#include <vector>
#include "../../../Types/Color/Color.hpp"
#include "../../../Types/Vector/Vector.hpp"

namespace RayLib
{
    namespace Models
    {
        class Map {
            public:
                Map() = delete;
                Map(const std::string &filepath, Type::Vector<3> position);
                ~Map();
                void LoadMaterial(const std::string &filepath);
                Type::Vector<2> getCubicMap() const;
                std::vector<Type::Color> getMapPixels();
                void setPostionMap(Type::Vector<3> position);
                void drawMap(float scale, Type::Color tint);
            protected:
            private:
                Model _model;
                Mesh _mesh;
                Color *_mapPixels;
                Texture2D _cubicmap;
                Texture2D _material;
                Type::Vector<3> _position;
        };
    }
}

#endif /* !MAP_HPP_ */
