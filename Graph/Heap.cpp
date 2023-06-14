#include "Heap.h"

template <class T>
MaxHeap<T>::MaxHeap(int theCapacity) // constructor
{
    if(theCapacity < 1) 
        throw "Capacity must be >= 1";
    capacity = theCapacity;
    heapSize = 0; 
    heap = new T [capacity + 1]; // heap[0] unused
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
    delete [] heap;
    heapSize = 0;
    capacity = 0;
}

template <class T>
bool MaxHeap<T>::IsEmpty() const
{
    return !heapSize;
}

template <class T>
const T& MaxHeap<T>::Top() const
{
    if (IsEmpty())
        throw "Heap is empty.";
    return heap[1];
}

template <class T>
void MaxHeap<T>::Push(const T& e)
{ // add element e to max heap
    if (heapSize == capacity) // double the capacity
        ChangeCapacity(2 * capacity);
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < e) { // bubbling up
        heap[currentNode] = heap[currentNode / 2];//move parent down
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template <class T>
void MaxHeap<T>::Pop()
{
    // Delete max element
    if (IsEmpty ()) 
        throw "Heap is empty. Cannot delete.";
    heap[1].~T(); // delete max element
    T lastE = heap[heapSize--]; // remove last element from heap
    // trickle down to find a position to place the last element
    int currentNode = 1; // root
    int child = 2; // a child of current node
    while (child <= heapSize){
    // set child to larger child of currentNode
        if (child < heapSize && heap[child] < heap[child + 1]) 
            child++;
        if (lastE >= heap[child]) 
            break; 
        heap[currentNode] = heap[child]; // move child up
        currentNode = child; 
        child *= 2; // move down a level
    }
    heap[currentNode] = lastE;
}

template <class T>
void MaxHeap<T>::BottomUpConstruct(const T *array, const int size)
{
    delete [] heap;
    heap = new T[size + 1];
    copy(array, array + size, heap + 1);
    capacity = size;
    heapSize = size;
    for (int i = heapSize / 2; i > 0; i--){
        int currentNode = i;
        int child = 2 * currentNode;
        while (child <= heapSize){
            if (child < heapSize && heap[child] < heap[child + 1]) 
                child++;
            if (heap[currentNode] < heap[child]){
                swap(heap[currentNode], heap[child]);
                currentNode = child;
                child = 2 * currentNode;
            }else{
                break;
            }
        }
    }
}

template <class T>
void MaxHeap<T>::ChangeCapacity(const int newCapacity)
{
    if (newCapacity < capacity) 
        throw "The new capacity cannot be less than the origin one.";
    T* newHeap = new T[newCapacity + 1];
    copy(heap, heap + heapSize + 1, newHeap);
    delete [] heap;
    heap = newHeap; 
    capacity = newCapacity;
}

template <class T>
ostream &operator<<(ostream &os, const MaxHeap<T> &rhs)
{
        for (int i = 1; i <= rhs.heapSize; i++)
            os << rhs.heap[i] << " ";
        return os;
}

template <class T>
MinHeap<T>::MinHeap(int theCapacity) // constructor
{
    if(theCapacity < 1) 
        throw "Capacity must be >= 1";
    capacity = theCapacity;
    heapSize = 0; 
    heap = new T [capacity + 1]; // heap[0] unused
}

template <class T>
MinHeap<T>::~MinHeap()
{
    delete [] heap;
    heapSize = 0;
    capacity = 0;
}

template <class T>
bool MinHeap<T>::IsEmpty() const
{
    return !heapSize;
}

template <class T>
const T& MinHeap<T>::Top() const
{
    if (IsEmpty())
        throw "Heap is empty.";
    return heap[1];
}

template <class T>
void MinHeap<T>::Push(const T& e)
{ // add element e to max heap
    if (heapSize == capacity) // double the capacity
        ChangeCapacity(2 * capacity);
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] > e) { // bubbling up
        heap[currentNode] = heap[currentNode / 2];//move parent down
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template <class T>
void MinHeap<T>::Pop()
{
    // Delete max element
    if (IsEmpty ()) 
        throw "Heap is empty. Cannot delete.";
    heap[1].~T(); // delete max element
    T lastE = heap[heapSize--]; // remove last element from heap
    // trickle down to find a position to place the last element
    int currentNode = 1; // root
    int child = 2; // a child of current node
    while (child <= heapSize){
    // set child to larger child of currentNode
        if (child < heapSize && heap[child] > heap[child + 1]) 
            child++;
        if (lastE <= heap[child]) 
            break; 
        heap[currentNode] = heap[child]; // move child up
        currentNode = child; 
        child *= 2; // move down a level
    }
    heap[currentNode] = lastE;
}

template <class T>
void MinHeap<T>::BottomUpConstruct(const T *array, const int size)
{
    delete [] heap;
    heap = new T[size + 1];
    copy(array, array + size, heap + 1);
    capacity = size;
    heapSize = size;
    for (int i = heapSize / 2; i > 0; i--){
        int currentNode = i;
        int child = 2 * currentNode;
        while (child <= heapSize){
            if (child < heapSize && heap[child] > heap[child + 1]) 
                child++;
            if (heap[currentNode] > heap[child]){
                swap(heap[currentNode], heap[child]);
                currentNode = child;
                child = 2 * currentNode;
            }else{
                break;
            }
        }
    }
}

template <class T>
void MinHeap<T>::ChangeCapacity(const int newCapacity)
{
    if (newCapacity < capacity) 
        throw "The new capacity cannot be less than the origin one.";
    T* newHeap = new T[newCapacity + 1];
    copy(heap, heap + heapSize + 1, newHeap);
    delete [] heap;
    heap = newHeap; 
    capacity = newCapacity;
}

template <class T>
ostream &operator<<(ostream &os, const MinHeap<T> &rhs)
{
        for (int i = 1; i <= rhs.heapSize; i++)
            os << rhs.heap[i] << " ";
        return os;
}