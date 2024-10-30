#pragma once

#include <initializer_list>
#include "FieldGame.hpp"
#include "Team.hpp"
#include "Ball.hpp"

namespace TWC
{

    class Game
    {
    public:
        Game(std::initializer_list<const char *> path);
        void play() const;
    };
}