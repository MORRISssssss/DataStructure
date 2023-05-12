#include "PolynomialList.h"
#include "PolynomialList.cpp"

int main() 
{
    Polynomial p1, p2;
    
    cout << "Enter polynomial 1: ";
    // (a)
    cin >> p1;
    
    cout << "Enter polynomial 2: ";
    cin >> p2;
    
    // (b)
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    
    // (c), (f)
    Polynomial p3(p1 + p2);
    cout << "Sum: " << p3 << endl;

    // (d), (g)
    Polynomial p4 = p1 - p2;
    cout << "Difference: " << p4 << endl;
    
    // (h)
    Polynomial p5 = p1 * p2;
    cout << "Product: " << p5 << endl;
    
    // (i)
    double x;
    cout << "Enter a value for x: ";
    cin >> x;
    double result = p1.Evaluate(x);
    cout << "Evaluation of polynomial 1 at x = " << x << ": " << result << endl;
    
    return 0;
}