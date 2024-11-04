#include "../include/Game.hpp"

#include <iostream>
#include <limits>
#include "../include/utility/iomap.hpp"
#include "../include/themes/Defaults.hpp"

namespace TWC
{
    void Game::setup()
    {
        campo = new Defaults::FieldGame();
        ball = new Ball();
        team1 = new Team();
        team2 = new Team();

        int rows = 51;
        int columns = 121;

        ball->setRepresentation("X")
            .setStyle({Style::ColorText::BLACK,
                       Style::ColorBackground::DEFAULT})
            .position = Position(columns / 2 - 2, rows / 2);

        team1->setCoach(Coach("Suso"))
            .setFormation(Formation())
            .setTeamSize(11)
            .setFocus(ball)
            .setColor(Utility::mapColor(player1));

        team2->setCoach(Coach("Pita"))
            .setFormation(Formation())
            .setTeamSize(11)
            .setFocus(ball)
            .setColor(Utility::mapColor(player2));

        campo->setColumns(columns)
            .setRows(rows)
            .setBall(ball)
            .setTeam1(team1)
            .setTeam2(team2);

        Utility::clearScreen();

        campo->draw();
        ball->draw();
        team1->draw();
        team2->draw();

        int padding_down_to_field = 2;

        Utility::moveTo(0, campo->getRows() + padding_down_to_field);
        Utility::printf((std::string) " " + std::string(40, '-'));

        Utility::moveTo(0, campo->getRows() + padding_down_to_field + 1);
        Utility::printf("|");

        Utility::moveTo(42, campo->getRows() + padding_down_to_field + 1);
        Utility::printf("|");

        Utility::moveTo(0, campo->getRows() + padding_down_to_field + 2);
        Utility::printf((std::string) " " + std::string(40, '-'));

        Utility::update();
    }

    void Game::play()
    {
        setup();
        std::string select_player, action, choice, distance, team;
        bool turn = true;
        bool repeat = false;
        while (true)
        {

            // Turno
            auto &playerNow = turn ? player1 : player2;
            auto &playerPrev = (repeat ? turn : !turn) ? player1 : player2;

            // Limpiar la entrada
            Utility::moveTo(2, campo->getRows() + 3);
            Utility::printf(std::string(playerPrev.size() + 2 + select_player.size() + 1 + action.size() + choice.size() + 1 + distance.size() + 1 + team.size(), ' '));

            // Leer la entrada
            Utility::moveTo(2, campo->getRows() + 3);
            Utility::printf("{}:", Utility::ToUpper(playerNow));
            Utility::update();
            std::cin >> select_player >> action >> choice >> distance >> team;

            // Vaciar buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Manejo de entrada
            try
            {
                if (select_player == "exit")
                    break;
            }
            // Errores en la entrada
            catch (const std::exception &e)
            {
                Utility::moveTo(2, campo->getRows() + 6);
                Utility::printf("Operation Invalid");
                repeat = true;
                continue;
            }
            // Errores en la lógica del juego
            /*
            catch (const std::exception &e)
            {
                Utility::moveTo(2, campo->getRows() + 5);
                Utility::printf("Error: {}", e.what());
            }*/

            campo->draw();
            ball->draw();
            team1->draw();
            team2->draw();

            // Cambio de turno
            turn = !turn;
            repeat = false;

            Utility::update();
        }
    }

    Game::~Game()
    {
        Utility::moveTo(0, campo->getRows() + 5);
        Utility::printf("Liberando recursos...");
        Utility::printf("\n");
        delete campo;
        delete team1;
        delete team2;
        delete ball;
        campo = nullptr;
        team1 = nullptr;
        team2 = nullptr;
        ball = nullptr;
    }
};