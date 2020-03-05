#include <iostream>
#include "Matrix.h"
#include <gtest/gtest.h>


TEST(Test1, equalRowCol)
{
    Matrix<int> m1(2,3);
    EXPECT_EQ(2, m1.get_r());
    EXPECT_EQ(3, m1.get_c());
}

TEST(Test2, equalContent1)
{
    Matrix<double> m2(2,2);
    m2={ {1.1,1.2},{1.3,1.4} };
    EXPECT_EQ(1.1, m2(0,0));
    EXPECT_EQ(1.2, m2(0,1));
    EXPECT_EQ(1.3, m2(1,0));
    EXPECT_EQ(1.4, m2(1,1));
}

TEST(Test3, TestTranspose)
{
    Matrix<double> m2(2,3);
    m2={ {1.1,1.2,1.3},{1.4,1.5,1.6} };
    m2.transpose();
    EXPECT_EQ(1.1, m2(0,0));
    EXPECT_EQ(1.4, m2(0,1));
    EXPECT_EQ(1.2, m2(1,0));
    EXPECT_EQ(1.5, m2(1,1));
    EXPECT_EQ(1.3, m2(2,0));
    EXPECT_EQ(1.6, m2(2,1));
}

TEST(Test4, TestMultiplication1)
{
    Matrix<int> m1(2,2);
    m1={ {1,2},{3,4} };
    Matrix<int> m2 = m1*5;

    EXPECT_EQ(5, m2(0,0));
    EXPECT_EQ(10, m2(0,1));
    EXPECT_EQ(15, m2(1,0));
    EXPECT_EQ(20, m2(1,1));
}

TEST(Test5, TestMultiplication2)
{
    Matrix<int> m1(1,2);
    m1={ {1,2} };
    Matrix<int> m2(2,3);
    m2={ {1,2,3},{4,5,6} };
    Matrix<int> m3=m1*m2;

    EXPECT_EQ(9, m3(0,0));
    EXPECT_EQ(12, m3(0,1));
    EXPECT_EQ(15, m3(0,2));
}

TEST(Test6, TestComplex)
{
    Matrix<int> m1(1,2);
    m1={ {1,1} };
    m1 *2;
    Matrix<int> m2(2,3);
    m2={ {1,2,3},{4,5,6} };
    m2.transpose();
    m2.transpose();
    Matrix<int> m3 = m1*m2;

    EXPECT_EQ(10, m3(0,0));
    EXPECT_EQ(14, m3(0,1));
    EXPECT_EQ(18, m3(0,2));
}

TEST(Test7, TestMultiplication1)
{
    Matrix<int> m2(2,2);
    m2={ {1,2},{3,4} };
    m2 = m2*5;

    EXPECT_EQ(5, m2(0,0));
    EXPECT_EQ(10, m2(0,1));
    EXPECT_EQ(15, m2(1,0));
    EXPECT_EQ(20, m2(1,1));
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}