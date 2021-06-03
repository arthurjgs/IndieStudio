/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include "PlayerAnimation.hpp"

Bomberman::PlayerAnimation::PlayerAnimation(const std::string &assetPath, const Type::Vector<3> &position)
{
    if (std::filesystem::is_directory(assetPath)) {
        for (auto &dir : std::filesystem::directory_iterator(assetPath)) {
            std::string path = dir.path().string();
            if (path.find("action") != std::string::npos)
                _actionAnimation = std::make_unique<RayLib::Models::Animate>(path, position);
            if (path.find("idle") != std::string::npos)
                _idleAnimation = std::make_unique<RayLib::Models::Animate>(path, position);
            if (path.find("death") != std::string::npos)
                _deathAnimation = std::make_unique<RayLib::Models::Animate>(path, position);
            if (path.find("walking") != std::string::npos)
                _walkingAnimation = std::make_unique<RayLib::Models::Animate>(path, position);
        }
    }
    else {
        throw GameException("Unable to load " + assetPath + " it's not a directory.");
    }

    for (auto &dir : std::filesystem::directory_iterator(assetPath)) {
        std::string path = dir.path().string();
        if (path.find("texture") != std::string::npos) {
            for (const auto &file : std::filesystem::directory_iterator(path)) {
                if (file.is_regular_file() && file.path().string().find(".png") != std::string::npos) {
                    _texturesList.emplace_back(file.path());
                }
            }
            std::sort(_texturesList.begin(), _texturesList.end());
            for (const auto &filePath : _texturesList) {
            std::string file = filePath.filename();
            std::cout << file.substr(0, file.find_last_of('.')) << std::endl;
                try {
                    this->_walkingAnimation->setTexture(filePath.string(), std::stoi(file.substr(0, file.find_last_of('.'))));
                    this->_idleAnimation->setTexture(filePath.string(), std::stoi(file.substr(0, file.find_last_of('.'))));
                    this->_deathAnimation->setTexture(filePath.string(), std::stoi(file.substr(0, file.find_last_of('.'))));
                    this->_actionAnimation->setTexture(filePath.string(), std::stoi(file.substr(0, file.find_last_of('.'))));
                } catch (std::invalid_argument &e) {
                    throw GameException("Unable to load texture :" + file);
                }
            }
        }
    }
}

void Bomberman::PlayerAnimation::resetAnimations()
{
    this->_walkingAnimation->resetAnim();
    this->_idleAnimation->resetAnim();
    this->_deathAnimation->resetAnim();
    this->_actionAnimation->resetAnim();
}


void Bomberman::PlayerAnimation::setScale(const Type::Vector<3> &scale)
{
    this->_walkingAnimation->setScale(scale);
    this->_idleAnimation->setScale(scale);
    this->_deathAnimation->setScale(scale);
    this->_actionAnimation->setScale(scale);
}

void Bomberman::PlayerAnimation::setRotationAngle(const float &rotation)
{
    this->_walkingAnimation->setRotationAngle(rotation);
    this->_idleAnimation->setRotationAngle(rotation);
    this->_deathAnimation->setRotationAngle(rotation);
    this->_actionAnimation->setRotationAngle(rotation);
}

void Bomberman::PlayerAnimation::render(PlayerState state, const Type::Vector<3> &position)
{
    this->_walkingAnimation->setPosition(position);
    this->_idleAnimation->setPosition(position);
    this->_deathAnimation->setPosition(position);
    this->_actionAnimation->setPosition(position);

    switch (state) {
        case IDLE:
            _idleAnimation->display();
            break;
        case WALKING:
            _walkingAnimation->display();
            break;
        case ACTION:
            _actionAnimation->display();
            break;
        case DEAD:
            _deathAnimation->display();
            break;
    }
}
