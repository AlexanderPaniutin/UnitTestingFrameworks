#include <iostream>

#ifdef CUTEST
    #include <cppunit/extensions/TestFactoryRegistry.h>
    #include <cppunit/ui/text/TestRunner.h>
    #include "Complex_cutest.h"
#endif

#ifdef GTEST
    #include <gtest/gtest.h>
#endif


int main(int argc, char** argv)
{
#ifdef GTEST
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif

#ifdef CUTEST
    CPPUNIT_TEST_SUITE_REGISTRATION( ComplexTest );

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );

    runner.run();
    //bool wasSuccessful = runner.run( "", false );
#endif

    std::cout << "regural app is runing..." << std::endl;
}

