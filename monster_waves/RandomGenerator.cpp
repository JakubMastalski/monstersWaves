#include "RandomGenerator.hpp"

RandomNumber::RandomNumber()
{
    srand(static_cast<unsigned int>(time(nullptr)));
}

int RandomNumber::getNumber(int min, int max)
{
    if (min > max)
    {
        std::swap(min, max);
    }
    return min + (std::rand() % (max - min + 1));
}
