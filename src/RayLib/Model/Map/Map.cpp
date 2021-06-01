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

#include "Map.hpp"

RayLib::Models::Map::Map(const std::string &filepath, Type::Vector<3> position)
{
    _image = ::LoadImage(filepath.c_str());
    _cubicmap = ::LoadTextureFromImage(_image);
    _mesh = ::GenMeshCubicmap(_image, (Vector3){ 1.0f, 1.0f, 1.0f });
    _model = ::LoadModelFromMesh(_mesh);
    _position = position;
}

RayLib::Models::Map::~Map()
{
    ::UnloadTexture(_cubicmap);
    ::UnloadTexture(_material);
    ::UnloadModel(_model);
}

void RayLib::Models::Map::LoadMaterial(const std::string &filepath)
{
    ::UnloadTexture(_material);
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
