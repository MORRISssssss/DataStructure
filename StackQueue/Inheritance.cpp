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
    array[++top] = item;
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
Stack<T>::Stack(int stackCapacity): Bag<T>(stackCapacity)
{
}

template <class T>
Stack<T>::~Stack() 
{
}

template <class T>
T& Stack<T>::Top() const
{
    if (this->IsEmpty()) 
        throw "Stack is empty.";
    return this->array[this->top];
}

template <class T>
void Stack<T>::Pop()
{
    if (this->IsEmpty()) 
        throw "Stack is empty. Cannot delete.";
    this->array[this->top--].~T();
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &rhs)
{
    T* newArray = new T[rhs.capacity];
    copy(rhs.array, rhs.array + rhs.capacity, newArray);
    this->top = rhs.top;
    this->capacity = rhs.capacity;
    delete [] this->array;
    this->array = newArray; 
    return *this;
}

template <class T>
Queue<T>::Queue(int queueCapacity)
:Bag<T>(queueCapacity)
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
        return rear + this->capacity - front;
    else 
        return rear - front;
}

template <class T>
void Queue<T>::ChangeCapacity(int newCapacity)
{
    if (newCapacity < this->capacity) 
        throw "The new capacity cannot be less than the origin one.";
    T* newQu = new T[newCapacity];
    int start = (front + 1) % this->capacity;
    if(start < 2)
        copy(this->array + start, this->array + start + this->capacity - 1, newQu);
    else{
        copy(this->array + start, this->array + this->capacity, newQu);
        copy(this->array, this->array + rear + 1, newQu + this->capacity - start);
    }
    front = newCapacity - 1;
    rear = this->capacity - 2;
    delete[] this->array;
    this->array = newQu; 
    this->capacity = newCapacity;
}

template <class T>
void Queue<T>::Push(const T& item) 
{
    if ((rear + 1) % this->capacity == front)
        ChangeCapacity(2 * this->capacity);
    rear = (rear + 1) % this->capacity; 
    this->array[rear] = item;
}

template <class T>
void Queue<T>::Pop()
{
    if (IsEmpty()) 
        throw "Queue is empty, cannot delete";
    front = (front + 1) % this->capacity;
    this->array[front].~T();
}

template <class T>
inline T& Queue<T>::Front() const
{
    if (IsEmpty()) 
        throw "Queue is empty. No front element.";
    return this->array[(front + 1) % this->capacity]; //front unchanged
}

template <class T>
inline T& Queue<T>::Rear() const
{
    if (IsEmpty()) 
        throw "Queue is empty. No rear element.";
    return this->array[rear];
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T> &rhs)
{
    T* newArray = new T[rhs.capacity];
    copy(rhs.array, rhs.array + rhs.capacity, newArray);
    front = rhs.front;
    rear = rhs.rear;
    this->capacity = rhs.capacity;
    delete [] this->array;
    this->array = newArray; 
    return *this;
}

template <class T>
Deque<T>::Deque(int dequeCapacity)
:Queue<T>(dequeCapacity)
{
}

template <class T>
Deque<T>::~Deque()
{
}

template <class T>
void Deque<T>::PushFront(const T &item)
{
    if ((this->front - 1) % this->capacity == this->rear)
        this->ChangeCapacity(2 * this->capacity);
    this->array[this->front] = item;
    this->front = ((this->front + this->capacity) - 1) % this->capacity; 
}

template <class T>
void Deque<T>::PushRear(const T &item)
{
    if ((this->rear + 1) % this->capacity == this->front)
        this->ChangeCapacity(2 * this->capacity);
    this->rear = (this->rear + 1) % this->capacity; 
    this->array[this->rear] = item;
}

template <class T>
void Deque<T>::PopFront()
{
    if (this->IsEmpty()) 
        throw "Queue is empty, cannot delete";
    this->front = (this->front + 1) % this->capacity;
    this->array[this->front].~T();
}

template <class T>
void Deque<T>::PopRear()
{
    if (this->IsEmpty()) 
        throw "Queue is empty, cannot delete";
    this->rear = ((this->rear % this->capacity) - 1) % this->capacity;
    this->array[this->rear + 1].~T();
}

template <class T>
Deque<T>& Deque<T>::operator=(const Deque<T> &rhs)
{
    T* newArray = new T[rhs.capacity];
    copy(rhs.array, rhs.array + rhs.capacity, newArray);
    this->front = rhs.front;
    this->rear = rhs.rear;
    this->capacity = rhs.capacity;
    delete [] this->array;
    this->array = newArray; 
    return *this;
}

template <class T>
ostream& operator<<(ostream& os, const Stack<T>& rhs)
{
    Stack<T> s;
    s = rhs;
    if (s.IsEmpty()){
        os << "Empty";
    }else{
        os << s.Top();
        s.Pop();
        while (!s.IsEmpty()){
            os << " " << s.Top();
            s.Pop();
        }
    }
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const Queue<T>& rhs)
{
    Queue<T> q;
    q = rhs;
    if (q.IsEmpty()){
        os << "Empty";
    }else{
        os << q.Front();
        q.Pop();
        while (!q.IsEmpty()){
            os << " " << q.Front();
            q.Pop();
        }
    }
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const Deque<T>& rhs)
{
    Deque<T> d;
    d = rhs;
    if (d.IsEmpty()){
        os << "Empty";
    }else{
        os << d.Front();
        d.PopFront();
        while (!d.IsEmpty()){
            os << " " << d.Front();
            d.PopFront();
        }
    }
    return os;
}