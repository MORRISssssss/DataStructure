#include "String.h"
#include "String.cpp"
#include <iostream>
using namespace std;

int main()
{
    String A, B, C;
    cout << "Enter String A: ";
    cin >> A;
    cout << "String A: " << A << endl;
    cout << "Length of A: " << A.Length() << endl << endl;

    cout << "Enter String B: ";
    cin >> B;
    cout << "String B: " << B << endl;
    cout << "Length of B: " << B.Length() << endl << endl;

    C = A.Concat(B);
    cout << "Concatenate A with B: " << C << endl << endl;

    C = A.Substr(2, 5);
    cout << "Substring of A from 2 and with length 5: " << C << endl << endl;

    cout << "To find C in A, enter String C: ";
    cin >> C;
    cout << "String C: " << C << endl;
    cout << "String A: " << A << endl;
    cout << "The index of C in A is " << A.Find(C) << endl << endl;
    
    C = A.Delete(2, 5);
    cout << "String A: " << A << endl;
    cout << "Delete A from index 2 and with length 5: " << C << endl << endl;
    
    C = A.CharDelete('5');
    cout << "String A: " << A << endl;
    cout << "Delete '5' in A: " << C << endl << endl;

    cout << "String A: " << A << endl;
    cout << "String B: " << B << endl;
    cout << "Compare A and B: ";
    if (A.Compare(B) == -1)
        cout << "A < B" << endl;
    else if (A.Compare(B) == 1)
        cout << "A > B" << endl;
    else if (A.Compare(B) == 0)
        cout << "A == B" << endl;
    cout << endl;
    
    cout << "end" << endl;
    return 0;
}