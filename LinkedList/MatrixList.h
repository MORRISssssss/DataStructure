#ifndef MATRIXLIST_H
#define MATRIXLIST_H

#include <iostream>
using namespace std;

struct Triple{
    int row, col, value;
};

class Matrix;
class MatrixNode{
    friend class Matrix;
    friend istream& operator>>(istream& is, Matrix& matrix);
    friend ostream& operator<<(ostream& os, Matrix& matrix);
    private:
        MatrixNode *down, *right;
        bool head;
        union{
            MatrixNode *next;
            Triple triple;
        };
        MatrixNode(bool b, Triple *t); 
};

class Matrix{
    friend istream& operator>>(istream& is, Matrix& matrix);
    friend ostream& operator<<(ostream& os, Matrix& matrix);
    public:
        Matrix();
        ~Matrix();
        Matrix operator+(const Matrix& b) const;
        Matrix operator*(const Matrix& b) const;
        void Transpose();
        Matrix(const Matrix& b);
        void PrintMatrix() const;
    private:
        MatrixNode *headnode;
};

#endif