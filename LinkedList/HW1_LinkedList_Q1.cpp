#include <iostream>
#include "CircularList.h"
#include "CircularList.cpp"
using namespace std;

int main()
{
    CircularList<int> list1;
    list1.InsertFront(5);
    list1.InsertFront(4);
    list1.InsertFront(3);
    list1.InsertFront(2);
    list1.InsertFront(1);
    cout << "list1(use first pointer) = " << list1 << endl << endl;
    cout << "(a) list1.Size() = " << list1.Size() << endl << endl;
    list1.InsertFront(6);
    cout << "(b) list1.InsertFront(6)" << endl;
    cout << "list1 = " << list1 << endl << endl;
    list1.InsertBack(7);
    cout << "(c) list1.InsertBack(7)" << endl;
    cout << "list1 = " << list1 << endl << endl;
    list1.DeleteFirst();
    cout << "(d) list1.DeleteFirst()" << endl;
    cout << "list1 = " << list1 << endl << endl;
    list1.DeleteBack();
    cout << "(e) list1.DeleteBack()" << endl;
    cout << "list1 = " << list1 << endl << endl;
    list1.DeleteOddNode();
    cout << "(f) list1.DeleteOddNode()" << endl;
    cout << "list1 = " << list1 << endl << endl;
    list1.InsertFront(5);
    list1.InsertFront(4);
    list1.InsertFront(-3);
    list1.InsertFront(2);
    list1.InsertFront(1);
    cout << "list1 = " << list1 << endl;
    Node<int> *split1 = list1.IndexPointer(3);
    cout << "split1 points to the node with index 3 in list1" << endl;
    CircularList<int> list2, list3;
    list1.Deconcatenate(split1, list2, list3);
    cout << "(g) list1.Deconcatenate(split1, list2, list3)" << endl;
    cout << "list1 = " << list1 << endl;
    cout << "list2 = " << list2 << endl;
    cout << "list3 = " << list3 << endl << endl;
    list1 = list2.Merge(list3);
    cout << "(h) list1 = list2.Merge(list3)" << endl;
    cout << "list1 = " << list1 << endl << endl;

    CircularHeaderList<int> list4;
    list4.InsertFront(1);
    list4.InsertFront(2);
    list4.InsertFront(3);
    list4.InsertFront(4);
    list4.InsertFront(5);
    cout << "list4(use head node) = " << list4 << endl << endl;
    cout << "(i-a) list4.Size() = " << list4.Size() << endl << endl;
    list4.InsertFront(6);
    cout << "(i-b) list4.InsertFront(6)" << endl;
    cout << "list4 = " << list4 << endl << endl;
    list4.InsertBack(7);
    cout << "(i-c) list4.InsertBack(7)" << endl;
    cout << "list4 = " << list4 << endl << endl;
    list4.DeleteFirst();
    cout << "(i-d) list4.DeleteFirst()" << endl;
    cout << "list4 = " << list4 << endl << endl;
    list4.DeleteBack();
    cout << "(i-e) list4.DeleteBack()" << endl;
    cout << "list4 = " << list4 << endl << endl;
    list4.DeleteOddNode();
    cout << "(i-f) list4.DeleteOddNode()" << endl;
    cout << "list4 = " << list4 << endl << endl;
    list4.InsertFront(5);
    list4.InsertFront(4);
    list4.InsertFront(-3);
    list4.InsertFront(2);
    list4.InsertFront(1);
    cout << "list4 = " << list4 << endl;
    Node<int> *split2 = list4.IndexPointer(3);
    cout << "split2 points to the node with index 3 in list4" << endl;
    CircularHeaderList<int> list5, list6;
    list4.Deconcatenate(split2, list5, list6);
    cout << "(i-g) list4.Deconcatenate(split2, list5, list6)" << endl;
    cout << "list4 = " << list4 << endl;
    cout << "list5 = " << list5 << endl;
    cout << "list6 = " << list6 << endl << endl;
    list4 = list5.Merge(list6);
    cout << "(i-h) list4 = list5.Merge(list6)" << endl;
    cout << "list4 = " << list4 << endl << endl;

    return 0;
}