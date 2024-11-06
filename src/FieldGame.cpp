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

    bool FieldGame::isGoal() const
    {
        if (ball and (ball->position.x == 0 or ball->position.x == columns - 1) and (rows / 2 - 5 < ball->position.y or ball->position.y < rows / 2 + 5))
        {
            return true;
        }
        return false;
    }

    bool FieldGame::ballIsOut(Actions::Action action, const int &distance) const
    {
        int modX{};
        int modY{};
        switch (action)
        {
        case Actions::Action::DOWN:
            modY = distance;
            break;
        case Actions::Action::UP:
            modY = -distance;
            break;
        case Actions::Action::LEFT:
            modX = -distance;
            break;
        case Actions::Action::RIGHT:
            modX = distance;
            break;
        case Actions::Action::UPLEFT:
            modY = -distance;
            modX = -distance;
            break;
        case Actions::Action::UPRIGHT:
            modY = -distance;
            modX = distance;
            break;
        case Actions::Action::DOWNLEFT:
            modY = distance;
            modX = -distance;
            break;
        case Actions::Action::DOWNRIGHT:
            modY = distance;
            modX = distance;
            break;
        }
        if (ball->position.x + modX < 0 or ball->position.x + modX > columns - 1 or ball->position.y + modY < 0 or ball->position.y + modY > rows - 1)
        {
            return true;
        }
        return false;
    }

    bool FieldGame::playerIsOut(Player *select, Actions::Action action, const int &distance) const
    {
        int modX{};
        int modY{};
        switch (action)
        {
        case Actions::Action::DOWN:
            modY = distance;
            break;
        case Actions::Action::UP:
            modY = -distance;
            break;
        case Actions::Action::LEFT:
            modX = -distance;
            break;
        case Actions::Action::RIGHT:
            modX = distance;
            break;
        case Actions::Action::UPLEFT:
            modY = -distance;
            modX = -distance;
            break;
        case Actions::Action::UPRIGHT:
            modY = -distance;
            modX = distance;
            break;
        case Actions::Action::DOWNLEFT:
            modY = distance;
            modX = -distance;
            break;
        case Actions::Action::DOWNRIGHT:
            modY = distance;
            modX = distance;
            break;
        }
        if (select->getPosition().x + modX < 0 or select->getPosition().x + modX > columns - 1 or select->getPosition().y + modY < 0 or select->getPosition().y + modY > rows - 1)
        {
            return true;
        }
        return false;
    }

};