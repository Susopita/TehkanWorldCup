#pragma once

#include <string>

namespace TWC
{
    struct Coach
    {
        std::string name;
        Coach() = default;
        Coach(const std::string &name) : name(name) {}
    };
};