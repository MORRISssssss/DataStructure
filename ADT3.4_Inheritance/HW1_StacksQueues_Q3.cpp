#include <iostream>
#include "Inheritance.h"
#include "Inheritance.cpp"
using namespace std;

int main()
{
    Stack<int> intStack;
    intStack.Push(1);
    cout << "intStack.Push(1);" << endl;
    cout << "intStack = " << intStack << endl;
    cout << "intStack.Size() = " << intStack.Size() << endl;
    intStack.Push(2);
    cout << "intStack.Push(2);" << endl;
    cout << "intStack = " << intStack << endl;
    cout << "intStack.Size() = " << intStack.Size() << endl;
    intStack.Push(3);
    cout << "intStack.Push(3);" << endl;
    cout << "intStack = " << intStack << endl;
    cout << "intStack.Size() = " << intStack.Size() << endl;
    intStack.Pop();
    cout << "intStack.Pop();" << endl;
    cout << "intStack = " << intStack << endl;
    cout << "intStack.Size() = " << intStack.Size() << endl;
    intStack.Pop();
    cout << "intStack.Pop();" << endl;
    cout << "intStack = " << intStack << endl;
    cout << "intStack.Size() = " << intStack.Size() << endl;
    return 0;
}