/**
 *  @file   DynamicLibraryException.cpp
 *  @brief  libdl-encapsulation exception
 *  @author Arthur Junges
 *  @date   2021-03-18
 **/

#include "DynamicLibraryException.hpp"

/**
 *   Exception raised by the DynamicLibrary class
 *   @param message the massage to be displayed in the exception.
 */
LibDl::DynamicLibraryException::DynamicLibraryException(const std::string &message)
{
    this->_message = message;
}