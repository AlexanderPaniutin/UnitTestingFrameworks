#include <cppunit/extensions/HelperMacros.h>

#include "Complex.h"
#include <iostream>

class ComplexTest : public CppUnit::TestFixture
{

  // this marco needs to be in cpp file. not sure why (:
  // for now I added that to main.cpp
  // CPPUNIT_TEST_SUITE_REGISTRATION( ComplexTest );

  CPPUNIT_TEST_SUITE( ComplexTest );
  CPPUNIT_TEST( testEquality );
  CPPUNIT_TEST( testAddition );
  CPPUNIT_TEST_SUITE_END();

private:
  Complex *m_10_1, *m_1_1, *m_11_2;
public:
  void setUp()
  {
    m_10_1 = new Complex( 10, 1 );
    m_1_1 = new Complex( 1, 1 );
    m_11_2 = new Complex( 11, 2 );  
  }

  void tearDown() 
  {
    delete m_10_1;
    delete m_1_1;
    delete m_11_2;
  }

  void testEquality()
  {
    CPPUNIT_ASSERT( *m_10_1 == *m_10_1 );
    CPPUNIT_ASSERT( !(*m_10_1 == *m_11_2) );
  }

  void testAddition()
  {
    CPPUNIT_ASSERT( *m_10_1 + *m_1_1 == *m_11_2 );
  }

  void testDivideByZeroThrows()
  {
    *m_10_1 / Complex(0);
  }

};
