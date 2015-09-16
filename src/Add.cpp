#include <iostream>

#ifdef GTEST
    #include <gtest/gtest.h>
#endif

#include "Add.h"

int add(int a, int b)
{
    return a+b;
}

int main(int argc, char** argv)
{
#ifdef GTEST
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif

    std::cout << "regural app is runing..." << std::endl;
}

