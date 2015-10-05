#include "Complex.h"
#include "gtest/gtest.h"

class ComplexTest : public ::testing::Test
{
    protected:
        // the fixture will be created for each test run separately
        ComplexTest() { }
        virtual ~ComplexTest() { }

        // this function will be called after Creating current fixture and before calling a single test
        virtual void SetUp()
        { 
            m_10_1 = new Complex( 10, 1 );
            m_1_1 = new Complex( 1, 1 );
            m_11_2 = new Complex( 11, 2 );
        }

        // this function will be called after single test run before deleting current fixture object
        virtual void TearDown()
        {
            delete m_1_1;
            delete m_10_1;
            delete m_11_2;
        }

        Complex *m_1_1;
        Complex *m_10_1;
        Complex *m_11_2;
};

TEST_F(ComplexTest, TestEquality)
{
    EXPECT_TRUE( *m_10_1 == *m_10_1 );
    EXPECT_TRUE( !(*m_10_1 == *m_11_2) );
}

TEST_F(ComplexTest, TestAddition)
{
    EXPECT_TRUE( *m_10_1 + *m_1_1 == *m_11_2 );
}
