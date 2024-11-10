#include "RandomGenerator.hpp"
#include <gtest/gtest.h>


class RandomNumberTest : public ::testing::Test
{
protected:
    RandomNumber randGen;
};

TEST_F(RandomNumberTest, TestInRangeINT)
{
    int number = randGen.getIntNumber(1,10);

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}

TEST_F(RandomNumberTest, TestMinMaxOrderFloat)
{
    float number = randGen.getFloatNumber(1.0f,10.0f);

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}

TEST_F(RandomNumberTest, ExpectExactResult)
{
    RandomNumber randomGenEE;

    unsigned int number = randomGenEE.getUIntNumber(5, 5);

    EXPECT_EQ(number, 5);
}
