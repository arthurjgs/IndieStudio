/**
 * @file Map.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <vector>
#include "Map.hpp"

RayLib::Models::Map::Map(const std::string &filepath, Type::Vector<3> position) : _size(0)
{
    auto image = ::LoadImage(filepath.c_str());

    _cubicmap = ::LoadTextureFromImage(image);
    _mesh = ::GenMeshCubicmap(image, ::Vector3{ 1.0f, 1.0f, 1.0f });
    _model = ::LoadModelFromMesh(_mesh);
    _mapPixels = ::LoadImageColors(image);
    _position = position;
    _size = image.width * image.height;
    _width = image.width;
    _height = image.height;

    ::UnloadImage(image);
}

RayLib::Models::Map::~Map()
{
    ::UnloadTexture(_cubicmap);
    ::UnloadTexture(_material);
    ::UnloadModel(_model);
    ::UnloadImageColors(_mapPixels);
}

void RayLib::Models::Map::LoadMaterial(const std::string &filepath)
{
    _material = ::LoadTexture(filepath.c_str());
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _material;
}

void RayLib::Models::Map::setPostionMap(Type::Vector<3> position)
{
    _position = position;
}

void RayLib::Models::Map::drawMap(float scale, Type::Color tint)
{
    ::DrawModel(_model,
    ::Vector3 {_position.getX(), _position.getY(), _position.getZ()},
    scale,
    ::Color {tint.getR(), tint.getG(), tint.getB(), tint.getA()});
}

Type::Vector<2> RayLib::Models::Map::getCubicMap() const
{
    return Type::Vector<2>(static_cast<float>(_cubicmap.width), static_cast<float>(_cubicmap.height));
}

std::vector<Type::Color> RayLib::Models::Map::getMapPixels()
{
    std::vector<Type::Color> colors = std::vector<Type::Color>();

    for(int i = 0; i < _size; i++)
    {
        Color c = _mapPixels[i];
        colors.emplace_back(Type::Color(c.r, c.g, c.b, c.a));
    }

    return colors;
}

int RayLib::Models::Map::getWidth()
{
    return this->_width;
}

int RayLib::Models::Map::getHeight()
{
    return this->_height;
}
