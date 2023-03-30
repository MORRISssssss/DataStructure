#include "Polynomial.h"
#include <iostream>
using namespace std;

int main()
{
    Polynomial a;
    Polynomial b;
    Polynomial c;
    Polynomial d;
    float x;
    cout << "a: ";
    cin >> a;
    cout << "a(x) = " << a << endl;
    cout << "b: ";
    cin >> b;
    cout << "b(x) = " << b << endl;
    c = a.Add(b);
    cout << "a(x) + b(x) = " << c << endl;
    d = a.Mult(b);
    cout << "a(x) * b(x) = " << d << endl;
    cout << "x = ";
    cin >> x;
    cout << "a(" << x << ") = " << a.Eval(x) << endl;
    cout << "b(" << x << ") = " << b.Eval(x) << endl;
    cout << "a(" << x << ") + b(" << x << ") = " << c.Eval(x) << endl;
    cout << "a(" << x << ") * b(" << x << ") = " << d.Eval(x) << endl;

    return 0;
}