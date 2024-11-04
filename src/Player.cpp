#include "../include/Player.hpp"

#include "../include/utility/iomap.hpp"

namespace TWC
{
    Player &Player::setRole(PlayerRole role)
    {
        this->role = role;
        return *this;
    }
    Player &Player::setPosition(Position position)
    {
        this->position = position;
        return *this;
    }
    Player &Player::setFocus(Ball *ball)
    {
        this->focus = ball;
        return *this;
    }

    PlayerRole Player::getRole() const { return role; }
    Position Player::getPosition() const { return position; }
    Ball *Player::getFocus() const { return focus; }

    void Player::print(std::ostream &os) const
    {
        Utility::moveTo(position.x, position.y);
        os << representation;
    }

    void Player::move(Action action, Choice choice, int distance)
    {
        switch (choice)
        {
        case Choice::BALL:
            if (distance < 1 || distance > 40)
                throw new std::invalid_argument("Distance must be between 1 and 40");
            if (focus == nullptr)
                throw new std::exception();
            else
            {
                if (position.distance(focus->position) > 2)
                    throw new std::invalid_argument("Distance must be less than 2");
            }
            break;
        case Choice::PLAYER:
            if (distance < 1 || distance > 10)
                throw new std::invalid_argument("Distance must be between 1 and 10");
            break;
        }
        switch (action)
        {
        case Action::DOWN:
            position.x -= distance;
            break;

        case Action::DOWNLEFT:
            break;

        case Action::DOWNRIGHT:
            break;

        case Action::LEFT:
            break;

        case Action::RIGHT:
            break;

        case Action::UP:
            break;

        case Action::UPLEFT:
            break;

        case Action::UPRIGHT:
            break;
        }
    }
};