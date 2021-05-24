/**
 *  @file   RayLibModel.cpp
 *  @brief  Ray Lib Model encapsulation
 *  @author Arthur Junges
 *  @date   2021-05-24
 **/


#include "RayLibModel.hpp"

bool replace(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}


/**
 *  IndieModel constructor
 *  this will create a model without its textures and animation
 *  It will only load the model itself without any information
 *  thus you should call setTexture and/or setAnimation before using display
 *  @param path path to the model (.iqm file, or folder containing .obj and .mtl files)
 *  @param position models position (default is 0)
 *  @param rotationAxis models position (default is 0)
 *  @param rotationAngle models position (default is 0)
 *  @param scale models position (default is 1)
 */
RayLib::IndieModel::IndieModel(const std::string &path, Vector3 position, Vector3 rotationAxis, double rotationAngle, Vector3 scale) : _animFrameCounter(0),
                                                                                                                                            _position(position),
                                                                                                                                            _rotationAngle(rotationAngle),
                                                                                                                                            _rotationAxis(rotationAxis),
                                                                                                                                            _scale(scale),
                                                                                                                                            _path(path),
                                                                                                                                            _iqmAnimCount(0),
                                                                                                                                            _animations()
{
    // TODO: CUSTOM EXCEPTIONS

    if (std::filesystem::is_directory(_path)) {
        for (const auto &file : std::filesystem::directory_iterator(path)) {
            if (file.is_regular_file() && file.path().string().find(".mtl") == std::string::npos) {
                std::string stringPath = file.path();
                _fileList.emplace_back(stringPath);
            }
        }
        std::sort(_fileList.begin(), _fileList.end());
        for (const auto &file : _fileList) {
            if (file.find(".obj") != std::string::npos)
                Models.emplace_back(LoadModel(file.c_str()));
        }
        _animType = OBJ_LIST;
    }

    if (std::filesystem::is_regular_file(_path)) {
        Models.emplace_back(LoadModel(_path.c_str()));
        _animType = IQM;
    }
}

/**
 *  Set model's texture
 *  @param path path to the texture (only supported format is png)
 *  @param materialIndex index of the materiel if the model contains more than one material (usually 0)
 */
void RayLib::IndieModel::setTexture(const std::string &path, int materialIndex)
{
    Texture2D texture = LoadTexture(path.c_str());

    for (auto & Model : Models)
        SetMaterialTexture(&Model.materials[materialIndex], MAP_DIFFUSE, texture);

    _textures.emplace_back(texture);
}

RayLib::IndieModel::~IndieModel()
{
    for (auto texture : _textures)
        UnloadTexture(texture);

    if (_animType == IQM) {
        for (int i = 0; i < _iqmAnimCount; i++) UnloadModelAnimation(_animations[i]);
        RL_FREE(_animations);
    }

    for (auto model : Models)
        UnloadModel(model);
}

/**
 *  Display model with it's animation
 *  This should be the only thing used in the loop to display the model
 */
void RayLib::IndieModel::display()
{
    switch (_animType) {

        case OBJ_LIST:
            DrawModelEx(Models[_animFrameCounter], _position, _rotationAxis, _rotationAngle, _scale, WHITE);
            _animFrameCounter++;
            if (_animFrameCounter >= Models.size()) _animFrameCounter = 0;
            break;
        case IQM:
            _animFrameCounter++;
            UpdateModelAnimation(Models[0], _animations[0], _animFrameCounter);
            if (_animFrameCounter >= _animations[0].frameCount) _animFrameCounter = 0;
            break;
    }
}

void RayLib::IndieModel::setPosition(Vector3 position)
{
    this->_position = position;
}

Vector3 RayLib::IndieModel::getPosition()
{
    return this->_position;
}

void RayLib::IndieModel::setScale(Vector3 scale)
{
    this->_scale = scale;
}

Vector3 RayLib::IndieModel::getScale()
{
    return this->_scale;
}

void RayLib::IndieModel::setRotationAxis(Vector3 rotationAxis)
{
    this->_rotationAxis = rotationAxis;
}

Vector3 RayLib::IndieModel::getRotationAxis()
{
    return this->_rotationAxis;
}

void RayLib::IndieModel::setRotationAngle(double rotationAngle)
{
    this->_rotationAngle = rotationAngle;
}

double RayLib::IndieModel::getRotationAngle()
{
    return this->_rotationAngle;
}

void RayLib::IndieModel::setAnimation(const std::string &path)
{
    _animations = LoadModelAnimations(path.c_str(), &_iqmAnimCount);
}
