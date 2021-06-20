/**
 *  @file   GameException.hpp
 *  @brief  Bomberman game exception header
 *  @author Arthur Junges
 *  @date   2021-05-25
 *  **/

#ifndef ARCADE_DYNAMICLIBRARYERROR_HPP
#define ARCADE_DYNAMICLIBRARYERROR_HPP

#include <exception>
#include <iostream>

/*! GameException exception class (simple home-made exception class) */
namespace Bomberman {
    class GameException : public std::exception {
    public:
        explicit GameException(std::string const &message);

        const char *what() const throw() override {
            return this->_message.c_str();
        }

    protected:
        std::string _message;
    };
}

#endif //ARCADE_DYNAMICLIBRARYERROR_HPP
