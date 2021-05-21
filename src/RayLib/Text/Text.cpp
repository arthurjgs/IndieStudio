/**
 * @file Text.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Text.hpp"

RayLib::Text::Text()
{
    this->__fontPath = "Default Font";
    this->__fontSize = 12;
    this->__rayFont = ::GetFontDefault();
}

RayLib::Text::Text(const std::string &fontPath)
{
    this->__fontPath = fontPath;
    this->__fontSize = 12;
    this->__rayFont = ::LoadFont(this->__fontPath.c_str());
}

RayLib::Text::Text(const std::string &fontPath, const int &fontSize, int *&fontChars, const int &charsCount)
{
    this->__fontPath = fontPath;
    this->__fontSize = fontSize;
    this->__rayFont = ::LoadFontEx(this->__fontPath.c_str(), this->__fontSize, fontChars, charsCount);
}

RayLib::Text::Text(const std::string &fileExtension, const unsigned char *&fileData, const int &dataSize, const int &fontSize, int *&fontChars, const int &charsCount)
{
    this->__fontPath = "LoadFromMemory";
    this->__fontSize = fontSize;
    this->__rayFont = ::LoadFontFromMemory(fileExtension.c_str(), fileData, dataSize, fontSize, fontChars, charsCount);
}

void RayLib::Text::DrawFPS(int posX, int posY) const
{
    ::DrawFPS(posX, posY);
}

void RayLib::Text::DrawText(const std::string &text, int posX, int posY, int fontSize, const Type::Color &color) const
{
    ::DrawText(
        text.c_str(),
        posX,
        posY,
        fontSize,
        ::Color {color.getR(), color.getG(), color.getB(), color.getA()}
    );
}

void RayLib::Text::DrawTextEx(const std::string &text, const Type::Vector<2> position, float fontSize, float spacing, const Type::Color &tint) const
{
    ::DrawTextEx(
        this->__rayFont,
        text.c_str(),
        ::Vector2 {position.getX(), position.getY()},
        fontSize,
        spacing,
        ::Color {tint.getR(), tint.getG(), tint.getB(), tint.getA()}
    );
}

void RayLib::Text::DrawTextRec(const std::string &text, const Type::Rectangle &rec, float fontSize, float spacing, bool wordWrap, const Type::Color &tint) const
{
    ::DrawTextRec(
        this->__rayFont,
        text.c_str(),
        ::Rectangle {rec.getX(), rec.getY(), rec.getWidth(), rec.getHeight()},
        fontSize,
        spacing,
        wordWrap,
        ::Color {tint.getR(), tint.getG(), tint.getB(), tint.getA()}
    );
}

RayLib::Text::~Text()
{
    ::UnloadFont(this->__rayFont);
}