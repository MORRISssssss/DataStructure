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
class Stack: public Bag<T>
{
    public:
        Stack (int stackCapacity = 10);
        ~Stack();
        T& Top() const;
        void Pop();
        Stack<T>& operator=(const Stack<T>& rhs);
        template <class U>
        friend ostream& operator<<(ostream& os, const Stack<U>& rhs);
};

template <class T>
class Queue: public Bag<T>
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
        Queue<T>& operator=(const Queue<T>& rhs);
        template <class U>
        friend ostream& operator<<(ostream& os, const Queue<U>& rhs);
    protected:
        int front, rear;
        virtual void ChangeCapacity(int newCapacity);
};

template <class T>
class Deque: public Queue<T>
{
    public:
        Deque(int dequeCapacity = 10);
        ~Deque();
        void PushFront(const T& item);
        void PushRear(const T& item);
        void PopFront();
        void PopRear();
        Deque<T>& operator=(const Deque<T>& rhs);
        template <class U>
        friend ostream& operator<<(ostream& os, const Deque<U>& rhs);
};

#endif