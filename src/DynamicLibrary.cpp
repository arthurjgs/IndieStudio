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

    this->_lib = ::dlopen(filename.c_str(), RTLD_LAZY);
    if (this->_lib == nullptr) {
        error = ::dlerror();
        throw DynamicLibraryException(error);
    }
}

arc::DynamicLibrary::~DynamicLibrary()
{
    ::dlclose(this->_lib);
}