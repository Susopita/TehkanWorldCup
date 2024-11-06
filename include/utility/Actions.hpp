#pragma once

#include <unordered_map>
#include <string>

namespace TWC::Actions
{
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

    enum class TeamAction
    {
        RIGHT,
        LEFT
    };

    static const std::unordered_map<std::string, Action> stringToAction = {
        {"UP", Action::UP},
        {"UPRIGHT", Action::UPRIGHT},
        {"RIGHT", Action::RIGHT},
        {"DOWNRIGHT", Action::DOWNRIGHT},
        {"DOWN", Action::DOWN},
        {"DOWNLEFT", Action::DOWNLEFT},
        {"LEFT", Action::LEFT},
        {"UPLEFT", Action::UPLEFT}};

    static const std::unordered_map<std::string, Choice> stringToChoice = {
        {"PLAYER", Choice::PLAYER},
        {"BALL", Choice::BALL}};

    static const std::unordered_map<std::string, TeamAction> stringToTeamAction = {
        {"RIGHT", TeamAction::RIGHT},
        {"LEFT", TeamAction::LEFT}};

    Action mapAction(const std::string &action);
    Choice mapChoice(const std::string &choice);
    TeamAction mapTeamAction(const std::string &action);
};