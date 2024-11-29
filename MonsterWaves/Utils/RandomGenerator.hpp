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

template<typename T>

T RandomNumber::getNumber(T minNumber, T maxNumber)
{
    if constexpr (std::is_integral<T>::value)
    {
        std::uniform_int_distribution<T> dist(minNumber, maxNumber);
        return dist(mt);
    }
    else if constexpr (std::is_floating_point<T>::value)
    {
        std::uniform_real_distribution<T> dist(minNumber, maxNumber);
        return dist(mt);
    }
}
