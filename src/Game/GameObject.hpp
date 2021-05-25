/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_GAMEOBJECT_HPP
#define BOMBERMAN_GAMEOBJECT_HPP

#include "Types/Vector/Vector.hpp"

namespace Bomberman {
    class GameObject {
    public:
        enum ObjectType {
            PLAYER,
            DECOR,
            DESTRUCTIBLE,
            BOMB,
            BONUS,
            BUTTON,
            TEXT,
            CAMERA,
            MUSIC,
            SOUND
        };

        GameObject() = delete;
        GameObject(const GameObject &) = delete;
        GameObject &operator=(const GameObject &) = delete;

        GameObject(const std::string &name, ObjectType type, const Type::Vector<3> &position, bool display = true);
        virtual ~GameObject();

        void setPosition(Type::Vector<3> position);
        Type::Vector<3> getPosition();

        std::string getName() const;

        ObjectType getType();

        void setDisplay(bool display);
        bool getDisplay();

        virtual void render() = 0;
    private:
        Type::Vector<3> _position;
        std::string _name;
        ObjectType _type;
        bool _display;
    };
}

#endif //BOMBERMAN_GAMEOBJECT_HPP
