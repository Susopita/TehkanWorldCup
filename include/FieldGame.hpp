#pragma once

#include <string>
#include "Style.hpp"
#include "Team.hpp"
#include "Ball.hpp"
#include "interfaces/Presenter.hpp"

namespace TWC
{
    class FieldGame : public Graphics::Presenter
    {
    protected:
        int columns;
        int rows;
        Ball *ball;
        Team *team1;
        Team *team2;

    public:
        FieldGame() = default;
        virtual ~FieldGame();
        FieldGame &setColumns(int columns);
        FieldGame &setRows(int rows);
        FieldGame &setBall(Ball *ball);
        FieldGame &setTeam1(Team *team1);
        FieldGame &setTeam2(Team *team2);
        bool isGoal() const;
        bool ballIsOut(Actions::Action, const int &distance) const;
        bool playerIsOut(Player *select, Actions::Action action, const int &distance) const;
        int getColumns() const;
        int getRows() const;
        virtual void draw() = 0;
    };
};