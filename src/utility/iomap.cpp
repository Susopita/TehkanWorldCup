#include "../../include/utility/iomap.hpp"

#include <iostream>
#include <cctype>
#include "../../include/Style.hpp"

namespace TWC::Utility
{
    void moveTo(const int &x, const int &y)
    {
        std::cout << "\033[" << y << ";" << x << "H";
    }

    void clearScreen()
    {
        std::cout << "\033[2J";
    }

    void printf(const std::string &format)
    {
        std::cout << format;
    }

    std::string ToUpper(std::string str)
    {
        for (char &c : str)
        {
            c = std::toupper(c);
        }
        return str;
    }

    void update()
    {
        std::cout << std::flush;
    }

    std::string mapColor(const std::string &color)
    {
        if (color == "BLACK")
            return Style::ColorText::BLACK;
        if (color == "RED")
            return Style::ColorText::RED;
        if (color == "GREEN")
            return Style::ColorText::GREEN;
        if (color == "YELLOW")
            return Style::ColorText::YELLOW;
        if (color == "BLUE")
            return Style::ColorText::BLUE;
        if (color == "MAGENTA")
            return Style::ColorText::MAGENTA;
        if (color == "CYAN")
            return Style::ColorText::CYAN;
        if (color == "WHITE")
            return Style::ColorText::WHITE;
        if (color == "LIGHT_GRAY")
            return Style::ColorText::LIGHT_GRAY;
        if (color == "LIGHT_RED")
            return Style::ColorText::LIGHT_RED;
        if (color == "LIGHT_GREEN")
            return Style::ColorText::LIGHT_GREEN;
        if (color == "LIGHT_YELLOW")
            return Style::ColorText::LIGHT_YELLOW;
        if (color == "LIGHT_BLUE")
            return Style::ColorText::LIGHT_BLUE;
        if (color == "LIGHT_MAGENTA")
            return Style::ColorText::LIGHT_MAGENTA;
        if (color == "LIGHT_CYAN")
            return Style::ColorText::LIGHT_CYAN;
        if (color == "BRIGHT_WHITE")
            return Style::ColorText::BRIGHT_WHITE;
        return Style::ColorText::DEFAULT;
    }
} // namespace TWC::Utility