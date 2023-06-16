#include "Sort.cpp"
#include <cstdlib>
#include <time.h>

int main()
{
    srand(time(NULL));

    char charArray[20];
    char charArray_copy[21];
    cout << "Unsorted char array:" << endl;
    for (int i = 0; i < 20; i++){
        charArray[i] = rand() % ('~' - '!' + 1) + '!';
        cout << charArray[i] << " ";
    }
    cout << endl;
    
    copy(charArray, charArray + 20, charArray_copy);
    InsertionSort(charArray_copy, 20);
    cout << "Insertion Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << charArray_copy[i] << " ";
    cout << endl;

    copy(charArray, charArray + 20, charArray_copy);
    QuickSort(charArray_copy, 0, 19);
    cout << "Quick Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << charArray_copy[i] << " ";
    cout << endl;

    copy(charArray, charArray + 20, charArray_copy + 1);
    IterMergeSort(charArray_copy, 20);
    cout << "Iterative Merge Sort:" << endl;
    for (int i = 1; i < 21; i++)
        cout << charArray_copy[i] << " ";
    cout << endl;

    copy(charArray, charArray + 20, charArray_copy);
    RecurMergeSort(charArray_copy, 0, 19);
    cout << "Recursive Merge Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << charArray_copy[i] << " ";
    cout << endl;

    copy(charArray, charArray + 20, charArray_copy + 1);
    HeapSort(charArray_copy, 20);
    cout << "Heap Sort:" << endl;
    for (int i = 1; i < 21; i++)
        cout << charArray_copy[i] << " ";
    cout << endl;

    cout << endl;
    int intArray[20];
    int intArray_copy[21];
    cout << "Unsorted int array:" << endl;
    for (int i = 0; i < 20; i++){
        intArray[i] = rand() % (1000 - -1000 + 1) + -1000;
        cout << intArray[i] << " ";
    }
    cout << endl;

    copy(intArray, intArray + 20, intArray_copy);
    InsertionSort(intArray_copy, 20);
    cout << "Insertion Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << intArray_copy[i] << " ";
    cout << endl;

    copy(intArray, intArray + 20, intArray_copy);
    QuickSort(intArray_copy, 0, 19);
    cout << "Quick Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << intArray_copy[i] << " ";
    cout << endl;

    copy(intArray, intArray + 20, intArray_copy + 1);
    IterMergeSort(intArray_copy, 20);
    cout << "Iterative Merge Sort:" << endl;
    for (int i = 1; i < 21; i++)
        cout << intArray_copy[i] << " ";
    cout << endl;

    copy(intArray, intArray + 20, intArray_copy);
    RecurMergeSort(intArray_copy, 0, 19);
    cout << "Recursive Merge Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << intArray_copy[i] << " ";
    cout << endl;

    copy(intArray, intArray + 20, intArray_copy + 1);
    HeapSort(intArray_copy, 20);
    cout << "Heap Sort:" << endl;
    for (int i = 1; i < 21; i++)
        cout << intArray_copy[i] << " ";
    cout << endl;

    cout << endl;
    float floatArray[20];
    float floatArray_copy[21];
    cout << "Unsorted float array:" << endl;
    for (int i = 0; i < 20; i++){
        floatArray[i] = (1. - 0.) * rand() / (RAND_MAX + 1.0) + 0.;
        cout << floatArray[i] << " ";
    }
    cout << endl;

    copy(floatArray, floatArray + 20, floatArray_copy);
    InsertionSort(floatArray_copy, 20);
    cout << "Insertion Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << floatArray_copy[i] << " ";
    cout << endl;

    copy(floatArray, floatArray + 20, floatArray_copy);
    QuickSort(floatArray_copy, 0, 19);
    cout << "Quick Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << floatArray_copy[i] << " ";
    cout << endl;

    copy(floatArray, floatArray + 20, floatArray_copy + 1);
    IterMergeSort(floatArray_copy, 20);
    cout << "Iterative Merge Sort:" << endl;
    for (int i = 1; i < 21; i++)
        cout << floatArray_copy[i] << " ";
    cout << endl;

    copy(floatArray, floatArray + 20, floatArray_copy);
    RecurMergeSort(floatArray_copy, 0, 19);
    cout << "Recursive Merge Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << floatArray_copy[i] << " ";
    cout << endl;

    copy(floatArray, floatArray + 20, floatArray_copy + 1);
    HeapSort(floatArray_copy, 20);
    cout << "Heap Sort:" << endl;
    for (int i = 1; i < 21; i++)
        cout << floatArray_copy[i] << " ";
    cout << endl;

    cout << endl;
    string stringArray[20] = {"Data", "structure's", "homeworks", "are", "very", "difficult", 
                              "I'll", "suggest", "my", "classmates", "to", "take", "this", "class", 
                              "Hope", "they", "can", "enjoy", "this", "class"};
    string stringArray_copy[21];
    cout << "Unsorted string array:" << endl;
    for (int i = 0; i < 20; i++){
        cout << stringArray[i] << " ";
    }
    cout << endl;

    copy(stringArray, stringArray + 20, stringArray_copy);
    InsertionSort(stringArray_copy, 20);
    cout << "Insertion Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << stringArray_copy[i] << " ";
    cout << endl;

    copy(stringArray, stringArray + 20, stringArray_copy);
    QuickSort(stringArray_copy, 0, 19);
    cout << "Quick Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << stringArray_copy[i] << " ";
    cout << endl;

    copy(stringArray, stringArray + 20, stringArray_copy + 1);
    IterMergeSort(stringArray_copy, 20);
    cout << "Iterative Merge Sort:" << endl;
    for (int i = 1; i < 21; i++)
        cout << stringArray_copy[i] << " ";
    cout << endl;

    copy(stringArray, stringArray + 20, stringArray_copy);
    RecurMergeSort(stringArray_copy, 0, 19);
    cout << "Recursive Merge Sort:" << endl;
    for (int i = 0; i < 20; i++)
        cout << stringArray_copy[i] << " ";
    cout << endl;

    copy(stringArray, stringArray + 20, stringArray_copy + 1);
    HeapSort(stringArray_copy, 20);
    cout << "Heap Sort:" << endl;
    for (int i = 1; i < 21; i++)
        cout << stringArray_copy[i] << " ";
    cout << endl;

    return 0;
}