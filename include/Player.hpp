#pragma once

#include <iostream>
#include "Position.hpp"
#include "Style.hpp"
#include "Ball.hpp"

namespace TWC
{
    enum class PlayerRole
    {
        GOALKEEPER,
        DEFENDER,
        MIDFIELDER,
        STRIKER
    };

    enum class Action
    {
        UP,
        UPRIGHT,
        RIGHT,
        DOWNRIGHT,
        DOWN,
        DOWNLEFT,
        LEFT,
        UPLEFT
    };

    enum class Choice
    {
        PLAYER,
        BALL
    };

    class Player : public Style::Representation<Player>
    {
        PlayerRole role;
        Position position;
        Ball *focus;

    public:
        Player() : role(PlayerRole::GOALKEEPER), position(Position(0, 0)), focus(nullptr) {}
        ~Player() = default;

        Player &setRole(PlayerRole role);
        Player &setPosition(Position position);
        Player &setFocus(Ball *ball);

        PlayerRole getRole() const;
        Position getPosition() const;
        Ball *getFocus() const;

        void print(std::ostream &os) const override;

        void move(Action action, Choice choice, int distance);
    };

};