/**
 *  @file   DynamicLibrary.cpp
 *  @brief  libdl-encapsulation
 *  @author Arthur Junges
 *  @date   2021-03-18
 **/

#include "DynamicLibrary.hpp"
#include "DynamicLibraryException.hpp"

/**
 *   Encapsulation of libdl.h
 *   @param filename path of the library.
 */
LibDl::DynamicLibrary::DynamicLibrary(const std::string &filename)
{
    ERRORTYPE error;

    this->_lib = LibDl::OPENLIB(filename.c_str());
    if (this->_lib == nullptr) {
        error = LibDl::ERRORLIB();
#if defined(_WIN32)
        throw DynamicLibraryException(std::to_string(error));
#else
        throw DynamicLibraryException(error);
#endif
    }
}

LibDl::DynamicLibrary::~DynamicLibrary()
{
    LibDl::CLOSELIB(this->_lib);
}