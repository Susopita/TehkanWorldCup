#pragma once

#include <initializer_list>
#include <string>
#include "FieldGame.hpp"
#include "Team.hpp"
#include "Ball.hpp"

namespace TWC
{
    class Game
    {
        FieldGame *campo;
        Team *team1;
        Team *team2;
        Ball *ball;

        std::string player1;
        std::string player2;

        void setup();

    public:
        Game(std::initializer_list<const char *> path) : player1(*path.begin()), player2(*(path.begin() + 1)) {}
        void play();
        ~Game();
    };
}