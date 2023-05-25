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
    intStack.Pop();
    cout << "intStack.Pop();" << endl;
    cout << "intStack = " << intStack << endl;
    cout << "intStack.Size() = " << intStack.Size() << endl;
    cout << endl;

    Stack<float> floatStack;
    floatStack.Push(0.1);
    cout << "floatStack.Push(0.1);" << endl;
    cout << "floatStack = " << floatStack << endl;
    cout << "floatStack.Size() = " << floatStack.Size() << endl;
    floatStack.Push(0.2);
    cout << "floatStack.Push(0.2);" << endl;
    cout << "floatStack = " << floatStack << endl;
    cout << "floatStack.Size() = " << floatStack.Size() << endl;
    floatStack.Push(0.3);
    cout << "floatStack.Push(0.3);" << endl;
    cout << "floatStack = " << floatStack << endl;
    cout << "floatStack.Size() = " << floatStack.Size() << endl;
    floatStack.Pop();
    cout << "floatStack.Pop();" << endl;
    cout << "floatStack = " << floatStack << endl;
    cout << "floatStack.Size() = " << floatStack.Size() << endl;
    floatStack.Pop();
    cout << "floatStack.Pop();" << endl;
    cout << "floatStack = " << floatStack << endl;
    cout << "floatStack.Size() = " << floatStack.Size() << endl;
    floatStack.Pop();
    cout << "floatStack.Pop();" << endl;
    cout << "floatStack = " << floatStack << endl;
    cout << "floatStack.Size() = " << floatStack.Size() << endl;
    cout << endl;

    Queue<int> intQueue;
    intQueue.Push(1);
    cout << "intQueue.Push(1);" << endl;
    cout << "intQueue = " << intQueue << endl;
    cout << "intQueue.Size() = " << intQueue.Size() << endl;
    intQueue.Push(2);
    cout << "intQueue.Push(2);" << endl;
    cout << "intQueue = " << intQueue << endl;
    cout << "intQueue.Size() = " << intQueue.Size() << endl;
    intQueue.Push(3);
    cout << "intQueue.Push(3);" << endl;
    cout << "intQueue = " << intQueue << endl;
    cout << "intQueue.Size() = " << intQueue.Size() << endl;
    intQueue.Pop();
    cout << "intQueue.Pop();" << endl;
    cout << "intQueue = " << intQueue << endl;
    cout << "intQueue.Size() = " << intQueue.Size() << endl;
    intQueue.Pop();
    cout << "intQueue.Pop();" << endl;
    cout << "intQueue = " << intQueue << endl;
    cout << "intQueue.Size() = " << intQueue.Size() << endl;
    intQueue.Pop();
    cout << "intQueue.Pop();" << endl;
    cout << "intQueue = " << intQueue << endl;
    cout << "intQueue.Size() = " << intQueue.Size() << endl;
    cout << endl;

    Queue<float> floatQueue;
    floatQueue.Push(0.1);
    cout << "floatQueue.Push(0.1);" << endl;
    cout << "floatQueue = " << floatQueue << endl;
    cout << "floatQueue.Size() = " << floatQueue.Size() << endl;
    floatQueue.Push(0.2);
    cout << "floatQueue.Push(0.2);" << endl;
    cout << "floatQueue = " << floatQueue << endl;
    cout << "floatQueue.Size() = " << floatQueue.Size() << endl;
    floatQueue.Push(0.3);
    cout << "floatQueue.Push(0.3);" << endl;
    cout << "floatQueue = " << floatQueue << endl;
    cout << "floatQueue.Size() = " << floatQueue.Size() << endl;
    floatQueue.Pop();
    cout << "floatQueue.Pop();" << endl;
    cout << "floatQueue = " << floatQueue << endl;
    cout << "floatQueue.Size() = " << floatQueue.Size() << endl;
    floatQueue.Pop();
    cout << "floatQueue.Pop();" << endl;
    cout << "floatQueue = " << floatQueue << endl;
    cout << "floatQueue.Size() = " << floatQueue.Size() << endl;
    floatQueue.Pop();
    cout << "floatQueue.Pop();" << endl;
    cout << "floatQueue = " << floatQueue << endl;
    cout << "floatQueue.Size() = " << floatQueue.Size() << endl;
    cout << endl;

    Deque<int> intDeque;
    intDeque.PushFront(1);
    cout << "intDeque.PushFront(1);" << endl;
    cout << "intDeque = " << intDeque << endl;
    cout << "intDeque.Size() = " << intDeque.Size() << endl;
    intDeque.PushRear(2);
    cout << "intDeque.PushRear(2);" << endl;
    cout << "intDeque = " << intDeque << endl;
    cout << "intDeque.Size() = " << intDeque.Size() << endl;
    intDeque.PushFront(3);
    cout << "intDeque.PushFront(3);" << endl;
    cout << "intDeque = " << intDeque << endl;
    cout << "intDeque.Size() = " << intDeque.Size() << endl;
    intDeque.PushRear(4);
    cout << "intDeque.PushRear(4);" << endl;
    cout << "intDeque = " << intDeque << endl;
    cout << "intDeque.Size() = " << intDeque.Size() << endl;
    intDeque.PopFront();
    cout << "intDeque.PopFront();" << endl;
    cout << "intDeque = " << intDeque << endl;
    cout << "intDeque.Size() = " << intDeque.Size() << endl;
    intDeque.PopRear();
    cout << "intDeque.PopRear();" << endl;
    cout << "intDeque = " << intDeque << endl;
    cout << "intDeque.Size() = " << intDeque.Size() << endl;
    cout << endl;

    Deque<float> floatDeque;
    floatDeque.PushFront(0.1);
    cout << "floatDeque.PushFront(0.1);" << endl;
    cout << "floatDeque = " << floatDeque << endl;
    cout << "floatDeque.Size() = " << floatDeque.Size() << endl;
    floatDeque.PushRear(0.2);
    cout << "floatDeque.PushRear(0.2);" << endl;
    cout << "floatDeque = " << floatDeque << endl;
    cout << "floatDeque.Size() = " << floatDeque.Size() << endl;
    floatDeque.PushFront(0.3);
    cout << "floatDeque.PushFront(0.3);" << endl;
    cout << "floatDeque = " << floatDeque << endl;
    cout << "floatDeque.Size() = " << floatDeque.Size() << endl;
    floatDeque.PushRear(0.4);
    cout << "floatDeque.PushRear(0.4);" << endl;
    cout << "floatDeque = " << floatDeque << endl;
    cout << "floatDeque.Size() = " << floatDeque.Size() << endl;
    floatDeque.PopFront();
    cout << "floatDeque.PopFront();" << endl;
    cout << "floatDeque = " << floatDeque << endl;
    cout << "floatDeque.Size() = " << floatDeque.Size() << endl;
    floatDeque.PopRear();
    cout << "floatDeque.PopRear();" << endl;
    cout << "floatDeque = " << floatDeque << endl;
    cout << "floatDeque.Size() = " << floatDeque.Size() << endl;
    cout << endl;

    return 0;
}