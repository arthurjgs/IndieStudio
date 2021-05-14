/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#ifndef BOMBERMAN_MAIN_H
#define BOMBERMAN_MAIN_H

#if defined _WIN32 || defined __CYGWIN__
#ifdef BUILDING_DLL
    #define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
  #else
    #define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
  #endif
  #define DLL_LOCAL
#endif

#endif //BOMBERMAN_MAIN_H
