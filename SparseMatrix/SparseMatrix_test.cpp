#include "SparseMatrix.h"
#include "SparseMatrix.cpp"
#include <iostream>
using namespace std;

int main()
{
    SparseMatrix A, B;
    cout << "Enter sparse matrix in the following form: " << endl;
    cout << "> rows cols terms" << endl;
    cout << "> row0 col0 value0" << endl;
    cout << "> row1 col1 value1" << endl;
    cout << "> ..." << endl;
    cout << "Enter sparse matrix A: " << endl;
    cin >> A;
    cout << "Matrix A: " << endl;
    cout << A << endl;
    cout << "Enter sparse matrix B: " << endl;
    cin >> B;
    cout << "Matrix B: " << endl;
    cout << B << endl;
    cout << "Matirx A + B: " << endl;
    cout << A.Add(B) << endl;
    cout << "Matrix A * B: " << endl;
    cout << A.Multiply(B) << endl;
    cout << "Transpose matrix of A: " << endl;
    cout << A.Transpose() << endl;
    cout << "Transpose matrix of B: " << endl;
    cout << B.Transpose() << endl;

    return 0;
}