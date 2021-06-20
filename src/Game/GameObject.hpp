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
        enum GameObjectState {
            ALIVE,
            DESTROYED
        };

        enum ObjectType {
            PLAYER,
            DECOR,
            DESTRUCTIBLE,
            BOMB,
            FLAME,
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
        Type::Vector<3> getPosition() const;

        std::string getName() const;

        ObjectType getType() const;
        GameObjectState getState() const;

        void setDisplay(bool display);
        bool getDisplay() const;
        void destroy();

        virtual void render() const = 0;
        virtual void update(const double &elapsed) = 0;

    protected:
        Type::Vector<3> _position;
        std::string _name;
        ObjectType _type;
        bool _display;
        GameObjectState _state;
    private:
    };
}

#endif //BOMBERMAN_GAMEOBJECT_HPP
