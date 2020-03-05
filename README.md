
requirement: running in ubuntu 18.04

Running steps:

mkdir build
cd build
cmake ..
make
./runTests


Limitation of this code:
Still need to implements follow part
1. 
	Matrix<int> m(1,3);
	m*5.0;
the above code will fail, since the int*double
2. 
	Matrix<int> m(1,2);
	m ={ {1,2},{2,3}}
	m = m*5;
the above code will fail, since now m's content will be changed to a new one.
this library doesn't take care of that part.
