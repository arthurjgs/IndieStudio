/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include "Bomb.hpp"

Bomberman::Bomb::Bomb(const std::string &assetPath, const Type::Vector<3> &position, double startTimer, int range) : GameObject("Bomb", BOMB, position)
{
    if (std::filesystem::is_directory(assetPath)) {
        for (auto &dir : std::filesystem::directory_iterator(assetPath)) {
            std::string path = dir.path().string();
            if (path.find("idle") != std::string::npos)
                _model = std::make_unique<RayLib::Models::Animate>(path, position);
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
                    this->_model->setTexture(filePath.string(), std::stoi(file.substr(0, file.find_last_of('.'))));
                } catch (std::invalid_argument &e) {
                    throw GameException("Unable to load texture :" + file);
                }
            }
        }
    }
    _model->setScale(Type::Vector<3>(30.0f, 30.0f, 30.0f));
    std::cout << "NEW BOMB" << std::endl;
}

Bomberman::Bomb::~Bomb()
{

}

void Bomberman::Bomb::update(const double &elapsed)
{
    
}

void Bomberman::Bomb::render() const
{
    this->_model->render();
}
