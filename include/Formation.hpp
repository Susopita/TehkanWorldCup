#pragma once

#include <vector>
#include "Player.hpp"
#include "Position.hpp"

namespace TWC
{
    class Formation
    {
    protected:
        Position goalkeeper;
        std::vector<Position> defenders;
        std::vector<Position> midfielders;
        std::vector<Position> strikers;

    public:
        virtual Position getGoalkeeper() const = 0;
        virtual std::vector<Position> getDefenders() const = 0;
        virtual std::vector<Position> getMidfielders() const = 0;
        virtual std::vector<Position> getStrikers() const= 0;
        virtual ~Formation() = default;
    };
};