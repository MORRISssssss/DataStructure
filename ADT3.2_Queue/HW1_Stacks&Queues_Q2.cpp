#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;


int main()
{
    Queue<int> q(5);
    q.Push(0);
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    cout << "q = " << q << endl;
    cout << "q.ReverseQueue() = " << q.ReverseQueue() << endl;
    return 0;
}