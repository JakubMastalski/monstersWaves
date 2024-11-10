#include <random>

class RandomNumber
{
public:
    RandomNumber();

    int getIntNumber(int minNumber, int maxNumber);
    unsigned int getUIntNumber(unsigned int minNumber, unsigned int maxNumber);
    float getFloatNumber(float minNumber, float maxNumber);
private:
    std::mt19937 mt;
};
