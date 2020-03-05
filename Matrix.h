/*
 * Developed for the matrix multipilication and tranpose.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef Mat_h
#define Mat_h
#include <iostream>
#include <assert.h>
#include "gtest/gtest.h"

template <typename T>
class Matrix{
    private:
        int r;
        int c;
        T **mat;
    public:
        Matrix(const int &r, const int &c)
        {
            this->r = r;
            this->c = c;
            mat = new T*[r]; // dynamic array (size r) of pointers to T
            for(int i = 0; i< r; ++i)
            {
                mat[i] = new T[c]{0};
            }
        }

        /**
         * copy constructor
        */
        Matrix(const Matrix &other)
        {
            this->r = other.r;
            this->c = other.c;
            mat = new T*[r];
            for(int i = 0; i<r; i++)
            {
                mat[i] = new T[c];
            }


            // copy the content of other matrix to current matrix
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++){
                    mat[i][j] = other.mat[i][j];
                }
            }
        }

        /**
         * destructor
        */
        ~Matrix()
        {
            for (int i = 0; i < r; i++)
            {
                delete[] mat[i]; // deletes an inner array
            }
            delete[] mat; //delete pointer holding array of pointers;
        }

        /**
         * get the row of matrix
        */
        T get_r(){
            return this->r;
        }

        /**
         * get the column of matrix
        */
        T get_c(){
            return this->c;
        }

        /**
         * allow allocate a new memory to matrix
         * 
         * @param rr, the row size of matrix
         * @param cc, index col size of matrix
        */
        void resetMatrix(const int &rr, const int &cc)
        {
            std::swap(this->r,this->c);
            mat = new T*[this->r];
            for(int i = 0; i< this->r; ++i)
            {
                mat[i] = new T[c]{0};
            }
        }

        /**
         * a new way to reset content in a matrix
         * ie: 
         *     Matrix<int> A(1,2); // A ={ {0,0}}
         *     A(0,0)= 1; // A ={ {1,0}}
         * 
         * @param x, index row
         * @param y, index col
         * @return the refereced value in that A(x,y)
        */
        T& operator()(const int &x,const int &y)  {
            return mat[x][y];
        }

        /**
         * initlize a matrix to a initializer_list
         * ie: 
         *     Matrix<int> A(1,3);
         *     A = { {1,2,3} };
         * 
         * @param lsh, initializer_list of initializer_list
         * @return the lsh matrix as current matrix.
        */
        Matrix<T>& operator=(const std::initializer_list<std::initializer_list<T>>& lst)  {
            [[maybe_unused]] bool check_r = this->r == lst.size();
            [[maybe_unused]] bool check_c = this->c == (*lst.begin()).size();;
            assert(check_r && "Wrong number of row");
            assert(check_c && "Wrong number of column");
            auto it = lst.begin();
            for(uint i = 0; i < lst.size(); i++, it++)
            {
                std::copy(it->begin(), it->end(), this->mat[i]);
            }
            return *this;
        }
        
        /**
         * assgin a matrix 
         * ie: Matrix A = Matrix A * 5
         * 
         * @param rhs, right hand matrix
         * @return the new matrix.
        */
        void operator=(Matrix<T> rhs)
        {
            std::swap(this->r,rhs.r);
            std::swap(this->c,rhs.c);
            std::swap(this->mat,rhs.mat);
        }

        // void operator=(const Matrix<T>& rhs)
        // {
        //     this->r = rhs.r;
        //     this->c = rhs.c;
        //     this->mat = rhs.mat;
        // }

        /**
         * multiplication of another matrix
         * 
         * @param rhs, right hand matrix
         * @return the result of two matrix multiplication.
        */
        Matrix<T> operator*(const Matrix<T> &rhs) const
        {
            assert(c == rhs.r);
            Matrix<T> ret(r,rhs.c);
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < rhs.c; j++)
                {
                    ret.mat[i][j] = 0;
                    for( int k = 0; k < rhs.r; k++ ){
                        ret.mat[i][j] += this->mat[i][k] * rhs.mat[k][j];
                    }
                }
            }
            return ret;
        }

        /**
         * multiplication of a single integral, late can change to more generatic(float, double)
         * 
         * @param mul The value that want to multiply.
         * @return the result of the multiplication.
        */
        Matrix<T> operator*(const int &mul) const
        {
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    this->mat[i][j] *= mul;
                }
            }
            return *this;
        }

        /**
         * Calculate the tranpose of the matrix.
         *
         * mathematicians have heard of.
         * @return the transpose of matrix
        */
        Matrix<T> transpose()
        {
            Matrix<T> temp(*this);
            resetMatrix(this->c, this->r);
            for(int i = 0; i < this->r; i++)
            {
                for(int j = 0; j < this->c; j++)
                {
                    this->mat[i][j] = temp.mat[j][i];
                }
            }
            return *this;
        }

        /**
         * a helper function to print out all the elements in the matrix.
         *
        */
        void print_all()
        {
            std::cout << "\nPrinting Matrix : \n";
            for(int i=0 ; i<=r-1 ; i++) {
                for(int j=0 ; j<=c-1 ; j++)
                    std::cout << mat[i][j] << " ";
                std::cout << std::endl;
            }
        }
};
#endif