#include <gtest/gtest.h>
#include "RandomGenerator.hpp"


class RandomNumberTest : public ::testing::Test
{
protected:
    RandomNumber randGen{ 1, 10 };
};

TEST_F(RandomNumberTest, TestInRange)
{
    int number = randGen.getIntNumber();

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}

TEST_F(RandomNumberTest, TestMinMaxOrder)
{
    float number = randGen.getFloatNumber();

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}

TEST_F(RandomNumberTest, ExpectExactResult)
{
    RandomNumber randomGenEE(5, 5);

    int number = randomGenEE.getIntNumber();

    EXPECT_EQ(number, 5);
}
