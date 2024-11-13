#include "RandomGenerator.hpp"
#include <gtest/gtest.h>


class RandomNumberTest : public ::testing::Test
{
protected:
    RandomNumber randGen;
};

TEST_F(RandomNumberTest, TestInRangeINT)
{
    int number = randGen.getNumber<int>(1,10);

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}


