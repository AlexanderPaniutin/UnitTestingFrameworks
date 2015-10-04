#include "Add.h"
#include "gtest/gtest.h"

TEST(Add, AddZero)
{
    EXPECT_EQ(0, Add::add(0,0));
}

TEST(Add, AddNegative)
{
    EXPECT_EQ(-5, Add::add(5, -10));
    EXPECT_EQ(-5, Add::add(-10, 5));
}

TEST(Add, AddPositive)
{
    EXPECT_EQ(15, Add::add(5, 10));
    EXPECT_EQ(15, Add::add(10, 5));
}

TEST(Add, AddUptoMax)
{
    EXPECT_EQ(2147483647, Add::add(2147483640, 7));
    EXPECT_EQ(2147483647, Add::add(7, 2147483640));
}

TEST(Add, AddDowntoMin)
{
    EXPECT_EQ(-2147483648, Add::add(-2147483640, -8));
    EXPECT_EQ(-2147483648, Add::add(-8, -2147483640));
}

/*
TEST(Add, ExpectToFail)
{
    EXPECT_EQ(0, Add::add(1, 0));
    EXPECT_EQ(5, Add::add(10, 15));
}
*/
