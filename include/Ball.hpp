#pragma once

#include "Position.hpp"
#include "Style.hpp"

namespace TWC
{

    struct Ball : public Style::Representation<Ball>
    {
        Position position;
        Ball();
    };
};