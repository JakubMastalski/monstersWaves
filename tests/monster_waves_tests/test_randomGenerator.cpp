#include <gtest/gtest.h>

#include "RandomGenerator.hpp"


class RandomNumberTest : public ::testing::Test
{
protected:
    RandomNumber randGen;
};

TEST_F(RandomNumberTest, TestInt)
{
    int number = randGen.getNumber(1,10);

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}

TEST_F(RandomNumberTest, TestFloat)
{
    float number = randGen.getNumber(1.0f, 10.0f);

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}

TEST_F(RandomNumberTest, TestDouble)
{
    double number = randGen.getNumber(1.0, 10.0);

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}


