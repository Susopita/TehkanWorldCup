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

    void Player::move(Actions::Action action, Actions::Choice choice, int distance)
    {
        switch (choice)
        {
        case Actions::Choice::BALL:
            if (distance < 1 || distance > 40)
                throw std::invalid_argument("Distance must be between 1 and 40");
            if (focus == nullptr)
                throw std::exception();
            else
            {
                if (position.distance(focus->position) > 2)
                    throw std::invalid_argument("Distance must be less than 2");
            }
            break;
        case Actions::Choice::PLAYER:
            if (distance < 1 || distance > 10)
                throw std::invalid_argument("Distance must be between 1 and 10");
            break;
        }
        Utility::moveTo(position.x, position.y);
        Utility::printf(" ");
        switch (action)
        {
        case Actions::Action::DOWN:
            position.y += distance;
            break;

        case Actions::Action::DOWNLEFT:
            position.y += distance;
            position.x -= distance;
            break;

        case Actions::Action::DOWNRIGHT:
            position.y += distance;
            position.x += distance;
            break;

        case Actions::Action::LEFT:
            position.x -= distance;
            break;

        case Actions::Action::RIGHT:
            position.x += distance;
            break;

        case Actions::Action::UP:
            position.y -= distance;
            break;

        case Actions::Action::UPLEFT:
            position.y -= distance;
            position.x -= distance;
            break;

        case Actions::Action::UPRIGHT:
            position.y -= distance;
            position.x += distance;
            break;
        }
    }
};