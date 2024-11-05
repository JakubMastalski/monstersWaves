#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

class randomNumber
{
public:
    randomNumber()
    {
        srand(time(NULL));
    }
    int getNumber(const int min, const int max)
    {
        return (std::rand() % max) + min;
    }

private:
    unsigned int number;
};


int main()
{
    Game game;
    game.run();

    randomNumber random;

    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;
    std::cout << random.getNumber(1, 99) << std::endl;

    return 0;
}