#include "../../include/themes/Defaults.hpp"

#include "../../include/utility/iomap.hpp"

namespace TWC::Defaults
{
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
};