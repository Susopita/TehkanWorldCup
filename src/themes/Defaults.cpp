#include "../../include/themes/Defaults.hpp"

#include "../../include/utility/iomap.hpp"

namespace TWC::Defaults
{
    // FieldGame
    void FieldGame::draw()
    {
        for (int i = 0; i < columns; i++)
        {
            Utility::moveTo(i, 0);
            BordeHorizontal.draw();
        }

        for (int i = 1; i < rows - 1; i++)
        {
            Utility::moveTo(0, i);
            BordeVertical.draw();
            Utility::moveTo(columns - 1, i);
            BordeVertical.draw();
        }

        for (int i = 0; i < columns; i++)
        {
            Utility::moveTo(i, rows - 1);
            BordeHorizontal.draw();
        }
    }

    // Formacion 1-4-3-3
    Formation1433::Formation1433(int rows, int columns, bool isLeft)
    {
        int x = 2;
        int y = rows / 2;

        goalkeeper = {x, y};

        defenders.push_back({x + 10, y - 10});
        defenders.push_back({x + 10, y - 5});
        defenders.push_back({x + 10, y + 5});
        defenders.push_back({x + 10, y + 10});

        midfielders.push_back({x + 30, y - 20});
        midfielders.push_back({x + 30, y});
        midfielders.push_back({x + 30, y + 20});

        strikers.push_back({x + 40, y - 23});
        strikers.push_back({x + 50, y});
        strikers.push_back({x + 40, y + 24});

        if (!isLeft)
        {
            goalkeeper.x = columns - goalkeeper.x;
            for (auto &defender : defenders)
            {
                defender.x = columns - defender.x;
            }
            for (auto &midfielder : midfielders)
            {
                midfielder.x = columns - midfielder.x;
            }
            for (auto &striker : strikers)
            {
                striker.x = columns - striker.x;
            }
        }
    }

    Position Formation1433::getGoalkeeper() const { return goalkeeper; }
    std::vector<Position> Formation1433::getDefenders() const { return defenders; }
    std::vector<Position> Formation1433::getMidfielders() const { return midfielders; }
    std::vector<Position> Formation1433::getStrikers() const { return strikers; }
};