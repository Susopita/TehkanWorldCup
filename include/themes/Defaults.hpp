#pragma once

#include "../FieldGame.hpp"
#include "../Style.hpp"

namespace TWC::Defaults
{
    class FieldGame : public TWC::FieldGame
    {
    protected:
        Style::Representation<std::string> BordeHorizontal = {"-",
                                                              {Style::ColorText::WHITE,
                                                               Style::ColorBackground::DEFAULT}};
        Style::Representation<std::string> BordeVertical = {"|",
                                                            {Style::ColorText::WHITE,
                                                             Style::ColorBackground::DEFAULT}};
        Style::Representation<std::string> Trazador = {"#",
                                                       {Style::ColorText::WHITE,
                                                        Style::ColorBackground::DEFAULT}};

    public:
        FieldGame() = default;
        ~FieldGame() override = default;
        void draw() override;
    };
};