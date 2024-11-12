#pragma once
#include <random>


class RandomNumber
{
public:
    RandomNumber();

    template<typename T>
    T getNumber(T minNumber, T maxNumber);
private:
    std::mt19937 mt;
};
