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

        // copy constructor
        Matrix(const Matrix &other)
        {
            this->r = other.r;
            this->c = other.c;
            mat = new T*[r];
            for(int i = 0; i<r; i++)
            {
                mat[i] = new T[c];
            }


            // copy the content, need to simplify later
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++){
                    mat[i][j] = other.mat[i][j];
                }
            }
        }

        // destructor
        ~Matrix()
        {
            for (int i = 0; i < r; i++)
            {
                delete[] mat[i]; // deletes an inner array
            }
            delete[] mat; //delete pointer holding array of pointers;
        }

        T get_r(){
            return this->r;
        }

        T get_c(){
            return this->c;
        }

        void resetMatrix(const int &rr, const int &cc)
        {
            std::swap(this->r,this->c);
            mat = new T*[this->r];
            for(int i = 0; i< this->r; ++i)
            {
                mat[i] = new T[c]{0};
            }
        }

        T& operator()(const int &x,const int &y)  {
            return mat[x][y];
        }

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


        Matrix<T> operator*(const Matrix<T> &rhs) const
        {
            // std::cout <<  "r=" << this->r << ", c=" << this->c << std::endl;
            // std::cout << "rhs.r =" << rhs.r << ", rhs.c=" << rhs.c << std::endl;
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

        Matrix<T> transpose()
        {
            Matrix<T> temp(*this);
            std::cout << std::endl;
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