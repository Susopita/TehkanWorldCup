#include "../../include/utility/iomap.hpp"

#include <iostream>

namespace TWC::Utility
{
    template <class... T>
    void printf(const std::format_string<T...> &format, T &&...args)
    {
        std::cout << std::format(format, std::forward<T>(args)...);
    }

    template <class T>
    void drawLine(const Position &begin, const Position &end, const Style::Representation<T> &draw)
    {
        int x0 = begin.x;
        int y0 = begin.y;
        int x1 = end.x;
        int y1 = end.y;

        // Calcula la diferencia en x e y
        int dx = std::abs(x1 - x0);
        int dy = std::abs(y1 - y0);

        // Determina la dirección de incremento
        int sx = (x0 < x1) ? 1 : -1;
        int sy = (y0 < y1) ? 1 : -1;

        // Variable de error inicial
        int err = dx - dy;

        while (true)
        {
            // Mueve el cursor a la posición actual y dibuja el carácter
            moveTo(x0, y0);
            draw.draw();

            // Si hemos llegado al punto final, terminamos el bucle
            if (x0 == x1 && y0 == y1)
                break;

            // Calcula el error para ajustar el siguiente punto
            int e2 = 2 * err;

            // Ajuste en x
            if (e2 > -dy)
            {
                err -= dy;
                x0 += sx;
            }

            // Ajuste en y
            if (e2 < dx)
            {
                err += dx;
                y0 += sy;
            }
        }
    }

    template <class T>
    void drawRectangle(const Position &begin, const Position &end, const Style::Representation<T> &draw, Seccion seccion)
    {
        switch (seccion)
        {
        case Seccion::COMPLETO:
            drawLine(begin, {end.x, begin.y}, draw);
            drawLine({end.x, begin.y}, end, draw);
            drawLine(end, {begin.x, end.y}, draw);
            drawLine({begin.x, end.y}, begin, draw);
            break;

        case Seccion::MITAD_SUPERIOR:
            drawLine({begin.x, (end.y - begin.y) / 2}, begin, draw);
            drawLine({end.x, (end.y - begin.y) / 2}, {end.x, begin.y}, draw);
            drawLine(begin, {end.x, begin.y}, draw);
            break;

        case Seccion::MITAD_INFERIOR:
            drawLine({begin.x, (end.y - begin.y) / 2}, {begin.x, end.y}, draw);
            drawLine({end.x, (end.y - begin.y) / 2}, end, draw);
            drawLine({begin.x, end.y}, end, draw);
            break;

        case Seccion::MITAD_DERECHA:
            drawLine({(abs(end.x) - abs(begin.x)) / 2, begin.y}, {end.x, begin.y}, draw);
            drawLine({(abs(end.x) - abs(begin.x)) / 2, end.y}, end, draw);
            drawLine({end.x, begin.y}, end, draw);
            break;

        case Seccion::MITAD_IZQUIERDA:
            drawLine(begin, {end.x - (abs(end.x) - abs(begin.x)) / 2, begin.y}, draw);
            drawLine({begin.x, end.y}, {end.x - (abs(end.x) - abs(begin.x)) / 2, end.y}, draw);
            drawLine(begin, {begin.x, end.y}, draw);
            break;
        }
    }

    template <class T>
    void drawCircle(const Position &position, const Position &radio, const Style::Representation<T> &draw, Seccion seccion)
    {
        auto drawPoint = [&](int &x, int &y)
        {
            switch (seccion)
            {
            case Seccion::COMPLETO:
                moveTo(radio.x + x + position.x, radio.y + y + position.y);
                draw.draw();
                moveTo(radio.x + x + position.x, radio.y - y + position.y);
                draw.draw();
                moveTo(radio.x - x + position.x, radio.y + y + position.y);
                draw.draw();
                moveTo(radio.x - x + position.x, radio.y - y + position.y);
                draw.draw();
                break;

            case Seccion::MITAD_SUPERIOR:
                moveTo(radio.x + x + position.x, radio.y - y + position.y);
                draw.draw();
                moveTo(radio.x - x + position.x, radio.y - y + position.y);
                draw.draw();
                break;

            case Seccion::MITAD_INFERIOR:
                moveTo(radio.x + x + position.x, radio.y + y + position.y);
                draw.draw();
                moveTo(radio.x - x + position.x, radio.y + y + position.y);
                draw.draw();
                break;

            case Seccion::MITAD_DERECHA:
                moveTo(radio.x + x + position.x, radio.y + y + position.y);
                draw.draw();
                moveTo(radio.x + x + position.x, radio.y - y + position.y);
                draw.draw();
                break;

            case Seccion::MITAD_IZQUIERDA:
                moveTo(radio.x - x + position.x, radio.y + y + position.y);
                draw.draw();
                moveTo(radio.x - x + position.x, radio.y - y + position.y);
                draw.draw();
                break;
            };
        };

        int x = 0;
        int y = radio.y;

        // Decisión inicial en la región 1
        int radioX2 = radio.x * radio.x;
        int radioY2 = radio.y * radio.y;
        int dosRadioX2 = 2 * radioX2;
        int dosRadioY2 = 2 * radioY2;

        int p1 = radioY2 - (radioX2 * radio.y) + (0.25 * radioX2);

        int dx = 0;
        int dy = dosRadioX2 * y;

        // Región 1: Dibuja la parte lateral del óvalo
        while (dx < dy)
        {
            drawPoint(x, y);

            if (p1 < 0)
            {
                x++;
                dx += dosRadioY2;
                p1 += dx + radioY2;
            }
            else
            {
                x++;
                y--;
                dx += dosRadioY2;
                dy -= dosRadioX2;
                p1 += dx - dy + radioY2;
            }
        }

        // Decisión inicial en la región 2
        int p2 = (radioY2) * ((x + 0.5) * (x + 0.5)) + (radioX2) * ((y - 1) * (y - 1)) - (radioX2 * radioY2);

        // Región 2: Dibuja la parte superior e inferior del óvalo
        while (y >= 0)
        {
            drawPoint(x, y);

            if (p2 > 0)
            {
                y--;
                dy -= dosRadioX2;
                p2 += radioX2 - dy;
            }
            else
            {
                y--;
                x++;
                dx += dosRadioY2;
                dy -= dosRadioX2;
                p2 += dx - dy + radioX2;
            }
        }
    }
}