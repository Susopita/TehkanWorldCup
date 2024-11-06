#include "../../include/utility/Actions.hpp"

namespace TWC::Actions
{
    Action mapAction(const std::string &action)
    {
        auto it = stringToAction.find(action);
        if (it == stringToAction.end())
            throw std::invalid_argument("Action not found");
        return it->second;
    }
    Choice mapChoice(const std::string &choice)
    {
        auto it = stringToChoice.find(choice);
        if (it == stringToChoice.end())
            throw std::invalid_argument("Action not found");
        return it->second;
    }
    TeamAction mapTeamAction(const std::string &action)
    {
        auto it = stringToTeamAction.find(action);
        if (it == stringToTeamAction.end())
            throw std::invalid_argument("Action not found");
        return it->second;
    }
};