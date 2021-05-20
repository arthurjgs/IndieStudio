/**
 * @file Color.hpp
 * @author Virgile Agnel
 * @brief 
 * @version 0.1
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

typedef unsigned char uChar;

namespace Type {
    /**
     * @brief class that contains color data
     * 
     */
    class Color {
        public:
            Color() = delete;
            /**
             * @brief Construct a new Color object
             * 
             * @param r 
             * @param g 
             * @param b 
             * @param a 
             */
            Color(const uChar &r, const uChar &g, const uChar &b, const uChar &a);
            /**
             * @brief Construct a new Color object
             * 
             * @param cpy 
             */
            Color(const Color &cpy);
            /**
             * @brief Construct a new Color object
             * 
             * @param cpy 
             */
            Color(const Color &&cpy);
            /**
             * @brief operator = of Color
             * 
             * @param cpy 
             * @return Color& 
             */
            Color &operator = (const Color &cpy);
            /**
             * @brief add to color together
             * 
             * @param add 
             * @return Color& 
             */
            Color operator + (const Color &add);
            ~Color() = default;
            
            /**
             * @brief get R value
             * 
             * @return uChar& 
             */
            inline uChar& getR()
            {
                return  (this->__r);
            }
            /**
             * @brief get G value
             * 
             * @return uChar& 
             */
            inline uChar& getG()
            {
                return (this->__g);             
            }
            /**
             * @brief get B value
             * 
             * @return uChar& 
             */
            inline uChar& getB()
            {
                return (this->__b);
            }
            /**
             * @brief get A value
             * 
             * @return uChar& 
             */
            inline uChar& getA()
            {
                return (this->__a);
            }
        protected:
        private:
            uChar __r;
            uChar __g;
            uChar __b;
            uChar __a;
    };
}