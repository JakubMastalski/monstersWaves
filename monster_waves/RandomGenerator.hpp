#include <ctime>
#include <cstdlib>
#include <algorithm>

class RandomNumber
{
public:
    RandomNumber(unsigned int minNumber, unsigned int maxNumber);

    int getNumber();
private:
    unsigned int number;
    unsigned int min, max;
};
