#pragma once

#include "Player.hpp"
#include "Coach.hpp"
#include "Ball.hpp"
#include "interfaces/Presenter.hpp"

namespace TWC
{
    enum class TeamAction
    {
        RIGHT,
        LEFT
    };

    struct Formation
    {
        int goalkeeper = 1;
        int defenders;
        int midfielders;
        int strikers;

        Formation() = default;
    };

    class Team : public Graphics::Presenter
    {
        Player *teammates;
        int teamSize;
        Formation formation;
        Coach coach;

        void createTeam();

    public:
        Team() = default;
        Team(Formation formation);
        Team(int teamSize, Formation formation);

        ~Team();

        Team &setCoach(const Coach &coach);
        Team &setFormation(const Formation &formation);
        Team &setTeamSize(int teamSize);
        Team &setFocus(Ball *ball);
        Team &setColor(const std::string &color);

        Coach getCoach() const;
        Formation getFormation() const;
        int getTeamSize() const;
        Player *getTeammate() const;

        // Implementación de la interfaz
        void draw() override;

        // Para decidir el movimiento general del equipo en cada turno
        void operator++(); // Right
        void operator--(); // Left
    };
};