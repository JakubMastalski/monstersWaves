#include "RandomGenerator.hpp"

RandomNumber::RandomNumber(unsigned int minNumber, unsigned int maxNumber):dist(minNumber,maxNumber)
{
    std::random_device rd;
    mt.seed(rd());
}

int RandomNumber::getNumber()
{
    return dist(mt);
}
