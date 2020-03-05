#include "Matrix.h"
#include <iostream>
// This is for self-learning purpose, doesn't not include for the submission.
int main()
{
    Matrix<int> m1(2,2);
    m1(0,0)= 2;
    m1(0,1)= 4;
    m1.print_all();

    Matrix<int> m2(2,3);
    m2={ {1,2,1},{2,3,4} };
    m2.print_all();

    m2.transpose();
    m2.print_all();

    (m2.transpose()).print_all();

    auto multiplication2 = m1*2;
    multiplication2.print_all();
    return 0;
}
