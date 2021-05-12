/**
 *  @file   DynamicLibraryException.hpp
 *  @brief  libdl-encapsulation exception header
 *  @author Arthur Junges
 *  @date   2021-03-18
 **/

#ifndef ARCADE_DYNAMICLIBRARYERROR_HPP
#define ARCADE_DYNAMICLIBRARYERROR_HPP

#include <exception>
#include <iostream>

namespace arc {
    /*! DynamicLibrary exception class (simple home-made exception class) */
    class DynamicLibraryException : public std::exception
    {
    public:
        explicit DynamicLibraryException(std::string const &message);
        const char *what () const throw () override {
            return this->_message.c_str();
        }
    protected:
        std::string _message;
    };
}

#endif //ARCADE_DYNAMICLIBRARYERROR_HPP
