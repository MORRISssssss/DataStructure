#include <iostream>
using namespace std;

template <class T>
void InsertionSort(T *a, const int n);
template <class T>
void QuickSort(T *a, const int left, const int right);
template <class T>
void IterMergeSort(T *a, const int n);
template <class T>
void MergePass(T *a, T *b, const int n, const int s);
template <class T>
void Merge(T *a, T *b, const int k, const int m, const int n);
template <class T>
void RecurMergeSort(T *a, int low, int high);
template <class T>
void ListMerge(T *a, int low, int high, int mid);
template <class T>
void HeapSort(T *a, const int n);
template <class T>
void Adjust(T *a, const int root, const int n);

template <class T>
void InsertionSort(T *a, const int n)
{
    for(int i = 1,j; i < n; i++){
        T temp = a[i];
        for (j = i; j > 0 && temp < a[j-1]; j--)
            a[j] = a[j-1];
        a[j] = temp;
    }
}

template <class T>
void QuickSort(T *a, const int left, const int right)
{ // sort a[left:right] into nondecreasing, a[left] as pivot
    if (left < right) {
        T & pivot = a[left];
        int i = left;
        int j = right + 1;
        do {
            do j--; while (a[j] > pivot); //find a key ≤pivot
            do i++; while (a[i] <= pivot); //find a key >pivot
            if (i < j) swap(a[i], a[j]);
        } while (i < j);
        swap(pivot, a[j]); //place the pivot between 2 lists
        QuickSort(a, left, j - 1); // recursion
        QuickSort(a, j + 1, right); // recursion
    }
}

template <class T>
void IterMergeSort(T *a, const int n)
{ // sort a[1:n] into non-decreasing order
    T *tempList = new T[n + 1];
    // l is the length of the currently merged sublist
    for (int l = 1; l < n; l *= 2){
        MergePass(a, tempList, n, l);
        l *= 2;
        MergePass(tempList, a, n, l); 
    }
    delete [] tempList;
}

template <class T>
void MergePass(T *initList, T *resultList, const int n, const int s)
{//adjacent pairs of sublist of size s are merged from a to b. n = # records in a
    int i;
    for (i = 1; //i the first position in first of the sublists merged
    i <= n - (2 * s) + 1; //enough elements for 2 sublists of length s?
    i += 2 * s) {
        Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
    }
    // merge remaining lists of size < 2*s
    if ((i + s - 1) < n) //one full and one partial lists
        Merge(initList, resultList, i, i + s - 1, n);
    else //only one partial lists remained
        copy(initList + i, initList + n + 1, resultList + i);
}

template <class T>
void Merge(T *a, T *b, const int k, const int m, const int n)
{ // a[k:m], a[m+1:n] are sorted, merged to b[k:n]
    int i1, i2, i3;
    for (i1 = k, i2 = m + 1, i3 = k; 
        i1 <= m && i2 <= n; i3++) {
        if (a[i1] <= a[i2]) {
            b[i3] = a[i1];
            i1++;
        } else {
            b [i3] = a [i2];
            i2++;
        }
    }
    // copy remaining records, if any, of 1st sublist
    copy(a + i1, a + m + 1, b + i3);
    // copy remaining records, if any, of 2nd sublist
    copy(a + i2, a + n + 1, b + i3);
}

template <class T>
void RecurMergeSort(T *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		RecurMergeSort(a, low, mid);
		RecurMergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		ListMerge(a, low, high, mid);
	}
}

template <class T>
void ListMerge(T *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k;
    T temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

template <class T>
void HeapSort(T *a, const int n)
{// sort a[1..n] into non-decreasing order
// a[n/2] is the parent of the last node, a[n]
    for (int i = n/2; i >= 1; i--) // buttom-up heapification
        Adjust(a, i, n);// make the tree rooted at i be a max heap
    for (int i = n-1; i >= 1; i--) {
        swap(a[1], a[i+1]); // move one record from heap to list
        Adjust(a, 1, i); // heapify
    }
}

template <class T>
void Adjust(T *a, const int root, const int n)
{
// two subtrees are max heaps already
// same procedure as the trickling-down procedure
    T e = a[root];
    //2*root is root's left child
    int j;
    for (j = 2*root; j <= n; j *=2) {
        if (j < n && a[j] < a[j+1]) // j and j+1 are siblings
            j++; // make j be the max child
        if (e >= a[j]) 
            break; 
        a[j / 2] = a[j]; // move jth record up the path
    }
    a[j / 2] = e;
}
