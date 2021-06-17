/**
 *  @file   DynamicLibraryException.hpp
 *  @brief  libdl-encapsulation exception header
 *  @author Arthur Junges
 *  @date   2021-03-18
 **/

#ifndef BOMBERMAN_DYNAMICLIBRARYERROR_HPP
#define BOMBERMAN_DYNAMICLIBRARYERROR_HPP

#include <exception>
#include <iostream>

/*! DynamicLibrary exception class (simple home-made exception class) */
namespace LibDl {
    class DynamicLibraryException : public std::exception {
    public:
        explicit DynamicLibraryException(std::string const &message);

        const char *what() const throw() override {
            return this->_message.c_str();
        }

    protected:
        std::string _message;
    };
}

#endif //BOMBERMAN_DYNAMICLIBRARYERROR_HPP
