#include "PolynomialList.h"

Node* Polynomial::available = nullptr;

Node* Polynomial::GetNode() {
    if (available == nullptr) {
        return new Node();
    }
    Node* temp = available;
    available = available->link;
    return temp;
}

void Polynomial::RetNode(Node* p) {
    p->link = available;
    available = p;
}

Polynomial::Polynomial() {
    header = new Node;
    header->link = header;
}

Polynomial::~Polynomial() {
    Node* current = header->link;
    while (current != header) {
        Node* prev = current;
        current = current->link;
        RetNode(prev);
    }
    delete header;
}

void Polynomial::AppendTerm(const double& coef, const int& exp) {
    Node* newNode = GetNode();
    newNode->coef = coef;
    newNode->exp = exp;
    if (header->link == header || exp > header->link->exp) {
        newNode->link = header->link;
        header->link = newNode;
    } else {
        Node* prev = header;
        Node* current = header->link;
        while (current != header && exp < current->exp) {
            prev = current;
            current = current->link;
        }
        if (current != header && exp == current->exp) {
            current->coef += coef;
            if (current->coef == 0.0) {
                prev->link = current->link;
                RetNode(current);
            }
        } else {
            newNode->link = current;
            prev->link = newNode;
        }
    }
}

Polynomial::Polynomial(const Polynomial& a) {
    header = new Node;
    header->link = header;
    Node* current = a.header->link;
    while (current != a.header) {
        AppendTerm(current->coef, current->exp);
        current = current->link;
    }
}

const Polynomial& Polynomial::operator=(const Polynomial& a) {
    if (this == &a) {
        return *this;
    }
    Node* current = header->link;
    while (current != header) {
        Node* prev = current;
        current = current->link;
        RetNode(prev);
    }
    current = a.header->link;
    while (current != a.header) {
        AppendTerm(current->coef, current->exp);
        current = current->link;
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& b) const {
    Polynomial result;
    Node* currentA = header->link;
    Node* currentB = b.header->link;
    while (currentA != header && currentB != b.header) {
        if (currentA->exp > currentB->exp) {
            result.AppendTerm(currentA->coef, currentA->exp);
            currentA = currentA->link;
        } else if (currentA->exp < currentB->exp) {
            result.AppendTerm(currentB->coef, currentB->exp);
            currentB = currentB->link;
        } else {
            double sum = currentA->coef + currentB->coef;
            if (sum != 0.0) {
                result.AppendTerm(sum, currentA->exp);
            }
            currentA = currentA->link;
            currentB = currentB->link;
        }
    }
    while (currentA != header) {
        result.AppendTerm(currentA->coef, currentA->exp);
        currentA = currentA->link;
    }
    while (currentB != b.header) {
        result.AppendTerm(currentB->coef, currentB->exp);
        currentB = currentB->link;
    }
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& b) const {
    Polynomial result;
    Node* currentA = header->link;
    Node* currentB = b.header->link;
    while (currentA != header && currentB != b.header) {
        if (currentA->exp > currentB->exp) {
            result.AppendTerm(currentA->coef, currentA->exp);
            currentA = currentA->link;
        } else if (currentA->exp < currentB->exp) {
            result.AppendTerm(-currentB->coef, currentB->exp);
            currentB = currentB->link;
        } else {
            double diff = currentA->coef - currentB->coef;
            if (diff != 0.0) {
                result.AppendTerm(diff, currentA->exp);
            }
            currentA = currentA->link;
            currentB = currentB->link;
        }
    }
    while (currentA != header) {
        result.AppendTerm(currentA->coef, currentA->exp);
        currentA = currentA->link;
    }
    while (currentB != b.header) {
        result.AppendTerm(-currentB->coef, currentB->exp);
        currentB = currentB->link;
    }
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& b) const {
    Polynomial result;
    Node* currentA = header->link;
    while (currentA != header) {
        Node* currentB = b.header->link;
        while (currentB != b.header) {
            double coef = currentA->coef * currentB->coef;
            int exp = currentA->exp + currentB->exp;
            result.AppendTerm(coef, exp);
            currentB = currentB->link;
        }
        currentA = currentA->link;
    }
    return result;
}

double Polynomial::Evaluate(double x) const {
    double result = 0.0;
    Node* current = header->link;
    while (current != header) {
        double term = current->coef * pow(x, current->exp);
        result += term;
        current = current->link;
    }

    return result;
}

istream& operator>>(istream& is, Polynomial& x) {
    int n;
    is >> n;
    double coef;
    int exp;
    for (int i = 0; i < n; i++) {
        is >> coef >> exp;
        x.AppendTerm(coef, exp);
    }
    return is;
}

ostream& operator<<(ostream& os, const Polynomial& x) {
    Node* current = x.header->link;
    int count = 0;
    while (current != x.header) {
        if (count > 0) {
            os << " ";
        }
        os << current->coef << " " << current->exp;
        current = current->link;
        count++;
    }
    return os;
}