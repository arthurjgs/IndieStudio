/**
 *  @file   DynamicLibrary.cpp
 *  @brief  libdl-encapsulation
 *  @author Arthur Junges
 *  @date   2021-03-18
 **/

#include "DynamicLibrary.hpp"

/**
 *   Encapsulation of libdl.h
 *   @param filename path of the library.
 */
arc::DynamicLibrary::DynamicLibrary(const std::string &filename) : _lib(nullptr)
{
    char *error = nullptr;

    this->_lib = ::OPENLIB(filename.c_str());
    if (this->_lib == nullptr) {
        error = ::ERRORLIB();
        throw DynamicLibraryException(error);
    }
}

arc::DynamicLibrary::~DynamicLibrary()
{
    ::CLOSELIB(this->_lib);
}