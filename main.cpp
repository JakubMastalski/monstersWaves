#include "Game.hpp"
#include "RandomGenerator.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    Game game;
    game.run();

    RandomNumber r1(1, 6);
    unsigned int number1 = r1.getNumber();
    std::cout << number1;
    RandomNumber r2(1, 6);
    unsigned int number2 = r2.getNumber();
    std::cout << number1;
    RandomNumber r3(1, 6);
    unsigned int number3 = r3.getNumber();
    std::cout << number3;
    RandomNumber r4(1, 6);
    unsigned int number4 = r4.getNumber();
    std::cout << number4;

    return 0;
}