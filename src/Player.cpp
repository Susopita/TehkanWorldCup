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
        os << style.applyStyle(representation);
    }

    void Player::move(Actions::Action action, Actions::Choice choice, int distance)
    {
        bool withBall = false;
        switch (choice)
        {
        case Actions::Choice::BALL:
            if (distance < 1 || distance > 40)
                throw std::invalid_argument("Distance must be between 1 and 40");
            if (focus == nullptr)
                throw std::invalid_argument("Focus is null");
            if (position.distance(focus->position) > 2)
                throw std::invalid_argument("Distance must be less than 2: " + std::to_string(position.distance(focus->position)));
            break;
        case Actions::Choice::PLAYER:
            if (distance < 1 || distance > 10)
                throw std::invalid_argument("Distance must be between 1 and 10");
            if (position.distance(focus->position) <= 2)
                withBall = true;
            break;
        }

        Utility::moveTo(position.x, position.y);
        Utility::printf(" ");
        Utility::moveTo(focus->position.x, focus->position.y);
        Utility::printf(" ");

        switch (action)
        {
        case Actions::Action::DOWN:
            if (choice == Actions::Choice::BALL)
            {
                focus->position.y = position.y + distance;
                focus->position.x = position.x;
            }
            else
            {
                position.y += distance;
                if (withBall)
                    focus->position.y = position.y + 1;
            }
            break;

        case Actions::Action::DOWNLEFT:
            if (choice == Actions::Choice::BALL)
            {
                focus->position.y = position.y + distance;
                focus->position.x = position.x - distance;
            }
            else {
                position.y += distance;
                position.x -= distance;
                if (withBall) {
                    focus->position.y = position.y + 1;
                    focus->position.x = position.x - 1;
                }
            }
            break;

        case Actions::Action::DOWNRIGHT:
            if (choice == Actions::Choice::BALL)
            {
                focus->position.y = position.y + distance;
                focus->position.x = position.x + distance;
            }
            else
            {
                position.y += distance;
                position.x += distance;
                if (withBall) {
                    focus->position.y = position.y + 1;
                    focus->position.x = position.x + 1;
                }
            }
            break;

        case Actions::Action::LEFT:
            if (choice == Actions::Choice::BALL)
            {
                focus->position.x = position.x - distance;
                focus->position.y = position.y;
            }
            else
            {
                position.x -= distance;
                if (withBall) {
                    focus->position.x = position.x - 1;
                }
            }
            break;

        case Actions::Action::RIGHT:
            if (choice == Actions::Choice::BALL)
            {
                focus->position.x = position.x + distance;
                focus->position.y = position.y;
            }
            else
            {
                position.x += distance;
                if (withBall) {
                    focus->position.x = position.x + 1;
                }
            }
            break;

        case Actions::Action::UP:
            if (choice == Actions::Choice::BALL)
            {
                focus->position.y = position.y - distance;
                focus->position.x = position.x;
            }
            else
            {
                position.y -= distance;
                if (withBall) {
                    focus->position.y = position.y - 1;
                }
            }
            break;

        case Actions::Action::UPLEFT:
            if (choice == Actions::Choice::BALL)
            {
                focus->position.y = position.y - distance;
                focus->position.x = position.x - distance;
            }
            else
            {
                position.y -= distance;
                position.x -= distance;
                if (withBall) {
                    focus->position.y = position.y - 1;
                    focus->position.x = position.x - 1;
                }
            }
            break;

        case Actions::Action::UPRIGHT:
            if (choice == Actions::Choice::BALL)
            {
                focus->position.y = position.y - distance;
                focus->position.x = position.x + distance;
            }
            else
            {
                position.y -= distance;
                position.x += distance;
                if (withBall) {
                    focus->position.y = position.y - 1;
                    focus->position.x = position.x + 1;
                }
            }
            break;
        }
    }
};