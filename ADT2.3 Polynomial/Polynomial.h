#include <iostream>
using namespace std;
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial;
class Term {
    friend Polynomial;
    private:
        float coef;
        int exp;
};

// p(x) = a0 x^e0 + … + an x^en 
// where ai is nonzero float and ei is non-negative int
class Polynomial {
    public:
        //construct the polynomial p(x) = 0
        Polynomial();
        //return the sum of *this and poly
        Polynomial Add(const Polynomial);
        //return the product of *this and poly
        Polynomial Mult(const Polynomial);
        //Evaluate the polynomial *this at f and return the results
        float Eval(const float);
        // if *this is the zero polynomial, return 1; else return 0;
        int operator!();
        // return the coefficient of e in *this
        float Coef(const int);
        // return the largest exponent in *this
        int LeadExp();
        // Add a new term to the end of termArray
        void NewTerm(const float, const int);
        friend ostream& operator<<(ostream&, const Polynomial&);
        friend istream& operator>>(istream&, Polynomial&);
    private:
        Term *termArray;
        int capacity;
        int terms;
};
#endif