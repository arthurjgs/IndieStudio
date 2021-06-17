/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_CONFIG_HPP
#define BOMBERMAN_CONFIG_HPP

#include <string>

namespace Bomberman
{
    namespace Config
    {
        void  initialize();
        extern std::string  ExecutablePath; // Path to the executable (without executable name, '/' or '\' terminated)
        extern unsigned int ThreadNumber;   // Number of maximum parallele threads
    };
}

#endif //BOMBERMAN_CONFIG_HPP
