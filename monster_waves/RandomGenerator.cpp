#include "RandomGenerator.hpp"

RandomNumber::RandomNumber(unsigned int minNumber, unsigned int maxNumber):dist(minNumber,maxNumber)
{
    std::random_device rd;
    mt.seed(rd());
}

int RandomNumber::getIntNumber()
{
    return static_cast<int>(dist(mt));
}

unsigned int RandomNumber::getUIntNumber()
{
    return static_cast<int>(dist(mt));
}

float RandomNumber::getFloatNumber()
{
    return static_cast<float>(dist(mt));
}


