/**
 * @file Text.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../../Types/Color/Color.hpp"
#include "../../Types/Rectangle/Rectangle.hpp"
#include "../../Types/Vector/Vector.hpp"
#include <iostream>
#include <raylib.h>

namespace RayLib {
    class Text {
        public:
            Text();
            Text(const std::string &fontPath);
            // Load Font from TTF font file with generation parameters
            // NOTE: You can pass an array with desired characters, those characters should be available in the font
            // if array is nullptr, default char set is selected 32..126
            Text(const std::string &fontPath, const int &fontSize, int *&fontChars, const int &charsCount);
            Text(const std::string &fileExtension, const unsigned char *&fileData, const int &dataSize, const int &fontSize, int *&fontChars, const int &charsCount);
            Text(const Text &cpy) = delete;
            Text &operator = (const Text &cpy) = delete;
            ~Text();

            inline std::string &getFontPath() { return(this->__fontPath); }
            inline int &getFontSize() { return(this->__fontSize); }

            inline std::string getFontPath() const { return(this->__fontPath); }
            inline int getFontSize() const { return(this->__fontSize); }
        
            void DrawFPS(int posX, int posY) const;
            void DrawText(const std::string &text, int posX, int posY, int fontSize, const Type::Color &color) const;
            void DrawTextEx(const std::string &text, const Type::Vector<2> position, float fontSize, float spacing, const Type::Color &tint) const;
            void DrawTextRec(const std::string &text, const Type::Rectangle &rec, float fontSize, float spacing, bool wordWrap, const Type::Color &tint) const;
        protected:
        private:
            std::string __fontPath;
            int __fontSize;
            ::Font __rayFont;
    };
}