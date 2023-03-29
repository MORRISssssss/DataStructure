#include "Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial()
{
    capacity = 5;
    terms = 0;
    termArray = new Term[capacity];
    termArray[0].coef = 0;
    termArray[0].exp = 0;
}

Polynomial Polynomial::Add(const Polynomial b)
{
    Polynomial c; //c.terms = 0
    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms)){
            if (termArray[aPos].exp == b.termArray[bPos].exp) {
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if (t) c.NewTerm(t, termArray[aPos].exp);
            aPos++; bPos++;
        }
        else if (termArray[aPos].exp < b.termArray[bPos].exp) {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    } 
    //add in remaining terms of *this
    for ( ; aPos < terms ; aPos++)//output the remaining terms
        c.NewTerm (termArray[aPos].coef, termArray[aPos].exp);
    //add in remaining terms of b
    for ( ; bPos < b.terms ; bPos++)//output remaining terms
        c.NewTerm (b.termArray[bPos].coef, b.termArray[bPos].exp);
    return c;
}

Polynomial Polynomial::Mult(const Polynomial poly)
{
    return Polynomial();
}

float Polynomial::Eval(const float f)
{
    return 0.0f;
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
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp;
}

ostream& operator<<(ostream& os, const Polynomial& poly)
{

}

istream& operator>>(istream& os, Polynomial& poly){

}