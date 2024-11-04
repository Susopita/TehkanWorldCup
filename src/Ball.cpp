#include "../include/Ball.hpp"

#include "../include/utility/iomap.hpp"

namespace TWC
{
    Ball::Ball()
    {
        this->position = Position(0, 0);
        this->representation = "X";
        this->style = {Style::ColorText::BLACK, Style::ColorBackground::DEFAULT};
    }

    void Ball::print(std::ostream &os) const
    {
        Utility::moveTo(position.x, position.y);
        os << representation;
    }
};