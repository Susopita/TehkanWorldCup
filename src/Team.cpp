#include "../include/Team.hpp"

namespace TWC
{
    void Team::createTeam()
    {
        teammates = new Player[teamSize];
        for (int i = 0; i < teamSize; i++)
        {
            teammates[i] = Player();
        }
    }

    Team::Team(Formation formation) : teamSize(11), formation(formation), coach(Coach())
    {
        createTeam();
    }

    Team::Team(int teamSize, Formation formation) : teamSize(teamSize), formation(formation), coach(Coach())
    {
        createTeam();
    }

    Team::~Team()
    {
        delete[] teammates;
        teammates = nullptr;
    }

    Team &Team::setCoach(const Coach &coach)
    {
        this->coach = coach;
        return *this;
    }
    Team &Team::setFormation(const Formation &formation)
    {
        this->formation = formation;

        return *this;
    }
    Team &Team::setTeamSize(int teamSize)
    {
        this->teamSize = teamSize;
        delete[] teammates;
        teammates = nullptr;
        createTeam();
        return *this;
    }
    Team &Team::setFocus(Ball *ball)
    {
        for (int i = 0; i < teamSize; i++)
        {
            teammates[i].setFocus(ball);
        }
        return *this;
    }
    Team &Team::setColor(const std::string &color)
    {
        for (int i = 0; i < teamSize; i++)
        {
            teammates[i].setStyle({color, Style::ColorBackground::DEFAULT});
        }
        return *this;
    }

    void Team::draw()
    {
        for (int i = 0; i < teamSize; i++)
        {
            teammates[i].draw();
        }
    }

    Coach Team::getCoach() const { return coach; }
    Formation Team::getFormation() const { return formation; }
    int Team::getTeamSize() const { return teamSize; }
    Player *Team::getTeammate() const { return teammates; }

    // Para decidir el movimiento general del equipo en cada turno
    void Team::operator++() {} // Right
    void Team::operator--() {} // Left
};