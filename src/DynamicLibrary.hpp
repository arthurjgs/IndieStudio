/**
 *  @file   DynamicLibrary.hpp
 *  @brief  libdl-encapsulation header
 *  @author Arthur Junges
 *  @date   2021-03-18
 **/

#ifndef ARCADE_DYNAMICLIBRARY_HPP
#define ARCADE_DYNAMICLIBRARY_HPP

#include <string>
#include "DynamicLibraryException.hpp"
#include "../shared/IEngines.hpp"
#include <dlfcn.h>
#include <memory>

/*! DynamicLibrary encapsulation class */
namespace arc {
    class DynamicLibrary {
    public:
        DynamicLibrary(const std::string &filename);
        ~DynamicLibrary();
        template <typename T>
        T getSym(const std::string &symbol); /*!< get symbol in library */
    private:
        void *_lib; /*!< Library loaded with dlopen */
    };
}

/**
 *   Get Symbol in library previously loaded
 *   @param symbol the symbol to look for.
 *   @return address of the symbol in the lib, if lib
 *   is null or if th symbol cannot be found,
 *   an exception will be raised
 */
template<typename T>
T arc::DynamicLibrary::getSym(const std::string &symbol)
{
    T adr = nullptr;
    char *error = nullptr;

    error = ::dlerror();
    if (error != nullptr)
        throw DynamicLibraryException(error);
    adr = reinterpret_cast<T>(::dlsym(this->_lib, symbol.c_str()));
    error = ::dlerror();
    if (error != nullptr)
        throw DynamicLibraryException("Unable to open library. Reason : " + std::string(error));
    return adr;
}/*!< get symbol in library */

#endif //ARCADE_DYNAMICLIBRARY_HPP
