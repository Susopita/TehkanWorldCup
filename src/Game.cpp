#include "../include/Game.hpp"

#include <iostream>

namespace TWC
{
    Game::Game(std::initializer_list<const char *> path)
    {
        std::cout << "Game created" << std::endl;
        std::cout << *path.begin() << std::endl;
        std::cout << *(path.begin() + 1) << std::endl;
    }

    void Game::play() const
    {
        std::cout << "Playing..." << std::endl;
        Ball ball;
        ball.setStyle({TWC::Style::ColorText::BLACK, TWC::Style::ColorBackground::GREEN});
        std::cout << ball << std::endl;
    }
};