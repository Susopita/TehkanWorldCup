#pragma once

#include "../FieldGame.hpp"
#include "../Style.hpp"
#include "../Formation.hpp"

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

    class Formation1433 : public TWC::Formation
    {
    public:
        Formation1433(int rows, int columns, bool isLeft = true);

        Position getGoalkeeper() const override;
        std::vector<Position> getDefenders() const override;
        std::vector<Position> getMidfielders() const override;
        std::vector<Position> getStrikers() const override;

        ~Formation1433() override = default;
    };
};