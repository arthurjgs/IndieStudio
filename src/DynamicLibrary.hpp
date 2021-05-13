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
#include <memory>

namespace LibDl {
#ifdef __linux__
#include <dlfcn.h>
#define LIBTYPE void*
#define ERRORTYPE char*
#define OPENLIB(libname) dlopen((libname), RTLD_LAZY)
#define LIBFUNC(lib, fn) dlsym((lib), (fn))
#define ERRORLIB() dlerror()
#define CLOSELIB(LIBTYPE) dlclose(LIBTYPE)
#elif defined(_WIN32)
#include <windows.h>
#define LIBTYPE HINSTANCE
#define ERRORTYPE long
#define OPENLIB(libname) LoadLibrary(libname)
#define LIBFUNC(lib, fn) GetProcAddress((lib), (fn))
#define ERRORLIB() GetLastError()
#define CLOSELIB(LIBTYPE) FreeLibrary(LIBTYPE)
#elif __APPLE__
#include <dlfcn.h>
#define LIBTYPE void*
#define ERRORTYPE char*
#define OPENLIB(libname) dlopen((libname), RTLD_LAZY)
#define LIBFUNC(lib, fn) dlsym((lib), (fn))
#define ERRORLIB() dlerror()
#define CLOSELIB(LIBTYPE) dlclose(LIBTYPE)
#endif

/*! DynamicLibrary encapsulation class */
    class DynamicLibrary {
    public:
        DynamicLibrary(const std::string &filename);

        ~DynamicLibrary();

        template<typename T>
        T getSym(const std::string &symbol); /*!< get symbol in library */
    private:
        LIBTYPE _lib; /*!< Library loaded with dlopen */
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
T LibDl::DynamicLibrary::getSym(const std::string &symbol)
{
    T adr = nullptr;
    ERRORTYPE error = nullptr;

    error = ERRORLIB();
    if (error != nullptr) {
#if defined(_WIN32)
        throw DynamicLibraryException(std::to_string(error));
#else
        throw DynamicLibraryException(error);
#endif
    }
    adr = reinterpret_cast<T>(LIBFUNC(this->_lib, symbol.c_str()));
    error = ERRORLIB();
    if (error != nullptr) {
#if defined(_WIN32)
        throw DynamicLibraryException("Unable to open library. Reason : " + std::to_string(error));
#else
        throw DynamicLibraryException("Unable to open library. Reason : " + std::string(error));
#endif
    }
    return adr;
}/*!< get symbol in library */

#endif //ARCADE_DYNAMICLIBRARY_HPP
