#include <iostream>
#include <vector>
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
            for(int i = 0; i<r; i++)
            {
                mat[i] = new T[c]();
            }
        }
        // destructor

        // copy constructor
        Matrix(const Matrix &other)
        {
            this->r = other.r;
            this->c = other.c;
            for(int i = 0; i<r; i++)
            {
                mat[i] = new T[c]();
            }

            // copy the content, need to simplify later
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++){
                    mat[i][j] = other.Mat[i][j];
                }
            }
        }

        ~Matrix(){};

        int& operator()(const int &x,const int &y)  {
            return mat[x][y];
        }

        Matrix<T>& operator=(const std::initializer_list<std::initializer_list<T>>& lst)  {
            auto it = lst.begin();
            for(int i = 0; i < lst.size(); i++, it++)
            {
                std::copy(it->begin(), it->end(), this->mat[i]);
            }
            return *this;
        }

        void operator=(const Matrix<T> &rhs)
        {
            Matrix tmp(rhs);
            rhs.swap(*this);
            return *this;
        }
        Matrix operator *(const Matrix<T> &rhs) const
        {
            if( c==rhs.r){
                Matrix<T> result(r,rhs.c);
                for(int i = 0; i < r; r++)
                {
                    for(int j = 0; j < rhs.c; c++)
                    {
                        for( int k = 0; k < rhs.r; k++ ){
                            result[i][j] += mat[i][k] * rhs.mat[k][j];
                        }
                    }
                }
                return result;
            }
        }

        Matrix<T> operator *(const int &mul) const
        {
            Matrix<T> result(r,c);
            for(int i = 0; r < r; r++)
            {
                for(int j = 0; c < c; c++)
                {
                    mat[i][j] = mul * mat[i][j];
                }
            }
            return result;
        }

        void printOut()
        {
            std::cout << "\nPrinting Matrix : \n";
            for(int i=0 ; i<=r-1 ; i++) {
                for(int j=0 ; j<=c-1 ; j++)
                    std::cout << mat[i][j] << " ";
                std::cout << std::endl;
            }
        }
};


int main()
{
    Matrix<int> m(2,2);
    // m[0,0] = 2;
    m(0,0)= 2;
    m(0,1)= 4;

    Matrix<int> m2(2,2);
    // m2 = m*m;
    m.printOut();
    // m2.printOut();
    return 0;
}
