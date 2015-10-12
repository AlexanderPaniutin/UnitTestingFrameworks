#include <iostream>

#ifdef CUTEST
    #include <cppunit/extensions/TestFactoryRegistry.h>
    #include <cppunit/ui/text/TestRunner.h>
    #include <cppunit/TestResult.h>
    #include <cppunit/TestResultCollector.h>
    #include <cppunit/BriefTestProgressListener.h>
    #include <cppunit/CompilerOutputter.h>
    #include <cppunit/XmlOutputter.h>
    #include "Complex_cutest.h"
#endif

#ifdef GTEST
    #include <gtest/gtest.h>
    #include "Complex_gtest.h"
#endif


int main(int argc, char** argv)
{
#ifdef GTEST
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif

#ifdef CUTEST
    CPPUNIT_TEST_SUITE_REGISTRATION( ComplexTest );

    // informs test-listener about testresults
    CppUnit::TestResult testresult;
 
    // register listener for collecting the test-results
    CppUnit::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);
 
    // register listener for per-test progress output
    CppUnit::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run(testresult);
 
    // output results in compiler-format
    CppUnit::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();
 
    // Output XML for Jenkins CPPunit plugin
    std::ofstream xmlFileOut("tests/main_cutest_results_unformatted.xml");
    CppUnit::XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();
 
    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;

#endif

    std::cout << "regural app is runing..." << std::endl;
}

