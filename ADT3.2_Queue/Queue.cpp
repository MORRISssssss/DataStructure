#include <iostream>
#include <stack>
#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity)
{ 
    if (capacity < 1) throw "Queue capacity must be > 0";
    queue = new T[capacity];
    front = rear = 0; // indicate empty queue
}

template <class T>
Queue<T>::~Queue()
{ 
    delete [] queue;
}

template <class T>
inline bool Queue<T>::IsEmpty() const
{
    return front == rear;
}

template <class T>
inline T& Queue<T>::Front() const
{
    if (IsEmpty()) throw "Queue is empty. No front element.";
    return queue[(front + 1) % capacity]; //front unchanged
}

template <class T>
inline T& Queue<T>::Rear() const
{
    if (IsEmpty()) throw "Queue is empty. No rear element.";
    return queue[rear];
}

template <class T>
void Queue<T>::ChangeCapacity(int newCapacity)
{
    if (newCapacity < capacity) throw "The new capacity cannot be less than the origin one.";
    T* newQu = new T[newCapacity];
    int start = (front + 1) % capacity;
    if(start < 2)
        copy(queue + start, queue + start + capacity - 1, newQu);
    else{
        copy(queue + start, queue + capacity, newQu);
        copy(queue, queue + rear + 1,newQu + capacity - start);
    }
    front = newCapacity - 1;
    rear = capacity - 2;
    delete[] queue;
    queue = newQu; 
    capacity = newCapacity;
}

template <class T>
void Queue<T>::Push(const T& x) 
{// add x to queue
    if ((rear + 1) % capacity == front) //resize
        ChangeCapacity(2 * capacity);
    rear = (rear + 1) % capacity; 
    queue[rear] = x;
}

template <class T>
void Queue<T>::Pop( )
{
    if (IsEmpty()) throw "Queue is empty, cannot delete";
    front = (front + 1) % capacity;
    queue[front].~T(); // destructor for T
}

template <class T>
inline int Queue<T>::Size() const
{
    if (rear < front)
        return rear + capacity - front;
    else 
        return rear - front;
}

template <class T>
inline int Queue<T>::Capacity() const
{
    return capacity;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)
{
    T* newQu = new T[q.capacity];
    copy(q.queue, q.queue + q.capacity, newQu);
    front = q.front;
    rear = q.rear;
    delete [] queue;
    queue = newQu; 
    capacity = q.capacity;
    return *this;
}

template <class T>
Queue<T> Queue<T>::Merge(const Queue<T>& q) const
{
    Queue<T> mergeQu(5), q1(5), q2(5);
    q1 = *this;
    q2 = q;
    while (!q1.IsEmpty() && !q2.IsEmpty()){
        mergeQu.Push(q1.Front());
        q1.Pop();
        mergeQu.Push(q2.Front());
        q2.Pop();
    }
    while (!q1.IsEmpty()){
        mergeQu.Push(q1.Front());
        q1.Pop();
    }
    while (!q2.IsEmpty()){
        mergeQu.Push(q2.Front());
        q2.Pop();
    }
    return mergeQu;
}

template <class T>
Queue<T> Queue<T>::ReverseQueue()
{
    stack<T> s;
    Queue<T> q(5);
    q = *this;
    while (!q.IsEmpty()){
        s.push(q.Front());
        q.Pop();
    }
    while (!s.empty()){
        q.Push(s.top());
        s.pop();
    }
    return q;
}

template <class T>
ostream &operator<< (ostream &os, const Queue<T> &t)
{
    Queue<T> q(5);
    q = t;
    os << "(";
    if (!q.IsEmpty()){
        os << q.Front();
        q.Pop();
    }
    while (!q.IsEmpty()){
        os << ", " << q.Front();
        q.Pop();
    }
    os << ")";
    return os;
}