/**
 *  @file   GameException.cpp
 *  @brief  Bomberman game exception
 *  @author Arthur Junges
 *  @date   2021-05-25
 **/

#include "GameException.hpp"

/**
 *   Exception raised by the Game class
 *   @param message the massage to be displayed in the exception.
 */
Bomberman::GameException::GameException(const std::string &message)
{
    this->_message = message;
}