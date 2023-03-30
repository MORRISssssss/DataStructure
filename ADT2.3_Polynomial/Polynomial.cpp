#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

#define INIT_CAPACITY 5

Polynomial::Polynomial()
{
    capacity = INIT_CAPACITY;
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
            if (t) 
                c.NewTerm(t, termArray[aPos].exp);
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

Polynomial Polynomial::Mult(const Polynomial b)
{
    Polynomial c, tempPoly;
    int aPos, bPos;
    for (aPos = 0; aPos < terms; aPos++){
        for (bPos = 0; bPos < b.terms; bPos++){
            float tempCoef = termArray[aPos].coef * b.termArray[bPos].coef;
            int tempExp = termArray[aPos].exp + b.termArray[bPos].exp;
            if (tempCoef) 
                tempPoly.NewTerm(tempCoef, tempExp);
        }
        c = c.Add(tempPoly);
        tempPoly.ClearTerms();
    }
    return c;

}

float Polynomial::Eval(const float f)
{
    float sum = 0;
    for (int Pos = 0; Pos < terms; Pos++){
        sum += pow(f, termArray[Pos].exp) * termArray[Pos].coef; 
    }
    return sum;
}

int Polynomial::operator!()
{
    if (termArray[0].coef == 0 && termArray[0].exp == 0 && terms <= 1)
        return 1;
    else
        return 0;
}

inline float Polynomial::Coef(const int e)
{
    return termArray[e].coef;
}

inline int Polynomial::LeadExp()
{
    return termArray[terms - 1].exp;
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

void Polynomial::ClearTerms()
{
    capacity = INIT_CAPACITY;
    terms = 0;
    delete [] termArray;
    termArray = new Term[capacity];
}

Polynomial &Polynomial::operator=(Polynomial poly)
{
    capacity = poly.capacity;
    terms = poly.terms;
    Term *temp = new Term[capacity]; 
    copy(poly.termArray, poly.termArray + poly.terms, temp);
    delete [] termArray ;
    termArray = temp;
    return *this;
}

ostream& operator <<(ostream& os, const Polynomial& poly)
{
    os << poly.termArray[0].coef;
    if (poly.termArray[0].exp != 0)
        os << "x^" << poly.termArray[0].exp;
    for (int Pos = 1; Pos < poly.terms; Pos++){
        if (poly.termArray[Pos].coef >= 0)
            os << " + " << poly.termArray[Pos].coef;
        else
            os << " - " << abs(poly.termArray[Pos].coef);
        if (poly.termArray[Pos].exp != 0){
            os << "x^" << poly.termArray[Pos].exp;
        }
    }
    return os;
}

istream& operator >>(istream& is, Polynomial& poly){
    float COEF;
    int EXP;
    poly.ClearTerms();
    while (is >> COEF >> EXP){
        poly.NewTerm(COEF, EXP);
        if (is.get() == '\n')
            break;
    }
    return is;
}