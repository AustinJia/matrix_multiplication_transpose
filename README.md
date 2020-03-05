
detailed: https://github.com/AustinJia/matrix_multiplication_transpose
requirement: GTest
Tested in ubuntu 18.04

Running steps:
&nbsp;
```
mkdir build
cd build
cmake ..
make
./runTests
```


&nbsp;
Limitation of this code:

Still need to implements follow part

1. 
	Matrix<int> m(1,3);
	m*5.0;

the above code will fail, since the int*double

