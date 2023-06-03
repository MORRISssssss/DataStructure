#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

template <class T>
class MaxPQ
{
    public:
        virtual ~MaxPQ() {}  // virtual destructor
        virtual bool IsEmpty() const = 0; //return true iff empty
        virtual const T& Top() const = 0; //return reference to the max
        virtual void Push(const T&) = 0;
        virtual void Pop() = 0;
};

template <class T>
class MaxHeap: public MaxPQ<T>
{
    template <class U>
    friend ostream& operator<<(ostream& os, const MaxHeap<U>& rhs);
    public:
        MaxHeap(int theCapacity = 10); // constructor
        ~MaxHeap();
        bool IsEmpty() const; //return true iff empty
        const T& Top() const; //return reference to the max
        void Push(const T&);
        void Pop();
        void BottomUpConstruct(const T* array, const int size);
    private:
        T* heap; // element array
        int heapSize; // number of elements in heap
        int capacity; // size of the element array
        void ChangeCapacity(const int newCapacity);
};

template <class T>
class MinPQ
{
    public:
        virtual ~MinPQ() {}  // virtual destructor
        virtual bool IsEmpty() const = 0; //return true iff empty
        virtual const T& Top() const = 0; //return reference to the max
        virtual void Push(const T&) = 0;
        virtual void Pop() = 0;
};

template <class T>
class MinHeap: public MinPQ<T>
{
    template <class U>
    friend ostream& operator<<(ostream& os, const MinHeap<U>& rhs);
    public:
        MinHeap(int theCapacity = 10); // constructor
        ~MinHeap();
        bool IsEmpty() const; //return true iff empty
        const T& Top() const; //return reference to the max
        void Push(const T&);
        void Pop();
        void BottomUpConstruct(const T* array, const int size);
    private:
        T* heap; // element array
        int heapSize; // number of elements in heap
        int capacity; // size of the element array
        void ChangeCapacity(const int newCapacity);
};

#endif

