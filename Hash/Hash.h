#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cstring>

class LinearProbing{
    public:
        LinearProbing();
        ~LinearProbing() {}
        void Insert (char *str);
        bool Search (char *str);
        void Print();
    private:
        char SymbolTable[26][100];
};

struct Link {
    char item[100];
    Link *next;
};

class ChainList{
    public:
        ChainList();
        ~ChainList() {}
        void Insert (char *str);
        bool Search (char *str);
        void Print();
    private:
        Link *SymbolTable[26];
};

#endif