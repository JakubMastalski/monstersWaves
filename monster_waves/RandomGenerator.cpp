#include "RandomGenerator.hpp"

RandomNumber::RandomNumber(unsigned int minNumber, unsigned int maxNumber) : min(maxNumber),max(maxNumber),number(0)
{
   srand(static_cast<unsigned int>(time(nullptr)));
}

int RandomNumber::getNumber()
{
    if (min > max)
    {
        std::swap(min, max);
    }
    return min + (std::rand() % (max - min + 1));
}
