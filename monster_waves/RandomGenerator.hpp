#include <ctime>
#include <cstdlib>
#include <algorithm>

class RandomNumber
{
public:
    RandomNumber();

    int getNumber(const int min, const int max);
private:
    unsigned int number;
};
