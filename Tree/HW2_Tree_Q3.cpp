#include "Heap.cpp"

int main()
{
    int array[13] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};
    
    MaxHeap<int> Max1;
    cout << "MaxHeap1 constructed with Push(): " << endl;
    for (int i = 0; i < 13; i++)
        Max1.Push(array[i]);
    cout << Max1 << endl;

    MaxHeap<int> Max2;
    cout << "MaxHeap2 constructed by bottom up initialization: " << endl;
    Max2.BottomUpConstruct(array, 13);
    cout << Max2 << endl;

    cout << "MaxHeap1: Top() = " << Max1.Top() << endl;
    cout << "MaxHeap1: Pop():"<< endl;
    Max1.Pop();
    cout << Max1 << endl;

    MinHeap<int> Min1;
    cout << "MinHeap1 constructed with Push(): " << endl;
    for (int i = 0; i < 13; i++)
        Min1.Push(array[i]);
    cout << Min1 << endl;

    MinHeap<int> Min2;
    cout << "MinHeap2 constructed by bottom up initialization: " << endl;
    Min2.BottomUpConstruct(array, 13);
    cout << Min2 << endl;

    cout << "MinHeap1: Top() = " << Min1.Top() << endl;
    cout << "MinHeap1: Pop():"<< endl;
    Min1.Pop();
    cout << Min1 << endl;

    return 0;
}