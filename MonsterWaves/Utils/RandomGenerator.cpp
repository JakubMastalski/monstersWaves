#include "Utils/RandomGenerator.hpp"

RandomNumber::RandomNumber() : mt(std::random_device{}())
{
   //EMPTY BODY
}

