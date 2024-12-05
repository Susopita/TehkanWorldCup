#include "../include/Team.hpp"

#include "../include/utility/iomap.hpp"
namespace TWC
{
    void Team::createTeam()
    {
        teammates = new Player[teamSize];
        for (int i = 0; i < teamSize; i++)
        {
            teammates[i] = Player();
        }

        teammates[0].setPosition(formation->getGoalkeeper());
        auto defenders = formation->getDefenders();
        auto midfielders = formation->getMidfielders();
        auto strikers = formation->getStrikers();

        for (size_t i = 1, j = 0; j < defenders.size(); i++, j++)
        {
            teammates[i].setPosition(defenders[j]);
        }

        for (size_t i = 1 + defenders.size(), j = 0; j < midfielders.size(); i++, j++)
        {
            teammates[i].setPosition(midfielders[j]);
        }

        for (size_t i = 1 + defenders.size() + midfielders.size(), j = 0; j < strikers.size(); i++, j++)
        {
            teammates[i].setPosition(strikers[j]);
        }
    }

    Team::Team(Formation *formation) : teamSize(11), formation(formation), coach(Coach())
    {
        createTeam();
    }

    Team::Team(int teamSize, Formation *formation) : teamSize(teamSize), formation(formation), coach(Coach())
    {
        createTeam();
    }

    Team::~Team()
    {
        delete[] teammates;
        teammates = nullptr;
        delete formation;
        formation = nullptr;
        select = nullptr;
    }

    Team &Team::setCoach(const Coach &coach)
    {
        this->coach = coach;
        return *this;
    }
    Team &Team::setFormation(Formation *formation)
    {
        this->formation = formation;
        createTeam();
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
        this->color = color;
        for (int i = 0; i < teamSize; i++)
        {
            teammates[i].setStyle({color, Style::ColorBackground::DEFAULT});
        }
        return *this;
    }

    Team &Team::setRepresentations(const std::vector<std::string> &representations)
    {
        if (representations.size() != (size_t)teamSize)
        {
            throw std::invalid_argument("Representations must be the same size as the team");
        }
        for (int i = 0; i < teamSize; i++)
        {
            teammates[i].setRepresentation(representations[i]);
        }
        return *this;
    }

    void Team::draw()
    {
        for (int i = 0; i < teamSize; i++)
        {
            Utility::moveTo(teammates[i].getPosition().x, teammates[i].getPosition().y);
            teammates[i].draw();
        }
    }

    Coach Team::getCoach() const { return coach; }
    Formation *Team::getFormation() { return formation; }
    int Team::getTeamSize() const { return teamSize; }
    std::string Team::getColor() const { return color; }
    Player *Team::getTeammate(int number)
    {
        this->select = teammates + number;
        return select;
    }

    // Para decidir el movimiento general del equipo en cada turno
    void Team::operator++(int)
    {
        for (int i = 0; i < teamSize; i++)
        {
            if (teammates + i != select and i)
                teammates[i].move(Actions::Action::RIGHT, Actions::Choice::PLAYER, 4);
        }
    } // Right
    void Team::operator++()
    {
        for (int i = 0; i < teamSize; i++)
        {
            if (teammates + i != select and i)
                teammates[i].move(Actions::Action::LEFT, Actions::Choice::PLAYER, 4);
        }
    } // Left
};