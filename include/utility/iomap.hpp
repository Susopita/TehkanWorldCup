#pragma once

#include <string>
#include <format>
#include "../Position.hpp"
#include "../Style.hpp"

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

    enum class Seccion
    {
        COMPLETO,
        MITAD_SUPERIOR,
        MITAD_INFERIOR,
        MITAD_DERECHA,
        MITAD_IZQUIERDA
    };

    template <class T>
    void drawLine(const Position &begin, const Position &end, const Style::Representation<T> &draw);

    template <class T>
    void drawRectangle(const Position &begin, const Position &end, const Style::Representation<T> &draw, Seccion seccion = Seccion::COMPLETO);

    template <class T>
    void drawCircle(const Position &position, const Position &radio, const Style::Representation<T> &draw, Seccion seccion = Seccion::COMPLETO);

} // namespace TWC::Utility

#include "../../src/utility/iomap.tpp"