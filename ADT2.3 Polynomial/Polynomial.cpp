#include "Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial()
{
    capacity = 5;
    terms = 0;
    NewTerm(0, 0);
}

Polynomial Polynomial::Add(const Polynomial poly)
{
    return Polynomial();
}

Polynomial Polynomial::Mult(const Polynomial poly)
{
    return Polynomial();
}

int Polynomial::operator!()
{
    return 0;
}

float Polynomial::Coef(const int e)
{
    return 0.0f;
}

int Polynomial::LeadExp()
{
    return 0;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    if (terms == capacity){ // termArray (of c) is full
        capacity *= 2; // double the capacity of termArray
        Term *temp = new Term[capacity]; 
        copy(termArray, termArray + terms, temp);
        delete [] termArray ; // delete allocated old memory
        termArray = temp;
    }
    termArray [terms].coef = theCoeff;
    termArray [terms++].exp = theExp;
}
