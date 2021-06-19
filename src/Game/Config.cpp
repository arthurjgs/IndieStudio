/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** delivery
*/

#include <stdexcept>
#include <iostream>
#include <thread>
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#include <linux/limits.h>
#elif __APPLE__
#include <unistd.h>
#include <mach-o/dyld.h>
#endif

#include "Config.hpp"

namespace Bomberman
{
    namespace Config
    {
        std::string	  ExecutablePath(".");
        unsigned int  ThreadNumber(0);
    };

};

void  Bomberman::Config::initialize()
{
    const size_t bufSize = PATH_MAX + 1;

#ifdef _WIN32
    HMODULE handle;
  WCHAR   path[bufSize] = { 0 };

  // This error should never happen...
  handle = GetModuleHandle(nullptr);
  if (handle == nullptr)
    throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());

  GetModuleFileNameW(handle, path, MAX_PATH);
  Game::Config::ExecutablePath = std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(std::wstring(path).substr(0, std::wstring(path).find_last_of('\\') + 1));
#elif __linux__
    char  path[bufSize] = { 0 };

    // Find executable path from /proc/self/exe
    if (readlink("/proc/self/exe", path, sizeof(path) - 1) == -1)
        throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());

    Bomberman::Config::ExecutablePath = std::string(path).substr(0, std::string(path).find_last_of('/') + 1);
#elif __APPLE__
    uint32_t size = bufSize;
    char dirNameBuffer[bufSize];

    if (_NSGetExecutablePath(dirNameBuffer, &size) != 0) {
        // Buffer size is too small.
        throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());
    }
    Bomberman::Config::ExecutablePath = std::string(dirNameBuffer).substr(0, std::string(dirNameBuffer).find_last_of('/') + 1);
#endif

    // Initialize random
    std::srand((unsigned int)std::time(nullptr));

    // Detect maximum of thread concurrency.
    Bomberman::Config::ThreadNumber = std::thread::hardware_concurrency();

    // If failed...
    if (Bomberman::Config::ThreadNumber == 0) {
        Bomberman::Config::ThreadNumber = 1;
        std::cerr << "[Bomberman::Config]: Warning, failed to detect maximum of concurrency thread." << std::endl;
    }
}