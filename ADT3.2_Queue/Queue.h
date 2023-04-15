#include <iostream>
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H

template <class T> class Queue;
template <class T>
ostream& operator<< (ostream& os, const Queue<T>& t);

template <class T>
class Queue
{ 
    public:
        Queue(int queueCapacity = 0);
        ~Queue();
        bool IsEmpty() const;
        // add an item into the queue
        void Push(const T& item);    
        // delete an item 
        void Pop();    
        // return top element of queue
        T& Front() const;    
        // return top element of queue
        T& Rear() const;    
        // return the size of queue
        int Size() const;
        // return the capacity of queue
        int Capacity() const;
        Queue<T>& operator=(const Queue<T>& q);
        // merge two queue into one
        Queue<T> Merge(const Queue<T>& q) const;
        friend ostream& operator<< <>(ostream& os, const Queue<T>& t);
    private:
        T* queue;
        int front, rear, capacity;
        void ChangeCapacity(int newCapacity);
};

#endif