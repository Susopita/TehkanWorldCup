#include "../../include/themes/Defaults.hpp"

#include "../../include/utility/iomap.hpp"

namespace TWC::Defaults
{
    // FieldGame
    void FieldGame::draw()
    {
        // Bordes
        Utility::drawLine({0, 0}, {columns - 1, 0}, BordeHorizontal);
        Utility::drawLine({0, rows - 1}, {columns - 1, rows - 1}, BordeHorizontal);
        Utility::drawLine({0, 0}, {0, rows - 1}, BordeVertical);
        Utility::drawLine({columns - 1, 0}, {columns - 1, rows - 1}, BordeVertical);

        // Patrones
        Utility::drawRectangle({-5, (rows - 13) / 2}, {5, (rows - 13) / 2 + 13}, Trazador, Utility::Seccion::MITAD_DERECHA);
        Utility::drawRectangle({-10, (rows - 27) / 2}, {10, (rows - 27) / 2 + 27}, Trazador, Utility::Seccion::MITAD_DERECHA);
        Utility::drawCircle({10 - 8, rows / 2 - 8}, {8, 8}, Trazador, Utility::Seccion::MITAD_DERECHA);

        Utility::drawRectangle({columns - 5, (rows - 13) / 2}, {columns + 5, (rows - 13) / 2 + 13}, Trazador, Utility::Seccion::MITAD_IZQUIERDA);
        Utility::drawRectangle({columns - 10, (rows - 27) / 2}, {columns + 10, (rows - 27) / 2 + 27}, Trazador, Utility::Seccion::MITAD_IZQUIERDA);
        Utility::drawCircle({columns - 10 - 8, rows / 2 - 8}, {8, 8}, Trazador, Utility::Seccion::MITAD_IZQUIERDA);

        Utility::drawCircle({columns / 2 - 9, rows / 2 - 9}, {9, 9}, Trazador);
        Utility::drawLine({columns / 2, rows / 2 - 9}, {columns / 2, 0}, Trazador);
        Utility::drawLine({columns / 2, rows / 2 + 9}, {columns / 2, rows}, Trazador);
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