#include "demo_gtest.h"
#include "gtest/gtest.h"

TEST(Add, AddZeros)
{
    EXPECT_EQ(0, add(0,0));
    EXPECT_EQ(0, add(-1, 1));
}
