#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <iostream>
#include "RandomGenerator.hpp"


int main()
{
    Game game;
    game.run();

    RandomNumber random;

    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;

    return 0;
}