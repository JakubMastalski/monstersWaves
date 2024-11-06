#include <gtest/gtest.h>
#include "RandomGenerator.hpp"
#include "Window.hpp"

class WindowTest : public ::testing::Test
{
protected:
    void createDefaultWindow()
    {
        m_window = std::make_unique< Window >();
    }

    std::unique_ptr< Window > m_window;
};

class RandomNumberTest : public ::testing::Test
{
protected:
    RandomNumber randGen{ 1, 10 };
};

TEST_F(RandomNumberTest, TestInRange)
{
    int number = randGen.getNumber();

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}

TEST_F(RandomNumberTest, TestMinMaxOrder)
{
    int number = randGen.getNumber();

    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
}

TEST_F(RandomNumberTest, ExpectExactResult)
{
    RandomNumber randomGenEE(5, 5);

    int number = randomGenEE.getNumber();

    EXPECT_EQ(number, 5);
}



