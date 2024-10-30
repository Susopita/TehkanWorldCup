#pragma once

#include <string>
#include "Style.hpp"
#include "Ball.hpp"

namespace TWC
{
    static const Style::Representation<std::string> BordeHorizontal = {"-",
                                                                       {Style::ColorText::BLACK,
                                                                        Style::ColorBackground::GREEN}};
    static const Style::Representation<std::string> BordeVertical = {"|",
                                                                     {Style::ColorText::BLACK,
                                                                      Style::ColorBackground::DEFAULT}};
    static const Style::Representation<std::string> Trazador = {"#",
                                                                {Style::ColorText::BLACK,
                                                                 Style::ColorBackground::DEFAULT}};
    class FieldGame
    {
        int columns;
        int rows;
        Ball *ball;
    };
};