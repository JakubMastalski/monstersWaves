#include "RandomGenerator.hpp"

RandomNumber::RandomNumber() : mt(std::random_device{}())
{
   //EMPTY BODY
}

template<typename T>

T RandomNumber::getNumber(T minNumber,T maxNumber)
{
    if constexpr (std::is_integral<T>::value)
    {
        std::uniform_int_distribution<T> dist(minNumber, maxNumber);
        return dist(mt);
    }
    else if constexpr(std::is_floating_point<T>::value)
    {
        std::uniform_real_distribution<T> dist(minNumber, maxNumber);
        return dist(mt)
    }
}



