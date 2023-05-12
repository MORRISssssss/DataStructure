#ifndef POLYNOMIALLIST_H
#define POLYNOMIALLIST_H

#include <iostream>
#include <math.h>
using namespace std;

class Polynomial;

class Node{
    public:
        friend class Polynomial;
        friend istream& operator>>(istream& is, Polynomial& x);
        friend ostream& operator<<(ostream& os, const Polynomial& x);
    private:
        double coef;
        int exp;
        Node* link;
};

class Polynomial {
    public:
        Polynomial();
        ~Polynomial();
        Polynomial(const Polynomial& a);
        const Polynomial& operator=(const Polynomial& a);
        friend istream& operator>>(istream& is, Polynomial& x);
        friend ostream& operator<<(ostream& os, const Polynomial& x);
        Polynomial operator+(const Polynomial& b) const;
        Polynomial operator-(const Polynomial& b) const;
        Polynomial operator*(const Polynomial& b) const;
        double Evaluate(double x) const;
        void AppendTerm(const double& coef, const int& exp);
    private:
        Node* header;
        static Node* available;
        Node* GetNode();
        void RetNode(Node* p);   
};

#endif