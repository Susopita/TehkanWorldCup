#pragma once

#include <iostream>
#include "Position.hpp"
#include "Style.hpp"

namespace TWC
{

    struct Ball : public Style::Representation<Ball>
    {
        Position position;
        Ball();
        void print(std::ostream &os) const override;
    };
};