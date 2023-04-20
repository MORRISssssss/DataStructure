#include <iostream>
#include "Inheritance.h"
using namespace std;

template <class T>
Bag<T>::Bag(int bagCapacity): capacity(bagCapacity) 
{
    if (capacity < 1) 
        throw "Capacity must be > 0";
    array = new T[capacity]; // use array to implement 
    top = -1; // empty 
}

template <class T>
Bag<T>::~Bag() 
{ 
    delete [] array; 
}

template <class T>
inline int Bag<T>::Size() const
{ 
    return top + 1; 
}

template<class T>
bool Bag<T>::IsEmpty() const
{
    return (Size() == 0);
}

template <class T>
inline T& Bag<T>::Element() const
{
    if (IsEmpty()) 
        throw "Bag is empty";
    return array[0];
}

template <class T>
void Bag<T>::ChangeCapacity(int newCapacity)
{
    if (newCapacity < capacity) 
        throw "The new capacity cannot be less than the origin one.";
    T* newArray = new T[newCapacity];
    int start = (front + 1) % capacity;
    copy(array, array + Size(), newArray);
    delete [] array;
    array = newArray; 
    capacity = newCapacity;
}

template <class T>
void Bag<T>::Push(const T& item) 
{
    if (capacity == top + 1)
        ChangeCapacity(2 * capacity);
    array[++top] = x;
}

template <class T>
void Bag<T>::Pop()
{
    if (IsEmpty()) 
        throw "Bag is empty, cannot delete";
    int deletePos = top / 2;
    copy(array + deletePos + 1, array + top + 1, array + deletePos);
    array[top--].~T();
}

template <class T>
Stack<T>::Stack(int stackCapacity)
:Bag(stackCapacity)
{
}

template <class T>
Stack<T>::~Stack() 
{
}

template <class T>
T& Stack<T>::Top() const
{
    if (IsEmpty()) 
        throw "Stack is empty.";
    return array[top];
}

template <class T>
void Stack<T>::Pop()
{
    if (IsEmpty()) 
        throw "Stack is empty. Cannot delete.";
    array[top--].~T();
}

template <class T>
Queue<T>::Queue(int queueCapacity)
:Bag(queueCapacity)
{ 
    front = rear = 0;
}

template <class T>
Queue<T>::~Queue()
{ 
}

template <class T>
inline bool Queue<T>::IsEmpty() const
{
    return front == rear;
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
void Queue<T>::Push(const T& item) 
{
    if ((rear + 1) % capacity == front)
        ChangeCapacity(2 * capacity);
    rear = (rear + 1) % capacity; 
    array[rear] = item;
}

template <class T>
void Queue<T>::Pop()
{
    if (IsEmpty()) 
        throw "Queue is empty, cannot delete";
    front = (front + 1) % capacity;
    array[front].~T();
}

template <class T>
inline T& Queue<T>::Front() const
{
    if (IsEmpty()) 
        throw "Queue is empty. No front element.";
    return array[(front + 1) % capacity]; //front unchanged
}

template <class T>
inline T& Queue<T>::Rear() const
{
    if (IsEmpty()) 
        throw "Queue is empty. No rear element.";
    return array[rear];
}

template <class T>
Deque<T>::Deque(int dequeCapacity)
:Queue(dequeCapacity)
{
}

template <class T>
Deque<T>::~Deque()
{
}

template <class T>
void Deque<T>::PushFront(const T &item)
{
    if ((front - 1) % capacity == rear)
        ChangeCapacity(2 * capacity);
    front = (front - 1) % capacity; 
    array[front - 1] = item;
}

template <class T>
void Deque<T>::PushRear(const T &item)
{
    if ((rear + 1) % capacity == front)
        ChangeCapacity(2 * capacity);
    rear = (rear + 1) % capacity; 
    array[rear] = item;
}

template <class T>
void Deque<T>::PopFront()
{
    if (IsEmpty()) 
        throw "Queue is empty, cannot delete";
    front = (front + 1) % capacity;
    queue[front].~T();
}

template <class T>
void Deque<T>::PopRear()
{
    if (IsEmpty()) 
        throw "Queue is empty, cannot delete";
    rear = (rear - 1) % capacity;
    queue[rear + 1].~T();
}
