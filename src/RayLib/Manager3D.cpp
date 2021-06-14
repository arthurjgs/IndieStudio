/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include "Manager3D.hpp"

RayLib::Manager3D &RayLib::Manager3D::getInstance()
{
    static RayLib::Manager3D manager = RayLib::Manager3D(NONE);
    return (manager);
}

RayLib::Manager3D::Manager3D(RayLib::Manager3D::Scene scene) : _currentScene(scene)
{
}

void RayLib::Manager3D::setScene(RayLib::Manager3D::Scene nextScene)
{
    _models.clear();
    this->_currentScene = nextScene;
    load3DModels();
}

void RayLib::Manager3D::loadPlayers()
{
    if (std::filesystem::is_directory("assets/models/players")) {
        for (auto &dir : std::filesystem::directory_iterator("assets/models/players")) {
            if (std::filesystem::is_directory(dir)) {
                for (auto &subDir : std::filesystem::directory_iterator(dir.path().string())) {
                    std::string path = subDir.path().string();
                    if (path.find("action") != std::string::npos)
                        _models[dir.path().filename().string() + "ACTION"] = std::make_shared<RayLib::Models::Animate>(path);
                    if (path.find("idle") != std::string::npos)
                        _models[dir.path().filename().string() + "IDLE"] = std::make_shared<RayLib::Models::Animate>(path);
                    if (path.find("death") != std::string::npos)
                        _models[dir.path().filename().string() + "DEAD"] = std::make_shared<RayLib::Models::Animate>(path);
                    if (path.find("walking") != std::string::npos)
                        _models[dir.path().filename().string() + "WALKING"] = std::make_shared<RayLib::Models::Animate>(path);
                }
            }
            else {
                throw Bomberman::GameException("Unable to load " + dir.path().string() + " it's not a directory.");
            }

            for (auto &subDir : std::filesystem::directory_iterator(dir.path().string())) {
                std::string path = subDir.path().string();
                if (path.find("texture") != std::string::npos) {
                    for (const auto &filePath : std::filesystem::directory_iterator(path)) {
                        std::string file = filePath.path().filename().string();
                        try {
                            _models[dir.path().filename().string() + "WALKING"]->setTexture(filePath.path().string(),
                                                                std::stoi(file.substr(0, file.find_last_of('.'))));
                            _models[dir.path().filename().string() + "IDLE"]->setTexture(filePath.path().string(),
                                                             std::stoi(file.substr(0, file.find_last_of('.'))));
                            _models[dir.path().filename().string() + "DEAD"]->setTexture(filePath.path().string(),
                                                              std::stoi(file.substr(0, file.find_last_of('.'))));
                            _models[dir.path().filename().string() + "ACTION"]->setTexture(filePath.path().string(),
                                                               std::stoi(file.substr(0, file.find_last_of('.'))));
                        } catch (std::invalid_argument &e) {
                            throw Bomberman::GameException("Unable to load texture :" + file);
                        }
                    }
                }
            }
        }
    }
}

void RayLib::Manager3D::loadObjects()
{
    if (std::filesystem::is_directory("assets/models/objects")) {
        for (auto &dir : std::filesystem::directory_iterator("assets/models/objects")) {
            if (std::filesystem::is_directory(dir)) {
                for (auto &subDir : std::filesystem::directory_iterator(dir.path().string())) {
                    std::string path = subDir.path().string();
                    if (path.find("idle") != std::string::npos)
                        _models[dir.path().filename().string()] = std::make_shared<RayLib::Models::Animate>(path);
                    }
            }
            else {
                throw Bomberman::GameException("Unable to load " + dir.path().string() + " it's not a directory.");
            }

            for (auto &subDir : std::filesystem::directory_iterator(dir.path().string())) {
                std::string path = dir.path().string();
                if (path.find("texture") != std::string::npos) {
                    for (const auto &filePath : std::filesystem::directory_iterator(path)) {
                        std::string file = filePath.path().filename().string();
                        try {
                            _models[dir.path().filename().string()]->setTexture(filePath.path().string(),
                                                                                             std::stoi(file.substr(0, file.find_last_of('.'))));
                        }
                        catch (std::invalid_argument &e) {
                            throw Bomberman::GameException("Unable to load texture :" + file);
                        }
                    }
                }
            }
        }
    }
}

void RayLib::Manager3D::load3DModels()
{
    switch (this->_currentScene) {
        case NONE:
            break;
        case GAME:
            loadPlayers();
            loadObjects();
            break;
        case PLAYER_SELECTION:
            break;
        case MAP_SELECTION:
            break;
    }
}

std::shared_ptr<RayLib::Models::Animate> RayLib::Manager3D::getModel(const std::string &object)
{
    for (auto & model : this->_models) {
        if (model.first == object)
            return model.second;
    }
    return nullptr;
}

RayLib::Manager3D::~Manager3D() = default;
