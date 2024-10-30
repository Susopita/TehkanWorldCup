#pragma once

#include <cmath>

namespace TWC
{
    struct Position
    {
        int x;
        int y;
        Position() : x(0), y(0) {}
        Position(int x, int y) : x(x), y(y) {}
        int distance(const Position &position) const
        {
            return pow(abs(x - position.x) + abs(y - position.y), 2);
        }
    };
};