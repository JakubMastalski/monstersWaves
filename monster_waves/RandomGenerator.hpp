#include <random>

class RandomNumber
{
public:
    RandomNumber(unsigned int minNumber, unsigned int maxNumber);
    int getNumber();
private:
    std::mt19937 mt;
    std::uniform_int_distribution<unsigned int> dist;
};
