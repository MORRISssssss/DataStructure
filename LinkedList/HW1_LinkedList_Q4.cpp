#include "MatrixList.h"
#include "MatrixList.cpp"
#include "time.h"

int main()
{
    Matrix m1;
    cout << "Input m1: " << endl;
    cin >> m1;
    cout << "m1(in matrix): " << endl;
    m1.PrintMatrix();
    // (c)
    cout << "m1(in tuples): " << endl;
    cout << m1 << endl;

    Matrix m2;
    cout << "Input m2: " << endl;
    cin >> m2;
    cout << "m2(in matrix): " << endl;
    m2.PrintMatrix();
    cout << "m2(in tuples): " << endl;
    cout << m2 << endl;

    // (a), (e)
    Matrix m3(m1 + m2);
    /* The computing time of the copy constructor depends on 
    the number of non-zero elements in the original sparse 
    matrix. It iterates through all the non-zero elements and 
    inserts them into the new sparse matrix. The time 
    complexity is O(n), where n is the number of non-zero 
    elements in the original matrix. */
    cout << "m3(in matrix): " << endl;
    m3.PrintMatrix();
    cout << "m3(in tuples): " << endl;
    cout << m3 << endl;

    // (b)
    Matrix m4(m1 * m2);
    cout << "m4(in matrix): " << endl;
    m4.PrintMatrix();
    cout << "m4(in tuples): " << endl;
    cout << m4 << endl;

    // (d)
    m1.Transpose();
    cout << "m1(in matrix): " << endl;
    m1.PrintMatrix();
    cout << "m1(in tuples): " << endl;
    cout << m1 << endl;

    return 0;
}