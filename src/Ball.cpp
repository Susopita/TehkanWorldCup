#include "../include/Ball.hpp"

namespace TWC
{
    Ball::Ball()
    {
        this->position = Position(0, 0);
        this->representation = "X";
        this->style = {Style::ColorText::BLACK, Style::ColorBackground::DEFAULT};
    }
};