#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;

// Derived class for stack
template <class T>
class Stack : public List<T> {
    public:
        void Push(const T& e) {
            this->InsertFront(e);
        }

        void Pop() {
            this->DeleteFront();
        }

        T& Top() const {
            return this->Front();
        }

        bool IsEmpty() const {
            return this->first == nullptr;
        }
};

// Derived class for queue
template <class T>
class Queue : public List<T> {
    public:
        void Push(const T& e) {
            this->InsertBack(e);
        }

        void Pop() {
            this->DeleteFront();
        }

        T& Front() {
            return this->List<T>::Front();
        }

        bool IsEmpty() {
            return this->first == nullptr;
        }
};

int main() {
    List<int> myList;
    // (b)
    myList.InsertFront(1);
    myList.InsertFront(0);
    myList.InsertFront(4);
    myList.InsertBack(2);
    myList.InsertBack(3);
    myList.InsertBack(5);
    // (h)
    cout << "List: " << myList << endl;

    // (c)
    myList.DeleteFront();
    myList.DeleteBack();
    cout << "List: " << myList << endl;

    // (d)
    cout << "Front: " << myList.Front() << endl;
    cout << "Back: " << myList.Back() << endl;

    // (e)
    int i = myList.Get(2);
    cout << "The 2nd element in myList = " << i << endl;

    // (f)
    myList.Delete(2);
    cout << "List after deleting element at index 2: " << myList << endl;

    // (g)
    myList.Insert(2, 5);
    cout << "List after inserting 5 at index 2: " << myList << endl;

    // (i)
    cout << "Use iterator to print myList: ";
    for (Iterator<int> i = myList.Begin(); i != myList.End(); i++){
        int k = *i;
        cout << k << " ";
    }
    cout << endl;

    // (a)
    myList.~List();
    cout << "Delete myList by destructor: " << myList << endl;

    // (j)
    Stack<int> myStack;
    myStack.Push(10);
    myStack.Push(20);
    myStack.Push(30);

    cout << "Stack: ";
    while (!myStack.IsEmpty()) {
        cout << myStack.Top() << " ";
        myStack.Pop();
    }
    cout << endl;

    // (k)
    Queue<int> myQueue;
    myQueue.Push(100);
    myQueue.Push(200);
    myQueue.Push(300);

    cout << "Queue: ";
    while (!myQueue.IsEmpty()) {
        cout << myQueue.Front() << " ";
        myQueue.Pop();
    }
    cout << endl;

    // (l)
    myList.InsertBack(1);
    myList.InsertBack(2);
    myList.InsertBack(3);
    myList.InsertBack(4);
    myList.InsertBack(5);
    myList.InsertBack(6);
    myList.InsertBack(7);
    myList.InsertBack(8);
    myList.InsertBack(9);
    cout << "x1, x2,…, xn = " << myList << endl;

    
    int sum = 0;
    Iterator<int> x = myList.Begin();
    Iterator<int> y;
    for (int i = 1; i <= myList.Size() - 5; i++){
        y = x;
        for (int k = 0; k < 5; k++)
            y++;
        cout << "> " << *x << " * " << *y << endl;
        sum += (*x) * (*y);
        x++;
    }
    cout << "sum = " << sum << endl;

    return 0;
}