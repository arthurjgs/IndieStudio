/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_CRATES_HPP
#define BOMBERMAN_CRATES_HPP

#include <Types/Vector/Vector.hpp>
#include <Game/GameObject.hpp>

namespace Bomberman {
    class Crate : public GameObject {
    public:
        Crate(const Type::Vector<3> &position);
        ~Crate();
        void update(const double &elapsed);
        void render() const;
    protected:
    private:
    };
}


#endif //BOMBERMAN_CRATES_HPP
