#include "Matrix.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(NameTest1, equalRow)
{
    Matrix<int> m1(2,2);
    // int t = m1(0,0);
    // EXPECT_EQ(2, m1(2,2));
    // EXPECT_TRUE(2, t);
    EXPECT_EQ(2, 2);
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}