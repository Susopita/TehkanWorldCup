#pragma once

#include <string>
#include <format>

namespace TWC::Utility
{
    void moveTo(const int &x, const int &y);

    void clearScreen();

    template <class... T>
    void printf(const std::format_string<T...> &format, T &&...args);

    void printf(const std::string &format);

    std::string ToUpper(std::string str);

    std::string mapColor(const std::string &color);

    void update();
} // namespace TWC::Utility

#include "../../src/utility/iomap.tpp"