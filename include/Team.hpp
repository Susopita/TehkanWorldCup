#pragma once

#include "Player.hpp"
#include "Coach.hpp"

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

    class Team
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

        Coach getCoach() const;
        Formation getFormation() const;
        int getTeamSize() const;
        Player *getTeammate() const;

        // Para decidir el movimiento general del equipo en cada turno
        void operator++(); // Right
        void operator--(); // Left
    };
};