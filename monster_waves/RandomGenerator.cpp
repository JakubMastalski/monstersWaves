#include "RandomGenerator.hpp"

RandomNumber::RandomNumber()
{
   srand(time(NULL));
}

int RandomNumber::getNumber(const int min, const int max)
{
    return (std::rand() % max) + min;
}
