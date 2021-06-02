/**
 *  @file   RayLibModel.cpp
 *  @brief  Ray Lib Model encapsulation
 *  @author Arthur Junges
 *  @date   2021-05-24
 **/


#include "Animate.hpp"

bool replace(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}


/**
 *  Animate constructor
 *  this will create a model without its textures and animation
 *  It will only load the model itself without any information
 *  thus you should call setTexture and/or setAnimation before using display
 *  @param path path to the model (.iqm file, or folder containing .obj and .mtl files)
 *  @param position models position (default is 0)
 *  @param rotationAxis models position (default is 0)
 *  @param rotationAngle models position (default is 0)
 *  @param scale models position (default is 1)
 */
RayLib::Models::Animate::Animate(const std::string &path, const Type::Vector<3> &position, const Type::Vector<3> &rotationAxis, double rotationAngle, const Type::Vector<3> &scale) : 
_path(path),
_animFrameCounter(0),
_iqmAnimCount(0),
_animations(),
_rotationAngle(rotationAngle)
{
    // TODO: CUSTOM EXCEPTIONS
    this->_position.x = position.getX();
    this->_position.y = position.getY();
    this->_position.z = position.getZ();
    this->_rotationAxis.x = rotationAxis.getX();
    this->_rotationAxis.y = rotationAxis.getY();
    this->_rotationAxis.z = rotationAxis.getZ();
    this->_scale.x = scale.getX();
    this->_scale.y = scale.getY();
    this->_scale.z = scale.getZ();
    if (std::filesystem::is_directory(_path)) {
        for (const auto &file : std::filesystem::directory_iterator(path)) {
            if (file.is_regular_file() && file.path().string().find(".mtl") == std::string::npos) {
                std::string stringPath = file.path().string();
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
void RayLib::Models::Animate::setTexture(const std::string &path, int materialIndex)
{
    Texture2D texture = LoadTexture(path.c_str());

    for (auto & Model : Models)
        SetMaterialTexture(&Model.materials[materialIndex], MAP_DIFFUSE, texture);

    _textures.emplace_back(texture);
}

RayLib::Models::Animate::~Animate()
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
void RayLib::Models::Animate::display()
{
    switch (_animType) {

        case OBJ_LIST:
            DrawModelEx(Models[_animFrameCounter], _position, _rotationAxis, _rotationAngle, _scale, WHITE);
            _animFrameCounter++;
            if (_animFrameCounter >= static_cast<int>(Models.size())) _animFrameCounter = 0;
            break;
        case IQM:
            _animFrameCounter++;
            UpdateModelAnimation(Models[0], _animations[0], _animFrameCounter);
            if (_animFrameCounter >= _animations[0].frameCount) _animFrameCounter = 0;
            break;
    }
}

void RayLib::Models::Animate::setPosition(const Type::Vector<3> &position)
{
    this->_position.x = position.getX();
    this->_position.y = position.getY();
    this->_position.z = position.getZ();
}

Type::Vector<3> RayLib::Models::Animate::getPosition()
{
    return (Type::Vector<3>(this->_position.x, this->_position.y, this->_position.z));
}

void RayLib::Models::Animate::setScale(const Type::Vector<3> &scale)
{
    this->_scale.x = scale.getX();
    this->_scale.y = scale.getY();
    this->_scale.z = scale.getZ();
}

Type::Vector<3> RayLib::Models::Animate::getScale()
{
    return (Type::Vector<3>(this->_scale.x, this->_scale.y, this->_scale.z));
}

void RayLib::Models::Animate::setRotationAxis(const Type::Vector<3> &rotationAxis)
{
    this->_rotationAxis.x = rotationAxis.getX();
    this->_rotationAxis.y = rotationAxis.getY();
    this->_rotationAxis.z = rotationAxis.getZ();
}

Type::Vector<3> RayLib::Models::Animate::getRotationAxis()
{
    return (Type::Vector<3>(this->_rotationAxis.x, this->_rotationAxis.y, this->_rotationAxis.z));
}

double RayLib::Models::Animate::getRotationAngle()
{
    return this->_rotationAngle;
}

void RayLib::Models::Animate::setAnimation(const std::string &path)
{
    _animations = LoadModelAnimations(path.c_str(), &_iqmAnimCount);
}

void RayLib::Models::Animate::setRotationAngle(float rotationAngle)
{
    this->_rotationAngle = rotationAngle;
}

void RayLib::Models::Animate::resetAnim()
{
    this->_animFrameCounter = 0;
    this->_iqmAnimCount = 0;
}
