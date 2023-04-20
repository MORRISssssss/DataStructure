#include <iostream>
using namespace std;
#ifndef INHERITANCE_H
#define INHERITANCE_H

template <class T>
class Bag
{ 
    public:
        Bag (int bagCapacity = 10);
        virtual ~Bag();
        virtual int Size() const;
        virtual bool IsEmpty() const;
        virtual T& Element() const;
        virtual void Push(const T& item);
        virtual void Pop();
    protected:
        T* array;
        int top, capacity;
        void ChangeCapacity(int newCapacity);
};

template <class T>
class Stack: public Bag
{
    public:
        Stack (int stackCapacity = 10);
        ~Stack();
        T& Top() const;
        void Pop();
};

template <class T>
class Queue: public Bag
{ 
    public:
        Queue(int queueCapacity = 10);
        virtual ~Queue();
        virtual bool IsEmpty() const;
        virtual int Size() const;
        void Push(const T& item);    
        void Pop();
        virtual T& Front() const;    
        virtual T& Rear() const;
    protected:
        int front, rear;
        virtual void ChangeCapacity(int newCapacity);
};

template <class T>
class Deque: public Queue
{
    Deque(int dequeCapacity = 10);
    ~Deque();
    void PushFront(const T& item);
    void PushRear(const T& item);
    void PopFront();
    void PopRear();
};

#endif