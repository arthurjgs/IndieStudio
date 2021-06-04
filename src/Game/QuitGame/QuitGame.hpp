/**
 * @file QuitGame.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

namespace Bomberman {
    class QuitGame : public std::exception {
        public:
            QuitGame() = default;
            ~QuitGame() throw() = default;

            inline const char *what(void) const throw()
            {
                return ("Closing application");
            }
        protected:
        private:
    };
}