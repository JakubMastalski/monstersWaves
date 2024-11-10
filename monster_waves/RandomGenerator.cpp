#include "RandomGenerator.hpp"

RandomNumber::RandomNumber()
{
    std::random_device rd;
    mt.seed(rd());
}

int RandomNumber::getIntNumber(int minNumber,int maxNumber)
{
    std::uniform_int_distribution<int> dist(minNumber,maxNumber);
    return dist(mt);
}

unsigned int RandomNumber::getUIntNumber(unsigned int minNumber,unsigned int maxNumber)
{
    std::uniform_int_distribution<unsigned int> dist(minNumber,maxNumber);
    return dist(mt);
}

float RandomNumber::getFloatNumber(float minNumber,float maxNumber)
{
    std::uniform_real_distribution<float> dist(minNumber,maxNumber);
    return dist(mt);
}


