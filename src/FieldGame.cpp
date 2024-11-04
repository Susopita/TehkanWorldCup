#include "../include/FieldGame.hpp"

namespace TWC
{
    FieldGame::~FieldGame()
    {
        ball = nullptr;
        team1 = nullptr;
        team2 = nullptr;
    }

    FieldGame &FieldGame::setColumns(int columns)
    {
        this->columns = columns;
        return *this;
    }

    FieldGame &FieldGame::setRows(int rows)
    {
        this->rows = rows;
        return *this;
    }

    FieldGame &FieldGame::setBall(Ball *ball)
    {
        this->ball = ball;
        return *this;
    }

    FieldGame &FieldGame::setTeam1(Team *team1)
    {
        this->team1 = team1;
        return *this;
    }

    FieldGame &FieldGame::setTeam2(Team *team2)
    {
        this->team2 = team2;
        return *this;
    }

    int FieldGame::getColumns() const
    {
        return columns;
    }

    int FieldGame::getRows() const
    {
        return rows;
    }
};