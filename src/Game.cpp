#include "../include/Game.hpp"

#include <iostream>
#include <limits>
#include "../include/utility/iomap.hpp"
#include "../include/themes/Defaults.hpp"
#include "../include/utility/Actions.hpp"
#include <vector>

namespace TWC
{
    void Game::setup()
    {
        campo = new Defaults::FieldGame();
        ball = new Ball();
        team1 = new Team();
        team2 = new Team();

        std::vector<std::string> players1 = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
        std::vector<std::string> players2 = {"L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V"};

        int rows = 51;
        int columns = 121; // -2=2 -> -1=1

        ball->setRepresentation("X")
            .setStyle({Style::ColorText::BLACK,
                       Style::ColorBackground::DEFAULT})
            .position = Position(columns / 2 - 6, rows / 2 - 1);

        team1->setCoach(Coach("Suso"))
            .setFormation(new Defaults::Formation1433(rows, columns))
            .setTeamSize(11)
            .setFocus(ball)
            .setColor(Utility::mapColor(player1))
            .setRepresentations(players1);

        team2->setCoach(Coach("Pita"))
            .setFormation(new Defaults::Formation1433(rows, columns, false))
            .setTeamSize(11)
            .setFocus(ball)
            .setColor(Utility::mapColor(player2))
            .setRepresentations(players2);

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

            // Limpiear error
            Utility::moveTo(2, campo->getRows() + 6);
            Utility::printf("                 ");

            // Vaciar buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Manejo de entrada
            try
            {
                // Salir del juego
                if (select_player == "exit")
                    break;

                // Validar el jugador seleccionado
                if (select_player.size() > 1)
                    throw std::invalid_argument("Player not found");
                else if (turn ? 'A' > select_player[0] or select_player[0] > 'K' : 'L' > select_player[0] or select_player[0] > 'V')
                    throw std::invalid_argument("Player not found");

                auto playerFilter = select_player[0];

                // Validar la acción
                auto actionFilter = Actions::mapAction(action);

                // Validar la elección
                auto choiceFilter = Actions::mapChoice(choice);

                // Validar formato de la distancia
                int distanceFilter = std::stoi(distance);

                // Validar accion de equipo
                auto teamFilter = Actions::mapTeamAction(team);

                // Realizar la acción
                auto teammate = (turn ? team1 : team2)->getTeammate(playerFilter - (turn ? 'A' : 'L'));

                // Colisiones
                switch (choiceFilter)
                {
                case Actions::Choice::BALL:
                    if (campo->ballIsOut(actionFilter, distanceFilter))
                        throw std::invalid_argument("Ball out of bounds");
                    break;
                case Actions::Choice::PLAYER:
                    if (campo->playerIsOut(teammate, actionFilter, distanceFilter))
                        throw std::invalid_argument("Player out of bounds");
                    break;
                }

                // Realizar la acción
                teammate->move(actionFilter, choiceFilter, distanceFilter);

                // Acciones de equipo
                switch (teamFilter)
                {
                case Actions::TeamAction::RIGHT:
                    (*(turn ? team1 : team2))++;
                    break;
                case Actions::TeamAction::LEFT:
                    ++(*(turn ? team1 : team2));
                    break;
                }
            }
            // Errores en la entrada o en la accion
            catch (const std::exception &e)
            {
                Utility::moveTo(2, campo->getRows() + 6);
                Utility::printf("Operation Invalid -> {}", e.what());
                repeat = true;
                continue;
            }

            campo->draw();
            ball->draw();
            team1->draw();
            team2->draw();

            // Cambio de turno
            turn = !turn;
            repeat = false;

            // Actualizar la pantalla
            Utility::update();

            // Verificar si hay un gol
            if (campo->isGoal())
            {
                Utility::moveTo(2, campo->getRows() + 6);
                Utility::printf("Goal!");
                break;
            }
        }
    }

    Game::~Game()
    {
        Utility::moveTo(0, campo->getRows() + 7);
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