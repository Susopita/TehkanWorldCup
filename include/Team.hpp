#pragma once

#include "Player.hpp"
#include "Coach.hpp"
#include "Ball.hpp"
#include "interfaces/Presenter.hpp"
#include "Formation.hpp"
#include <vector>
#include <string>

namespace TWC
{

    class Team : public Graphics::Presenter
    {
        Player *teammates;
        Player *select;
        int teamSize;
        Formation *formation;
        Coach coach;
        std::string color;

        void createTeam();

    public:
        Team() = default;
        Team(Formation *formation);
        Team(int teamSize, Formation *formation);

        ~Team();

        Team &setCoach(const Coach &coach);
        Team &setFormation(Formation *formation);
        Team &setTeamSize(int teamSize);
        Team &setFocus(Ball *ball);
        Team &setColor(const std::string &color);
        Team &setRepresentations(const std::vector<std::string> &representations);

        Coach getCoach() const;
        Formation *getFormation();
        int getTeamSize() const;
        Player *getTeammate(int);
        std::string getColor() const;

        // Implementación de la interfaz
        void draw() override;

        // Para decidir el movimiento general del equipo en cada turno
        void operator++(int); // Right
        void operator++();    // Left
    };
};