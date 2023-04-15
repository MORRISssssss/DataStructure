#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

int main()
{
    Queue<int> q1(5), q2(5);
    cout << "q1 = (), q2 = ()" << endl;
    cout << "q1.Push(1);" << endl;
    q1.Push(1);
    cout << "q1.Push(2);" << endl;
    q1.Push(2);
    cout << "q1.Push(3);" << endl;
    q1.Push(3);
    cout << "q1.Pop();" << endl;
    q1.Pop();
    cout << "q1.Pop();" << endl;
    q1.Pop();
    cout << "q1.Push(4);" << endl;
    q1.Push(4);
    cout << "q1.Push(5);" << endl;
    q1.Push(5);
    cout << "q1 = " << q1 << endl;
    cout << "q1.Front() = " << q1.Front() << endl;
    cout << "q1.Rear() = " << q1.Rear() << endl;
    cout << "q1.Size() = " << q1.Size() << endl;
    cout << "q1.Capacity() = " << q1.Capacity() << endl;
    for (int i = 99; i > 94; i--)
        q2.Push(i);
    cout << "q2 = " << q2 << endl;
    cout << "q1.Merge(q2) = " << q1.Merge(q2) << endl;
    return 0;
}