#include <iostream>
#include <unordered_set>
#include "include/Game.hpp"

using namespace std;

const unordered_set<string> colors = {
    "BLACK",
    "RED",
    "GREEN",
    "YELLOW",
    "BLUE",
    "MAGENTA",
    "CYAN",
    "WHITE",
    "LIGHT_GRAY",
    "LIGHT_RED",
    "LIGHT_GREEN",
    "LIGHT_YELLOW",
    "LIGHT_BLUE",
    "LIGHT_MAGENTA",
    "LIGHT_CYAN",
    "BRIGHT_WHITE"};

// Compilacion:
// g++ -std=c++20 -I./include ./src/*.cpp ./src/utility/*.cpp ./src/themes/*.cpp main.cpp -o INIT
// g++ -std=c++20 ./src/**.cpp ./src/utility/*.cpp ./src/themes/*.cpp main.cpp -o INIT && ./INIT RED BLUE

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cout << "Uso: " << argv[0] << " <Color Team 1>  <Color Team 2>" << endl;
        cout << endl;
        cout << "Colores soportados:" << endl;
        for (const string &color : colors)
        {
            cout << "  - " << color << endl;
        }
        return 1;
    }

    if (argv[1] == argv[2])
    {
        cout << "Colores deben ser diferentes" << endl;
        return 1;
    }

    if (colors.find(argv[1]) == colors.end() || colors.find(argv[2]) == colors.end())
    {
        cout << "Color no soportado" << endl;
        return 1;
    }

    TWC::Game init({argv[1], argv[2]});
    init.play();

    return 0;
}
